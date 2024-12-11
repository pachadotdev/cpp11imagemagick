#include "00_magick_types.h"

[[cpp11::register]] XPtrImage magick_image_animate( XPtrImage input, cpp11::integers delay,
                                size_t iter, const char * method,
                                bool optimize){
  XPtrImage output = create();
  /* AFAICT optimizeImageLayers also coalesces the images, and the dispose method
   * is optimized, so it does not seem to make sense to call both. */
  if (optimize) {
#if MagickLibVersion >= 0x689
    optimizeImageLayers(output.get(), input->begin(), input->end());
#else
    throw std::runtime_error("Your imagemagick is too old for optimizeImageLayers");
#endif
  } else {
    for_each ( input->begin(), input->end(), Magick::gifDisposeMethodImage(Dispose(method)));
    coalesceImages( output.get(), input->begin(), input->end());
  }

  for_each ( output->begin(), output->end(), Magick::magickImage("gif"));

  if (delay.size() == 1) {
    for_each ( output->begin(), output->end(), Magick::animationDelayImage(delay[0]));
  } else {
    Image::iterator outit = output->begin();
    cpp11::r_vector<int>::const_iterator delit = delay.begin();
    while (outit != output->end()) {
      outit->animationDelay(*delit);
      ++outit;
      ++delit;
    }
  }

  for_each ( output->begin(), output->end(), Magick::animationIterationsImage(iter));
  return output;
}


[[cpp11::register]] XPtrImage magick_image_coalesce( XPtrImage input){
  XPtrImage output = create();
  // this fixes optimized gif images
  coalesceImages( output.get(), input->begin(), input->end());
  return output;
}

[[cpp11::register]] XPtrImage magick_image_morph( XPtrImage image, int frames){
  XPtrImage out = create();
  morphImages( out.get(), image->begin(), image->end(), frames);
  return out;
}

[[cpp11::register]] XPtrImage magick_image_mosaic( XPtrImage input, cpp11::strings composite){
  XPtrImage image = copy(input);
  if(composite.size()){
    for_each ( image->begin(), image->end(), Magick::commentImage("")); //required to force copy; weird bug in IM?
    for_each ( image->begin(), image->end(), Magick::composeImage(Composite(std::string(composite[0]).c_str())));
  }
  Frame frame;
  mosaicImages( &frame, image->begin(), image->end());
  frame.myRepage();
  XPtrImage out = create();
  out->push_back(frame);
  return out;
}

[[cpp11::register]] XPtrImage magick_image_flatten( XPtrImage input, cpp11::strings composite){
  Frame frame;
  XPtrImage image = copy(input);
  if(composite.size()){
    for_each ( image->begin(), image->end(), Magick::commentImage("")); //required to force copy; weird bug in IM?
    for_each ( image->begin(), image->end(), Magick::composeImage(Composite(std::string(composite[0]).c_str())));
  }
  flattenImages( &frame, image->begin(), image->end());
  frame.myRepage();
  XPtrImage out = create();
  out->push_back(frame);
  return out;
}

[[cpp11::register]] XPtrImage magick_image_average( XPtrImage image){
  Frame frame;
  averageImages( &frame, image->begin(), image->end());
  frame.myRepage();
  XPtrImage out = create();
  out->push_back(frame);
  return out;
}

[[cpp11::register]] XPtrImage magick_image_append(XPtrImage image, bool stack) {
  Frame frame;
  appendImages(&frame, image->begin(), image->end(), stack);
  frame.myRepage();
  Image *out = new Image();
  out->push_back(frame);
  XPtrImage ptr(out);
  cpp11::sexp ptr_sexp(ptr);
  ptr_sexp.attr("class") = cpp11::writable::strings({"magick-image"});
  return ptr;
}
