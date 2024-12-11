#include "00_magick_types.h"

[[cpp11::register]] cpp11::list magick_coder_info(std::string format) {
  Magick::CoderInfo info(format);
  return cpp11::writable::list(
      {"name"_nm = std::string(info.name()),
       "description"_nm = std::string(info.description()),
       "isReadable"_nm = info.isReadable() ? "true" : "false",
       "isWritable"_nm = info.isWritable() ? "true" : "false",
       "isMultiFrame"_nm = info.isMultiFrame() ? "true" : "false"});
}

/* Delegates are defined in include/ImageMagick-6/magick/magick-baseconfig.h */

[[cpp11::register]] cpp11::list magick_config_internal() {
  cpp11::writable::list out;

  out.push_back({"version"_nm = MAGICKCORE_PACKAGE_VERSION});

#ifdef MAGICKCORE_BUILD_MODULES
  out.push_back({"modules"_nm = true});
#else
  out.push_back({"modules"_nm = false});
#endif

#ifdef MAGICKCORE_CAIRO_DELEGATE
  out.push_back({"cairo"_nm = true});
#else
  out.push_back({"cairo"_nm = false});
#endif

#ifdef MAGICKCORE_FONTCONFIG_DELEGATE
  out.push_back({"fontconfig"_nm = true});
#else
  out.push_back({"fontconfig"_nm = false});
#endif

#ifdef MAGICKCORE_FREETYPE_DELEGATE
  out.push_back({"freetype"_nm = true});
#else
  out.push_back({"freetype"_nm = false});
#endif

#ifdef MAGICKCORE_FFTW_DELEGATE
  out.push_back({"fftw"_nm = true});
#else
  out.push_back({"fftw"_nm = false});
#endif

/* On Windows, the system ghostscript is used
 * See
 * https://github.com/ImageMagick/ImageMagick6/blob/master/magick/version.c#L136
 */
#if defined(MAGICKCORE_GS_DELEGATE) || defined(MAGICKCORE_WINDOWS_SUPPORT)
  out.push_back({"ghostscript"_nm = true});
#else
  out.push_back({"ghostscript"_nm = false});
#endif

#ifdef MAGICKCORE_HEIC_DELEGATE
  out.push_back({"heic"_nm = true});
#else
  out.push_back({"heic"_nm = false});
#endif

#ifdef MAGICKCORE_JPEG_DELEGATE
  out.push_back({"jpeg"_nm = true});
#else
  out.push_back({"jpeg"_nm = false});
#endif

#ifdef MAGICKCORE_LCMS_DELEGATE
  out.push_back({"lcms"_nm = true});
#else
  out.push_back({"lcms"_nm = false});
#endif

#ifdef MAGICKCORE_LIBOPENJP2_DELEGATE
  out.push_back({"libopenjp2"_nm = true});
#else
  out.push_back({"libopenjp2"_nm = false});
#endif

#ifdef MAGICKCORE_LZMA_DELEGATE
  out.push_back({"lzma"_nm = true});
#else
  out.push_back({"lzma"_nm = false});
#endif

#ifdef MAGICKCORE_PANGOCAIRO_DELEGATE
  out.push_back({"pangocairo"_nm = true});
#else
  out.push_back({"pangocairo"_nm = false});
#endif

#ifdef MAGICKCORE_PANGO_DELEGATE
  out.push_back({"pango"_nm = true});
#else
  out.push_back({"pango"_nm = false});
#endif

#ifdef MAGICKCORE_PNG_DELEGATE
  out.push_back({"png"_nm = true});
#else
  out.push_back({"png"_nm = false});
#endif

#ifdef MAGICKCORE_RAW_R_DELEGATE
  out.push_back({"raw"_nm = true});
#else
  out.push_back({"raw"_nm = false});
#endif

#ifdef MAGICKCORE_RSVG_DELEGATE
  out.push_back({"rsvg"_nm = true});
#else
  out.push_back({"rsvg"_nm = false});
#endif

#ifdef MAGICKCORE_TIFF_DELEGATE
  out.push_back({"tiff"_nm = true});
#else
  out.push_back({"tiff"_nm = false});
#endif

#ifdef MAGICKCORE_WEBP_DELEGATE
  out.push_back({"webp"_nm = true});
#else
  out.push_back({"webp"_nm = false});
#endif

#ifdef MAGICKCORE_WMF_DELEGATE
  out.push_back({"wmf"_nm = true});
#else
  out.push_back({"wmf"_nm = false});
#endif

#ifdef MAGICKCORE_X11_DELEGATE
  out.push_back({"x11"_nm = true});
#else
  out.push_back({"x11"_nm = false});
#endif

#ifdef MAGICKCORE_XML_DELEGATE
  out.push_back({"xml"_nm = true});
#else
  out.push_back({"xml"_nm = false});
#endif

#ifdef MAGICKCORE_ZERO_CONFIGURATION_SUPPORT
  out.push_back({"zero-configuration"_nm = true});
#else
  out.push_back({"zero-configuration"_nm = false});
#endif

  return out;
}
