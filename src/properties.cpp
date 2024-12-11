#include "00_magick_types.h"

[[cpp11::register]] cpp11::data_frame magick_image_properties( XPtrImage input){
  Frame frame = input->front();
  MagickCore::Image * image = frame.image();
  MagickCore::ResetImagePropertyIterator(image);
  const char * prop = NULL;
  std::vector<std::string> properties;
  while((prop = GetNextImageProperty(image)))
    properties.push_back(prop);
  cpp11::writable::strings names(properties.size());
  cpp11::writable::strings values(properties.size());
  for(size_t i = 0; i < properties.size(); i++){
    names.at(i) = properties.at(i);
    values.at(i) = frame.attribute(properties.at(i));
  }
  return cpp11::writable::data_frame({
    "property"_nm = properties,
    "value"_nm = values,
    "stringsAsFactors"_nm = false
  });
}
