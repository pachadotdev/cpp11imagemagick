// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "magick_types.h"
#include <Rcpp.h>

using namespace Rcpp;

// magick_coder_info
Rcpp::List magick_coder_info(Rcpp::String format);
RcppExport SEXP magick_magick_coder_info(SEXP formatSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Rcpp::String >::type format(formatSEXP);
    __result = Rcpp::wrap(magick_coder_info(format));
    return __result;
END_RCPP
}
// magick_frame_read
XPtrFrame magick_frame_read(Rcpp::RawVector x);
RcppExport SEXP magick_magick_frame_read(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Rcpp::RawVector >::type x(xSEXP);
    __result = Rcpp::wrap(magick_frame_read(x));
    return __result;
END_RCPP
}
// magick_frame_write
Rcpp::RawVector magick_frame_write(XPtrFrame frame, Rcpp::String format);
RcppExport SEXP magick_magick_frame_write(SEXP frameSEXP, SEXP formatSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrFrame >::type frame(frameSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type format(formatSEXP);
    __result = Rcpp::wrap(magick_frame_write(frame, format));
    return __result;
END_RCPP
}
// magick_frame_info
Rcpp::List magick_frame_info(XPtrFrame frame);
RcppExport SEXP magick_magick_frame_info(SEXP frameSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrFrame >::type frame(frameSEXP);
    __result = Rcpp::wrap(magick_frame_info(frame));
    return __result;
END_RCPP
}
// magick_image_length
int magick_image_length(XPtrImage image);
RcppExport SEXP magick_magick_image_length(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_length(image));
    return __result;
END_RCPP
}
// magick_image_join
XPtrImage magick_image_join(Rcpp::List input);
RcppExport SEXP magick_magick_image_join(SEXP inputSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Rcpp::List >::type input(inputSEXP);
    __result = Rcpp::wrap(magick_image_join(input));
    return __result;
END_RCPP
}
// magick_image_subset
XPtrImage magick_image_subset(XPtrImage image, Rcpp::IntegerVector index);
RcppExport SEXP magick_magick_image_subset(SEXP imageSEXP, SEXP indexSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::IntegerVector >::type index(indexSEXP);
    __result = Rcpp::wrap(magick_image_subset(image, index));
    return __result;
END_RCPP
}
// magick_image_delay
XPtrImage magick_image_delay(XPtrImage image, int delay);
RcppExport SEXP magick_magick_image_delay(SEXP imageSEXP, SEXP delaySEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< int >::type delay(delaySEXP);
    __result = Rcpp::wrap(magick_image_delay(image, delay));
    return __result;
END_RCPP
}
// magick_image_format
XPtrImage magick_image_format(XPtrImage image, Rcpp::String format);
RcppExport SEXP magick_magick_image_format(SEXP imageSEXP, SEXP formatSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type format(formatSEXP);
    __result = Rcpp::wrap(magick_image_format(image, format));
    return __result;
END_RCPP
}
// magick_image_trim
XPtrImage magick_image_trim(XPtrImage image);
RcppExport SEXP magick_magick_image_trim(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_trim(image));
    return __result;
