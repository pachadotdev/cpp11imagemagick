#include "00_magick_types.h"

/* Support for artifacts was added in 6.8.7: https://git.io/v7HFG
 */

Magick::Geometry apply_geom_gravity(Frame image, Magick::Geometry geom, Magick::GravityType gravity){
  MagickCore::RectangleInfo region(geom);
  region.x = geom.xOff(); //auto-constructor loses negative sign
  region.y = geom.yOff(); //https://github.com/ropensci/magick/issues/274
  MagickCore::GravityAdjustGeometry(image.columns(), image.rows(), gravity, &region);
  return region;
}

[[cpp11::register]] XPtrImage magick_image_composite( XPtrImage input, XPtrImage composite_image,
                                  const char * offset, const char * gravity,
                                  const char * composite, cpp11::strings args){
  if(composite_image->size() == 0)
    throw std::runtime_error("Invalid composite_image");
  XPtrImage output = copy(input);
  if(args.size() && std::string(args.at(0)).length()){
#if MagickLibVersion >= 0x687
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact("compose:args", std::string(args.at(0)));
#else
    Rcpp::warning("ImageMagick too old to support composite_args (requires >= 6.8.7)");
#endif
  }

  // offset can be either geometry or gravity
  for(size_t i = 0; i < output->size(); i++){
    Magick::Geometry geom = Geom(offset);
    if(geom.width() == 0)
      geom.width(composite_image->front().columns());
    if(geom.height() == 0)
      geom.height(composite_image->front().rows());
    geom = apply_geom_gravity(output->at(i), geom, Gravity(gravity));
    output->at(i).composite(composite_image->front(), geom, Composite(composite));
  }

  if(args.size() && std::string(args.at(0)).length()){
#if MagickLibVersion >= 0x687
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact("compose:args", "");
#endif
  }
  return output;
}

[[cpp11::register]] XPtrImage magick_image_border(XPtrImage input,
                                                  cpp11::strings color,
                                                  cpp11::strings geometry,
                                                  cpp11::strings composite) {
  XPtrImage output = copy(input);
  for_each(
      output->begin(), output->end(),
      Magick::composeImage(Composite(std::string(composite.at(0)).c_str())));
  if (color.size())
    for_each(output->begin(), output->end(),
             Magick::borderColorImage(Color(std::string(color.at(0)).c_str())));
  if (geometry.size())
    for_each(output->begin(), output->end(),
             Magick::borderImage(Geom(std::string(geometry.at(0)).c_str())));
  return output;
}

[[cpp11::register]] XPtrImage magick_image_frame( XPtrImage input, cpp11::strings color, cpp11::strings geometry){
  XPtrImage output = copy(input);
  if(color.size())
    for_each(output->begin(), output->end(),
             Magick::borderColorImage(std::string(color.at(0)).c_str()));
  if(geometry.size())
    for_each(output->begin(), output->end(),
             Magick::frameImage(Geom(std::string(geometry.at(0)).c_str())));
  return output;
}

[[cpp11::register]] XPtrImage magick_image_shadow_mask( XPtrImage input, const char * geomstr){
  XPtrImage output = copy(input);
#if MagickLibVersion >= 0x675
  Magick::Geometry geom = Geom(geomstr);
  const double opacity = geom.width();
  const double sigma = geom.height();
  const size_t x = geom.xOff();
  const size_t y = geom.yOff();
  for_each ( output->begin(), output->end(), Magick::shadowImage(opacity, sigma, x, y));
#else
  throw std::runtime_error("shadowImage not supported, ImageMagick too old");
#endif
  return output;
}

[[cpp11::register]] XPtrImage magick_image_shade( XPtrImage input, double azimuth = 30, double elevation = 30, bool color = false){
  XPtrImage output = copy(input);
  for_each ( output->begin(), output->end(), Magick::shadeImage(azimuth, elevation, color));
  return output;
}

// The C++ crop() API doesn't work well, see https://github.com/ImageMagick/ImageMagick/issues/1642

[[cpp11::register]] XPtrImage magick_image_crop( XPtrImage input, cpp11::strings geometry,
                             cpp11::strings gravity, bool repage){
  XPtrImage output = copy(input);
  for(size_t i = 0; i < output->size(); i++){
    Magick::Geometry region(geometry.size() ? Geom(std::string(geometry.at(0)).c_str()) : input->front().size());
    if(gravity.size())
      region = apply_geom_gravity(output->at(i), region, Gravity(std::string(gravity.at(0)).c_str()));
    if(region.percent()){
      MagickCore::ExceptionInfo *exception = MagickCore::AcquireExceptionInfo();
      MagickCore::Image *newImage = MagickCore::CropImageToTiles(output->at(i).constImage(), std::string(region).c_str(), exception);
  #if MagickLibVersion >= 0x690
      Magick::throwException(exception);
  #endif
      exception=MagickCore::DestroyExceptionInfo(exception);
      output->at(i).replaceImage(newImage);
    } else {
      output->at(i).crop(region);
    }
  }
  if(repage)
    for_each ( output->begin(), output->end(), Magick::pageImage(Magick::Geometry()));
  return output;
}

[[cpp11::register]] XPtrImage magick_image_extent(XPtrImage input,
                                                  cpp11::strings geometry,
                                                  cpp11::strings gravity,
                                                  cpp11::strings color) {
  XPtrImage output = copy(input);
  for (size_t i = 0; i < output->size(); i++) {
    output->at(i).extent(Geom(std::string(geometry.at(0)).c_str()),
                         Color(std::string(color.at(0)).c_str()),
                         Gravity(std::string(gravity.at(0)).c_str()));
  }
  return output;
}

[[cpp11::register]] cpp11::strings magick_image_artifact(XPtrImage input, std::string name){
#if MagickLibVersion >= 0x687
  cpp11::writable::strings artifacts(input->size());
  for(size_t i = 0; i < input->size(); i++){
    artifacts.at(i) = input->at(i).artifact(name);
  }
  return artifacts;
#else
  throw std::runtime_error("ImageMagick too old to support artifacts (requires >= 6.8.7)");
#endif
}
