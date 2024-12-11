/* Jeroen Ooms (2018)
 * Bindings to vectorized image manipulations.
 * See API: https://www.imagemagick.org/Magick++/STL.html
 */

#include "00_magick_types.h"

Magick::CompressionType Compression(const char * str){
  ssize_t val = MagickCore::ParseCommandOption( MagickCore::MagickCompressOptions, Magick::MagickFalse, str);
  if(val < 0)
    throw std::runtime_error(std::string("Invalid CompressionType value: ") + str);
  return (Magick::CompressionType) val;
}

XPtrImage magick_image_bitmap(void * data, Magick::StorageType type, size_t slices, size_t width, size_t height){
  const char * format;
  switch ( slices ){ //TODO: K is blackchannel, there should be a 'graychannel' instead? (G = Green!)
    case 1 : format = "K"; break;
    case 2 : format = "KA"; break;
    case 3 : format = "RGB"; break;
    case 4 : format = "RGBA"; break;
    default: throw std::runtime_error("Invalid number of channels (must be 4 or less)");
  }
  Frame frame(width, height, format, type , data);
  if(slices == 1) //Workaround for using 'K' above
    frame.channel(Magick::BlackChannel);
  frame.magick("PNG");
  XPtrImage image = create();
  image->push_back(frame);
  return image;
}

[[cpp11::register]] XPtrImage magick_image_readbitmap_native(cpp11::integers_matrix<> x){
  cpp11::writable::integers dims = as_cpp<cpp11::integers>(x.attr("dim"));
  return magick_image_bitmap(x.data(), Magick::CharPixel, 4, dims[1], dims[0]);
}

[[cpp11::register]] XPtrImage magick_image_readbitmap_raster1(
    cpp11::strings_matrix<> x) {
  std::vector<rcolor> y(x.size());
  for (size_t i = 0; i < y.size(); i++)
    y[i] = R_GE_str2col(std::string(x[i / x.ncol()][i % x.ncol()]).c_str());
  cpp11::writable::integers dims =
      cpp11::as_cpp<cpp11::writable::integers>(x.attr("dim"));
  return magick_image_bitmap(y.data(), Magick::CharPixel, 4, dims[0], dims[1]);
}

[[cpp11::register]] XPtrImage magick_image_readbitmap_raster2(
    cpp11::strings_matrix<> x) {
  std::vector<rcolor> y(x.size());
  for (size_t i = 0; i < y.size(); i++)
    y[i] = R_GE_str2col(std::string(x[i / x.ncol()][i % x.ncol()]).c_str());
  cpp11::writable::integers dims =
      cpp11::as_cpp<cpp11::writable::integers>(x.attr("dim"));
  return magick_image_bitmap(y.data(), Magick::CharPixel, 4, dims[1], dims[0]);
}

[[cpp11::register]] XPtrImage magick_image_readbitmap_raw(cpp11::raws x){
  cpp11::writable::integers dims = as_cpp<cpp11::integers>(x.attr("dim"));
  return magick_image_bitmap(x.data(), Magick::CharPixel, dims[0], dims[1], dims[2]);
}

[[cpp11::register]] XPtrImage magick_image_readbitmap_double(cpp11::doubles x){
  cpp11::writable::integers dims = as_cpp<cpp11::integers>(x.attr("dim"));
  return magick_image_bitmap(x.data(), Magick::DoublePixel, dims[0], dims[1], dims[2]);
}

[[cpp11::register]] XPtrImage magick_image_readbin(cpp11::raws x, cpp11::strings density, cpp11::integers depth,
                               bool strip, cpp11::strings defines){
  XPtrImage image = create();
#if MagickLibVersion >= 0x689
  Magick::ReadOptions opts = Magick::ReadOptions();
#if MagickLibVersion >= 0x690
  opts.quiet(1);
#endif
  if(density.size())
    opts.density(std::string(density.at(0)).c_str());
  if(depth.size())
    opts.depth(depth.at(0));
  if(defines.size()){
    cpp11::strings names = defines.names();
    for(int i = 0; i < defines.size(); i++)
      MagickCore::SetImageOption(opts.imageInfo(),
                                 std::string(names.at(i)).c_str(),
                                 std::string(defines.at(i)).c_str());
  }
  Magick::readImages(image.get(), Magick::Blob(x.data(), x.size()), opts);
#else
  Magick::readImages(image.get(), Magick::Blob(x.data(), x.size()));
#endif
  if(strip)
    for_each (image->begin(), image->end(), Magick::stripImage());
  return image;
}

