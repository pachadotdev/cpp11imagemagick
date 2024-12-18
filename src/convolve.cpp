/* Jeroen Ooms (2018)
 * Bindings to vectorized image manipulations.
 * See API: https://www.imagemagick.org/Magick++/STL.html
 */

#include "00_magick_types.h"

/* Morphology was added to Magick++ 6.8.8-7 on Feb 16, 2014
 * https://github.com/ImageMagick/ImageMagick/commit/018006bb3daced97350baecc5d172e6561a873cb
 */

[[cpp11::register]] XPtrImage magick_image_fx( XPtrImage input, std::string expression, cpp11::strings channel){
  XPtrImage output = copy(input);
  if(channel.size()){
    Magick::ChannelType chan = Channel(std::string(channel.at(0)).c_str());
    for(size_t i = 0; i < output->size(); i++)
      output->at(i).fx(expression, chan);
  } else {
    for(size_t i = 0; i < output->size(); i++)
      output->at(i).fx(expression);
  }
  return output;
}

[[cpp11::register]] XPtrImage magick_image_fx_sequence( XPtrImage input, const std::string expr){
#if MagickLibVersion >= 0x688
  Frame x;
  Magick::fxImages(&x, input->begin(), input->end(), expr);
  XPtrImage output = create(1);
  output->push_back(x);
  return output;
#else
  throw std::runtime_error("ImageMagick too old to support fx_sequence (requires >= 6.8.8)");
#endif
}

#if MagickLibVersion >= 0x689

Magick::KernelInfoType Kernel(const char * str){
  ssize_t val = MagickCore::ParseCommandOption(
    MagickCore::MagickKernelOptions, Magick::MagickFalse, str);
  if(val < 0)
    throw std::runtime_error(std::string("Invalid KernelType value: ") + str);
  return (Magick::KernelInfoType) val;
}

Magick::MorphologyMethod Method(const char * str){
  ssize_t val = MagickCore::ParseCommandOption(
    MagickCore::MagickMorphologyOptions, Magick::MagickFalse, str);
  if(val < 0)
    throw std::runtime_error(std::string("Invalid MorphologyMethod value: ") + str);
  return (Magick::MorphologyMethod) val;
}

[[cpp11::register]] XPtrImage magick_image_morphology( XPtrImage input, std::string method, std::string kernel, ssize_t iter,
                                   cpp11::strings opt_names, cpp11::strings opt_values){
  XPtrImage output = copy(input);
  for (int i = 0; i < opt_values.size(); i++){
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact(std::string(opt_names.at(i)), std::string(opt_values.at(i)));
  }
  for(size_t i = 0; i < output->size(); i++)
    output->at(i).morphology(Method(method.c_str()), kernel, iter);
  return output;
}

[[cpp11::register]] XPtrImage magick_image_convolve_kernel( XPtrImage input, std::string kernel, ssize_t iter,
                                 cpp11::strings scaling, cpp11::strings bias){
  XPtrImage output = copy(input);
  if(scaling.size()){
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact("convolve:scale", std::string(scaling.at(0)));
  }
  if(bias.size()){
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact("convolve:bias", std::string(bias.at(0)));
  }
  for(size_t i = 0; i < output->size(); i++)
    output->at(i).morphology(Magick::ConvolveMorphology, kernel, iter);
  return output;
}

[[cpp11::register]] XPtrImage magick_image_convolve_matrix( XPtrImage input, cpp11::doubles_matrix<> matrix, size_t iter,
                                 cpp11::strings scaling, cpp11::strings bias){
  XPtrImage output = copy(input);
  if(scaling.size()){
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact("convolve:scale", std::string(scaling.at(0)));
  }
  if(bias.size()){
    for (Iter it = output->begin(); it != output->end(); ++it)
      it->artifact("convolve:bias", std::string(bias.at(0)));
  }
  const double* matrix_data = REAL(matrix);
  for (size_t i = 0; i < output->size(); i++)
    for (size_t j = 0; j < iter; j++)
      output->at(i).convolve(matrix.nrow(), matrix_data);
  return output;
}

#else
XPtrImage magick_image_morphology( XPtrImage input, std::string method, std::string kernel, ssize_t iter,
                                   cpp11::strings opt_names, cpp11::strings opt_values){
  throw std::runtime_error("ImageMagick too old. Morphology requires at least version  6.8.8");
}

XPtrImage magick_image_convolve_kernel( XPtrImage input, std::string kernel, ssize_t iter,
                                        cpp11::strings scaling, cpp11::strings bias){
  throw std::runtime_error("ImageMagick too old. Convolve requires at least version  6.8.8");
}

XPtrImage magick_image_convolve_matrix( XPtrImage input, cpp11::doubles_matrix<> matrix, size_t iter,
                                        cpp11::strings scaling, cpp11::strings bias){
  throw std::runtime_error("ImageMagick too old. Convolve requires at least version  6.8.8");
}
#endif