END_RCPP
}
// magick_image_background
XPtrImage magick_image_background(XPtrImage image, Rcpp::String color);
RcppExport SEXP magick_magick_image_background(SEXP imageSEXP, SEXP colorSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type color(colorSEXP);
    __result = Rcpp::wrap(magick_image_background(image, color));
    return __result;
END_RCPP
}
// magick_image_matte
XPtrImage magick_image_matte(XPtrImage image, bool matte, Rcpp::String color);
RcppExport SEXP magick_magick_image_matte(SEXP imageSEXP, SEXP matteSEXP, SEXP colorSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< bool >::type matte(matteSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type color(colorSEXP);
    __result = Rcpp::wrap(magick_image_matte(image, matte, color));
    return __result;
END_RCPP
}
// magick_image_pen
XPtrImage magick_image_pen(XPtrImage image, Rcpp::String color);
RcppExport SEXP magick_magick_image_pen(SEXP imageSEXP, SEXP colorSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type color(colorSEXP);
    __result = Rcpp::wrap(magick_image_pen(image, color));
    return __result;
END_RCPP
}
// magick_image_crop
XPtrImage magick_image_crop(XPtrImage image, Rcpp::String geometry);
RcppExport SEXP magick_magick_image_crop(SEXP imageSEXP, SEXP geometrySEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type geometry(geometrySEXP);
    __result = Rcpp::wrap(magick_image_crop(image, geometry));
    return __result;
END_RCPP
}
// magick_image_scale
XPtrImage magick_image_scale(XPtrImage image, Rcpp::String geometry);
RcppExport SEXP magick_magick_image_scale(SEXP imageSEXP, SEXP geometrySEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type geometry(geometrySEXP);
    __result = Rcpp::wrap(magick_image_scale(image, geometry));
    return __result;
END_RCPP
}
// magick_image_border
XPtrImage magick_image_border(XPtrImage image, Rcpp::String color, Rcpp::String geometry);
RcppExport SEXP magick_magick_image_border(SEXP imageSEXP, SEXP colorSEXP, SEXP geometrySEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type color(colorSEXP);
    Rcpp::traits::input_parameter< Rcpp::String >::type geometry(geometrySEXP);
    __result = Rcpp::wrap(magick_image_border(image, color, geometry));
    return __result;
END_RCPP
}
// magick_image_read
XPtrImage magick_image_read(Rcpp::RawVector x);
RcppExport SEXP magick_magick_image_read(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Rcpp::RawVector >::type x(xSEXP);
    __result = Rcpp::wrap(magick_image_read(x));
    return __result;
END_RCPP
}
// magick_image_read_list
XPtrImage magick_image_read_list(Rcpp::List list);
RcppExport SEXP magick_magick_image_read_list(SEXP listSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Rcpp::List >::type list(listSEXP);
    __result = Rcpp::wrap(magick_image_read_list(list));
    return __result;
END_RCPP
}
// magick_image_write
Rcpp::RawVector magick_image_write(XPtrImage image);
RcppExport SEXP magick_magick_image_write(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_write(image));
    return __result;
END_RCPP
}
// magick_image_append
XPtrImage magick_image_append(XPtrImage image, bool stack);
RcppExport SEXP magick_magick_image_append(SEXP imageSEXP, SEXP stackSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< bool >::type stack(stackSEXP);
    __result = Rcpp::wrap(magick_image_append(image, stack));
    return __result;
END_RCPP
}
// magick_image_average
XPtrImage magick_image_average(XPtrImage image);
RcppExport SEXP magick_magick_image_average(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_average(image));
    return __result;
END_RCPP
}
// magick_image_coalesce
XPtrImage magick_image_coalesce(XPtrImage image);
RcppExport SEXP magick_magick_image_coalesce(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_coalesce(image));
    return __result;
END_RCPP
}
// magick_image_flatten
XPtrImage magick_image_flatten(XPtrImage image);
RcppExport SEXP magick_magick_image_flatten(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_flatten(image));
    return __result;
END_RCPP
}
// magick_image_fft
XPtrImage magick_image_fft(XPtrImage image);
RcppExport SEXP magick_magick_image_fft(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_fft(image));
    return __result;
END_RCPP
}
// magick_image_map
XPtrImage magick_image_map(XPtrImage image, XPtrImage map_image, bool dither);
RcppExport SEXP magick_magick_image_map(SEXP imageSEXP, SEXP map_imageSEXP, SEXP ditherSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< XPtrImage >::type map_image(map_imageSEXP);
    Rcpp::traits::input_parameter< bool >::type dither(ditherSEXP);
    __result = Rcpp::wrap(magick_image_map(image, map_image, dither));
    return __result;
END_RCPP
}
// magick_image_montage
XPtrImage magick_image_montage(XPtrImage image);
RcppExport SEXP magick_magick_image_montage(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_montage(image));
    return __result;
END_RCPP
}
// magick_image_morph
XPtrImage magick_image_morph(XPtrImage image, int frames);
RcppExport SEXP magick_magick_image_morph(SEXP imageSEXP, SEXP framesSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    Rcpp::traits::input_parameter< int >::type frames(framesSEXP);
    __result = Rcpp::wrap(magick_image_morph(image, frames));
    return __result;
END_RCPP
}
// magick_image_mosaic
XPtrImage magick_image_mosaic(XPtrImage image);
RcppExport SEXP magick_magick_image_mosaic(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_mosaic(image));
    return __result;
END_RCPP
}
// magick_image_quantize
XPtrImage magick_image_quantize(XPtrImage image);
RcppExport SEXP magick_magick_image_quantize(SEXP imageSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< XPtrImage >::type image(imageSEXP);
    __result = Rcpp::wrap(magick_image_quantize(image));
    return __result;
END_RCPP
}
