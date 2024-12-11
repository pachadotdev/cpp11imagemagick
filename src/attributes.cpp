/* Jeroen Ooms (2018)
 * Bindings to vectorized image manipulations.
 * See API: https://www.imagemagick.org/Magick++/STL.html
 */

#include "00_magick_types.h"

#define Option(type, val) MagickCore::CommandOptionToMnemonic(type, val);

//Workaround for GCC-7:
// - https://github.com/ImageMagick/ImageMagick/issues/707
// - https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=871300
std::string col_to_str(Magick::Color col){
  char output[10] = "#";
  Magick::Quantum red(col.myRedQ());
  Magick::Quantum green(col.myGreenQ());
  Magick::Quantum blue(col.myBlueQ());
  Magick::Quantum alpha(col.myAlphaQ());
  snprintf(&output[1], 3, "%02x", (unsigned char) red);
  snprintf(&output[3], 3, "%02x", (unsigned char) green);
  snprintf(&output[5], 3, "%02x", (unsigned char) blue);
#if MagickLibVersion >= 0x700
  snprintf(&output[7], 3, "%02x", (unsigned char) alpha);
#else //NOTE: alpha scale is reverse on IM6
  snprintf(&output[7], 3, "%02x", 255 - (unsigned char) alpha);
#endif
  return std::string(output);
}

[[cpp11::register]] cpp11::strings magick_attr_comment( XPtrImage input, cpp11::strings set){
  if(set.size())
    for_each ( input->begin(), input->end(), Magick::commentImage(std::string(set.at(0))));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->comment());
  return out;
}

[[cpp11::register]] cpp11::logicals magick_attr_text_antialias( XPtrImage input, cpp11::logicals set){
  if(set.size())
    for_each ( input->begin(), input->end(), Magick::myAntiAliasImage(set[0]));
  cpp11::writable::logicals out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->myAntiAlias());
  return out;
}

[[cpp11::register]] cpp11::logicals magick_attr_stroke_antialias( XPtrImage input, cpp11::logicals set){
  cpp11::writable::logicals out;
  for (Iter it = input->begin(); it != input->end(); ++it){
    if(set.size())
      it->strokeAntiAlias(set[0]);
    out.push_back(it->strokeAntiAlias());
  }
  return out;
}

[[cpp11::register]] cpp11::integers magick_attr_animationdelay( XPtrImage input, cpp11::integers delay){
  if(delay.size())
    for_each ( input->begin(), input->end(), Magick::animationDelayImage(delay[0]));
  cpp11::writable::integers out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->animationDelay());
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_backgroundcolor( XPtrImage input, cpp11::strings color){
  if(color.size())
    for_each(
        input->begin(), input->end(),
        Magick::backgroundColorImage(Color(std::string(color[0]).c_str())));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(col_to_str(it->backgroundColor()));
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_boxcolor( XPtrImage input, cpp11::strings color){
  if(color.size())
    for_each ( input->begin(), input->end(), Magick::boxColorImage(Color(std::string(color[0]).c_str())));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(col_to_str(it->boxColor()));
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_fillcolor( XPtrImage input, cpp11::strings color){
  if(color.size())
    for_each ( input->begin(), input->end(), Magick::fillColorImage(Color(std::string(color[0]).c_str())));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(col_to_str(it->fillColor()));
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_font( XPtrImage input, cpp11::strings font){
  if(font.size())
    for_each ( input->begin(), input->end(), Magick::fontImage(std::string(font[0])));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->font());
  return out;
}

[[cpp11::register]] cpp11::integers magick_attr_fontsize( XPtrImage input, cpp11::integers pointsize){
  if(pointsize.size())
    for_each ( input->begin(), input->end(), Magick::fontPointsizeImage(pointsize[0]));
  cpp11::writable::integers out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->fontPointsize());
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_label( XPtrImage input, cpp11::strings label){
  if(label.size())
    for_each ( input->begin(), input->end(), Magick::labelImage(std::string(label[0])));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->label());
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_format( XPtrImage input, cpp11::strings format){
  if(format.size())
    for_each ( input->begin(), input->end(), Magick::magickImage(std::string(format[0])));
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->magick());
  return out;
}

[[cpp11::register]] cpp11::integers magick_attr_quality( XPtrImage input, cpp11::integers quality){
  if(quality.size()){
    if(quality[0] < 0 || quality[0] > 100)
      throw std::runtime_error("quality must be value between 0 and 100");
    for_each ( input->begin(), input->end(), Magick::qualityImage(quality[0]));
  }
  cpp11::writable::integers out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->quality());
  return out;
}

