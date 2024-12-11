#' @title Open Source OCR Engine
#'
#' @description
#' Bindings to 'ImageMagick':
#' The most comprehensive open-source image processing library available.
#' Supports many common formats (png, jpeg, tiff, pdf, etc) and manipulations
#' (rotate, scale, crop, trim, flip, blur, etc). All operations are vectorized
#' via the Magick++ STL meaning they operate either on a single frame or a
#' series of frames for working with layers, collages, or animation. In RStudio,
#' the images are automatically previewed when printed to the console,
#' resulting in an interactive editing environment. Includes a native graphics
#' device for creating  in-memory graphics or drawing onto images using pixel
#' coordinates.
#'
#' @name cpp11imagemagick-package
#' @useDynLib cpp11imagemagick, .registration = TRUE
"_PACKAGE"
