#include "00_magick_types.h"

[[cpp11::register]] XPtrImage magick_image_scale( XPtrImage input, cpp11::strings geometry){
  XPtrImage output = copy(input);
  if(geometry.size()){
    for_each (output->begin(), output->end(), Magick::scaleImage(Geom(std::string(geometry.at(0)).c_str())));
  } else if(input->size()) {
    for_each (output->begin(), output->end(), Magick::scaleImage(input->front().size()));
  }
  return output;
}

[[cpp11::register]] XPtrImage magick_image_sample( XPtrImage input, cpp11::strings geometry){
  XPtrImage output = copy(input);
  if(geometry.size()){
    for_each (output->begin(), output->end(), Magick::sampleImage(Geom(std::string(geometry.at(0)).c_str())));
  } else if(input->size()){
    for_each (output->begin(), output->end(), Magick::sampleImage(input->front().size()));
  }
  return output;
}

[[cpp11::register]] XPtrImage magick_image_resize( XPtrImage input, cpp11::strings geometry, cpp11::strings filter){
  XPtrImage output = copy(input);
  if(filter.size())
    for_each (output->begin(), output->end(), Magick::filterTypeImage(Filter(std::string(filter.at(0)).c_str())));
  if(geometry.size()){
    for_each (output->begin(), output->end(), Magick::resizeImage(Geom(std::string(geometry.at(0)).c_str())));
  } else if(input->size()){
    for_each (output->begin(), output->end(), Magick::resizeImage(input->front().size()));
  }
  return output;
}

[[cpp11::register]] XPtrImage magick_image_rotate( XPtrImage input, double degrees){
  XPtrImage output = copy(input);
  for_each ( output->begin(), output->end(), Magick::rotateImage(degrees));
  return output;
}

[[cpp11::register]] XPtrImage magick_image_chop( XPtrImage input, const char * geometry){
  XPtrImage output = copy(input);
  for_each ( output->begin(), output->end(), Magick::chopImage(Geom(geometry)));
  return output;
}

[[cpp11::register]] XPtrImage magick_image_trim( XPtrImage input, double fuzz_percent){
  XPtrImage output = copy(input);
  double fuzz = fuzz_pct_to_abs(fuzz_percent);
  if(fuzz != 0)
    for_each ( output->begin(), output->end(), Magick::colorFuzzImage( fuzz ));
  for_each ( output->begin(), output->end(), Magick::trimImage());
  for_each ( output->begin(), output->end(), Magick::pageImage(Magick::Geometry()));
  if(fuzz != 0)
    for_each ( output->begin(), output->end(), Magick::colorFuzzImage(input->front().colorFuzz()));
  return output;
}

[[cpp11::register]] XPtrImage magick_image_flip( XPtrImage input){
  XPtrImage output = copy(input);
  for_each ( output->begin(), output->end(), Magick::flipImage());
  return output;
}

[[cpp11::register]] XPtrImage magick_image_flop( XPtrImage input){
  XPtrImage output = copy(input);
  for_each ( output->begin(), output->end(), Magick::flopImage());
  return output;
}

[[cpp11::register]] XPtrImage magick_image_shear( XPtrImage input, const char * geometry, const char * color){
  XPtrImage output = copy(input);
  Magick::Geometry geom(Geom(geometry));
  for_each ( output->begin(), output->end(), Magick::backgroundColorImage(color));
  for_each ( output->begin(), output->end(), Magick::shearImage(geom.width(), geom.height()));
  return output;
}