[[cpp11::register]] cpp11::integers magick_attr_quantize( XPtrImage input, cpp11::integers numcolors){
  if(numcolors.size())
    for_each ( input->begin(), input->end(), Magick::quantizeColorsImage(numcolors[0]));
  cpp11::writable::integers out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(it->quantizeColors());
  return out;
}

[[cpp11::register]] cpp11::strings magick_attr_density( XPtrImage input, cpp11::strings density){
  if(density.size()){
    for_each ( input->begin(), input->end(), Magick::resolutionUnitsImage(Magick::PixelsPerInchResolution));
    for_each ( input->begin(), input->end(), Magick::densityImage(Point(std::string(density[0]).c_str())));
  }
  cpp11::writable::strings out;
  for (Iter it = input->begin(); it != input->end(); ++it)
    out.push_back(std::string(it->density()));
  return out;
}

[[cpp11::register]] cpp11::list magick_image_info(XPtrImage input){
  int len = input->size();
  cpp11::writable::strings format(len);
  cpp11::writable::strings colorspace(len);
  cpp11::writable::integers width(len);
  cpp11::writable::integers height(len);
  cpp11::writable::logicals matte(len);
  cpp11::writable::integers filesize(len);
  cpp11::writable::strings density(len);
  for(int i = 0; i < len; i++){
    Frame frame = input->at(i);
    colorspace[i] = Option(MagickCore::MagickColorspaceOptions, frame.colorSpace());
    Magick::Geometry geom(frame.size());
    format[i] = std::string(frame.magick());
    width[i] = geom.width();
    height[i] = geom.height();
    matte[i] = frame.hasMatte();
    filesize[i] = frame.fileSize();
    density[i] = std::string(frame.density());
  }
  return cpp11::writable::list({
    "format"_nm = format,
    "width"_nm = width,
    "height"_nm = height,
    "colorspace"_nm = colorspace,
    "matte"_nm = matte,
    "filesize"_nm = filesize,
    "density"_nm = density
  });
}

[[cpp11::register]] cpp11::strings magick_image_as_raster(
    cpp11::raws data) {
  cpp11::integers dim = as_cpp<cpp11::integers>(data.attr("dim"));
  int w = dim[1], h = dim[2];
  static std::string sixteen("0123456789abcdef");
  cpp11::writable::strings transparent({"transparent"});

  cpp11::writable::strings out(h * w);
  auto p = data.begin();
  std::string buf("#00000000");

  for (int i = 0; i < h; i++) {
    int k = i * w;
    for (int j = 0; j < w; j++, p += 4, k++) {
      if (*(p + 3)) {
        Rbyte red = *(p + 0), green = *(p + 1), blue = *(p + 2),
              alpha = *(p + 3);

        buf[1] = sixteen[red >> 4];
        buf[2] = sixteen[red & 0x0F];
        buf[3] = sixteen[green >> 4];
        buf[4] = sixteen[green & 0x0F];
        buf[5] = sixteen[blue >> 4];
        buf[6] = sixteen[blue & 0x0F];
        buf[7] = sixteen[alpha >> 4];
        buf[8] = sixteen[alpha & 0x0F];

        out[k] = buf.c_str();
      } else {
        out[k] = transparent[0];
      }
    }
  }

  out.attr("class") = "raster";
  out.attr("dim") = dim;
  return out;
}