[[cpp11::register]] XPtrImage magick_image_readpath(cpp11::strings paths, cpp11::strings density, cpp11::integers depth,
                                bool strip, cpp11::strings defines){
  XPtrImage image = create();
#if MagickLibVersion >= 0x689
  Magick::ReadOptions opts = Magick::ReadOptions();
#if MagickLibVersion >= 0x690
  opts.quiet(1);
#endif
  if(density.size())
    opts.density(std::string(density.at(0)).c_str());
  if(depth.size())
    opts.depth(depth.at(0));
  if(defines.size()){
    cpp11::strings names = defines.names();
    for(int i = 0; i < defines.size(); i++)
      MagickCore::SetImageOption(opts.imageInfo(),
                                 std::string(names.at(i)).c_str(),
                                 std::string(defines.at(i)).c_str());
  }
  for(int i = 0; i < paths.size(); i++)
    Magick::readImages(image.get(), std::string(paths[i]), opts);
#else
  for(int i = 0; i < paths.size(); i++)
    Magick::readImages(image.get(), std::string(paths[i]));
#endif
  if(strip)
    for_each (image->begin(), image->end(), Magick::stripImage());
  return image;
}

[[cpp11::register]] XPtrImage magick_image_read_list(cpp11::list list){
  XPtrImage image = create();
  for(int i = 0; i < list.size(); i++) {
    if(TYPEOF(list[i]) != RAWSXP)
      throw std::runtime_error("magick_image_read_list can only read raw vectors");
    cpp11::raws x = list[i];
    Magick::readImages(image.get(), Magick::Blob(x.data(), x.size()));
  }
  return image;
}

[[cpp11::register]] cpp11::raws magick_image_write( XPtrImage input, cpp11::strings format, cpp11::integers quality,
                                    cpp11::integers depth, cpp11::strings density, cpp11::strings comment,
                                    cpp11::strings compression){
  if(!input->size())
    return cpp11::raws(0);
  XPtrImage image = copy(input);
#if MagickLibVersion >= 0x691
  //suppress write warnings see #74 and #116
  image->front().quiet(true);
#endif
  if(format.size())
    for_each ( image->begin(), image->end(), Magick::magickImage(std::string(format[0])));
  if(quality.size())
    for_each ( image->begin(), image->end(), Magick::qualityImage(quality[0]));
  if(depth.size())
    for_each ( image->begin(), image->end(), Magick::depthImage(depth[0]));
  if(density.size()){
    for_each ( image->begin(), image->end(), Magick::resolutionUnitsImage(Magick::PixelsPerInchResolution));
    for_each ( image->begin(), image->end(), Magick::densityImage(Point(std::string(density[0]).c_str())));
  }
  if(comment.size())
    for_each ( image->begin(), image->end(), Magick::commentImage(std::string(comment.at(0))));
  if(compression.size())
    for_each ( image->begin(), image->end(), Magick::compressTypeImage(Compression(std::string(compression.at(0)).c_str())));
  Magick::Blob output;
  writeImages( image->begin(), image->end(),  &output );
  cpp11::writable::raws res(output.length());
  std::memcpy(res.data(), output.data(), output.length());
  return res;
}

[[cpp11::register]] cpp11::raws magick_image_write_frame(XPtrImage input, const char * format, size_t i = 1){
  if(input->size() < 1)
    throw std::runtime_error("Image must have at least 1 frame to write a bitmap");
  Frame frame = input->at(i-1); //zero indexing!
  Magick::Geometry size(frame.size());
  size_t width = size.width();
  size_t height = size.height();
  Magick::Blob output;
  frame.write(&output, format, 8L);
  size_t output_len = output.length();
  if (output_len == 0)
    throw std::runtime_error("Unsupported raw format: " + std::string(format));
  if (output_len % (width * height))
    throw std::runtime_error("Dimensions do not add up, '" + std::string(format) + "' may not be a raw format");
  size_t slices = output_len / (width * height);
  cpp11::writable::raws res(output_len);
  memcpy(res.data(), output.data(), output_len);
  res.attr("class") = cpp11::writable::strings({"bitmap", format});
  res.attr("dim") = cpp11::writable::integers({static_cast<int>(slices),
                                               static_cast<int>(width),
                                               static_cast<int>(height)});
  return res;
}

[[cpp11::register]] cpp11::integers magick_image_write_integer(XPtrImage input){
  if(input->size() != 1)
    throw std::runtime_error("Image must have single frame to write a native raster");
  Frame frame = input->front();
  Magick::Geometry size(frame.size());
  size_t width = size.width();
  size_t height = size.height();
  Magick::Blob output;
  frame.write(&output, "RGBA", 8L);
  size_t output_len = output.length();
  cpp11::writable::integers res(output_len / 4);
  memcpy(res.data(), output.data(), output_len);
  res.attr("class") = cpp11::writable::strings({"nativeRaster"});
  res.attr("dim") = cpp11::writable::integers(
      {static_cast<int>(height), static_cast<int>(width)});
  return res;
}

[[cpp11::register]] XPtrImage magick_image_display( XPtrImage image, bool animate){
#ifndef MAGICKCORE_X11_DELEGATE
  throw std::runtime_error("ImageMagick was built without X11 support");
#else
  XPtrImage output = copy(image);
  if(animate){
    Magick::animateImages(output->begin(), output->end());
  } else {
    Magick::displayImages(output->begin(), output->end());
  }
#endif
  return image;
}

/* Not very useful. Requires imagemagick configuration with --enable-fftw=yes */
[[cpp11::register]] XPtrImage magick_image_fft( XPtrImage image){
  XPtrImage out = create();
  if(image->size())
    forwardFourierTransformImage(out.get(), image->front());
  return out;
}

[[cpp11::register]] XPtrImage magick_image_montage( XPtrImage image, cpp11::strings geometry, cpp11::strings tile,
                                cpp11::strings gravity, std::string bg = "white", bool shadow = false){
  XPtrImage out = create();
  Magick::Montage opts = Magick::Montage();
  if(geometry.size())
    opts.geometry(Geom(std::string(geometry.at(0)).c_str()));
  if(tile.size())
    opts.tile(Geom(std::string(tile.at(0)).c_str()));
  if(gravity.size())
    opts.gravity(Gravity(std::string(gravity.at(0)).c_str()));
  opts.shadow(shadow);
  opts.backgroundColor(bg);
  montageImages(out.get(), image->begin(), image->end(), opts);
  return out;
}

[[cpp11::register]] XPtrImage magick_image_strip( XPtrImage input){
  XPtrImage output = copy(input);
  for_each (output->begin(), output->end(), Magick::stripImage());
  return output;
}

[[cpp11::register]] XPtrImage magick_image_separate( XPtrImage input, const char * channel){
  XPtrImage output = create();
#if MagickLibVersion >= 0x687
  separateImages( output.get(), input->front(), Channel(channel));
#else
  throw std::runtime_error("Your imagemagick is too old for separateImages");
#endif
  return output;
}

[[cpp11::register]] XPtrImage magick_image_combine( XPtrImage input, const char * colorspace, const char * channel){
  Frame x;
#if MagickLibVersion >= 0x700
  combineImages(&x, input->begin(), input->end(), Channel(channel), ColorSpace(colorspace));
#elif MagickLibVersion >= 0x687
  combineImages(&x, input->begin(), input->end(), Channel(channel));
  x.colorspaceType(ColorSpace(colorspace));
#else
  throw std::runtime_error("Your imagemagick is too old for combineImages");
#endif
  XPtrImage output = create(1);
  output->push_back(x);
  return output;
}

[[cpp11::register]] XPtrImage magick_image_set_define( XPtrImage input, cpp11::strings format,
                                   cpp11::strings name, cpp11::strings value){
  //NB: do NOT copy; modifies
  if(!format.size() || !name.size() || !value.size())
    throw std::runtime_error("Missing format or key");
  std::string val(value.at(0));
  std::string fmt(format.at(0));
  std::string key(name.at(0));
  for(size_t i = 0; i < input->size(); i++){
    if(!val.size()){
      input->at(i).defineSet(fmt, key, true); // empty string
    } else if (cpp11::is_na(value.at(0))) {
      input->at(i).defineSet(fmt, key, false); // unset
    } else {
      input->at(i).defineValue(fmt, key, val);
    }
  }
  return input;
}
