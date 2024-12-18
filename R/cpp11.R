# Generated by cpp11: do not edit by hand

magick_image_animate <- function(input, delay, iter, method, optimize) {
  .Call(`_cpp11imagemagick_magick_image_animate`, input, delay, iter, method, optimize)
}

magick_image_coalesce <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_coalesce`, input)
}

magick_image_morph <- function(image, frames) {
  .Call(`_cpp11imagemagick_magick_image_morph`, image, frames)
}

magick_image_mosaic <- function(input, composite) {
  .Call(`_cpp11imagemagick_magick_image_mosaic`, input, composite)
}

magick_image_flatten <- function(input, composite) {
  .Call(`_cpp11imagemagick_magick_image_flatten`, input, composite)
}

magick_image_average <- function(image) {
  .Call(`_cpp11imagemagick_magick_image_average`, image)
}

magick_image_append <- function(image, stack) {
  .Call(`_cpp11imagemagick_magick_image_append`, image, stack)
}

magick_attr_comment <- function(input, set) {
  .Call(`_cpp11imagemagick_magick_attr_comment`, input, set)
}

magick_attr_text_antialias <- function(input, set) {
  .Call(`_cpp11imagemagick_magick_attr_text_antialias`, input, set)
}

magick_attr_stroke_antialias <- function(input, set) {
  .Call(`_cpp11imagemagick_magick_attr_stroke_antialias`, input, set)
}

magick_attr_animationdelay <- function(input, delay) {
  .Call(`_cpp11imagemagick_magick_attr_animationdelay`, input, delay)
}

magick_attr_backgroundcolor <- function(input, color) {
  .Call(`_cpp11imagemagick_magick_attr_backgroundcolor`, input, color)
}

magick_attr_boxcolor <- function(input, color) {
  .Call(`_cpp11imagemagick_magick_attr_boxcolor`, input, color)
}

magick_attr_fillcolor <- function(input, color) {
  .Call(`_cpp11imagemagick_magick_attr_fillcolor`, input, color)
}

magick_attr_font <- function(input, font) {
  .Call(`_cpp11imagemagick_magick_attr_font`, input, font)
}

magick_attr_fontsize <- function(input, pointsize) {
  .Call(`_cpp11imagemagick_magick_attr_fontsize`, input, pointsize)
}

magick_attr_label <- function(input, label) {
  .Call(`_cpp11imagemagick_magick_attr_label`, input, label)
}

magick_attr_format <- function(input, format) {
  .Call(`_cpp11imagemagick_magick_attr_format`, input, format)
}

magick_attr_quality <- function(input, quality) {
  .Call(`_cpp11imagemagick_magick_attr_quality`, input, quality)
}

magick_attr_quantize <- function(input, numcolors) {
  .Call(`_cpp11imagemagick_magick_attr_quantize`, input, numcolors)
}

magick_attr_density <- function(input, density) {
  .Call(`_cpp11imagemagick_magick_attr_density`, input, density)
}

magick_image_info <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_info`, input)
}

magick_image_as_raster <- function(data) {
  .Call(`_cpp11imagemagick_magick_image_as_raster`, data)
}

my_magick_init <- function(dll) {
  invisible(.Call(`_cpp11imagemagick_my_magick_init`, dll))
}

magick_threads <- function(i) {
  .Call(`_cpp11imagemagick_magick_threads`, i)
}

magick_image_dead <- function(image) {
  .Call(`_cpp11imagemagick_magick_image_dead`, image)
}

magick_image_length <- function(image) {
  .Call(`_cpp11imagemagick_magick_image_length`, image)
}

magick_image_blank <- function(width, height, color, pseudo_image, options) {
  .Call(`_cpp11imagemagick_magick_image_blank`, width, height, color, pseudo_image, options)
}

magick_image_rev <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_rev`, input)
}

magick_image_join <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_join`, input)
}

magick_image_subset <- function(image, index) {
  .Call(`_cpp11imagemagick_magick_image_subset`, image, index)
}

magick_image_replace <- function(image, index, value) {
  .Call(`_cpp11imagemagick_magick_image_replace`, image, index, value)
}

magick_image_copy <- function(image, add) {
  .Call(`_cpp11imagemagick_magick_image_copy`, image, add)
}

magick_image_destroy <- function(image) {
  invisible(.Call(`_cpp11imagemagick_magick_image_destroy`, image))
}

magick_resource_limits <- function() {
  .Call(`_cpp11imagemagick_magick_resource_limits`)
}

magick_image_contrast <- function(input, sharpen) {
  .Call(`_cpp11imagemagick_magick_image_contrast`, input, sharpen)
}

magick_image_normalize <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_normalize`, input)
}

magick_image_modulate <- function(input, brightness, saturation, hue) {
  .Call(`_cpp11imagemagick_magick_image_modulate`, input, brightness, saturation, hue)
}

magick_image_map <- function(input, map_image, dither) {
  .Call(`_cpp11imagemagick_magick_image_map`, input, map_image, dither)
}

magick_image_channel <- function(input, channel) {
  .Call(`_cpp11imagemagick_magick_image_channel`, input, channel)
}

magick_image_colorize <- function(input, opacity, color) {
  .Call(`_cpp11imagemagick_magick_image_colorize`, input, opacity, color)
}

magick_image_enhance <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_enhance`, input)
}

magick_image_equalize <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_equalize`, input)
}

magick_image_median <- function(input, radius) {
  .Call(`_cpp11imagemagick_magick_image_median`, input, radius)
}

magick_image_quantize <- function(input, max, space, dither, depth) {
  .Call(`_cpp11imagemagick_magick_image_quantize`, input, max, space, dither, depth)
}

magick_image_ordered_dither <- function(input, threshold_map) {
  .Call(`_cpp11imagemagick_magick_image_ordered_dither`, input, threshold_map)
}

magick_image_transparent <- function(input, color, fuzz_percent) {
  .Call(`_cpp11imagemagick_magick_image_transparent`, input, color, fuzz_percent)
}

magick_image_background <- function(input, color) {
  .Call(`_cpp11imagemagick_magick_image_background`, input, color)
}

magick_image_lat <- function(input, geomstr) {
  .Call(`_cpp11imagemagick_magick_image_lat`, input, geomstr)
}

magick_image_threshold_black <- function(input, threshold, channel) {
  .Call(`_cpp11imagemagick_magick_image_threshold_black`, input, threshold, channel)
}

magick_image_threshold_white <- function(input, threshold, channel) {
  .Call(`_cpp11imagemagick_magick_image_threshold_white`, input, threshold, channel)
}

magick_image_level <- function(input, black_pct, white_pct, mid_point, channel) {
  .Call(`_cpp11imagemagick_magick_image_level`, input, black_pct, white_pct, mid_point, channel)
}

magick_image_composite <- function(input, composite_image, offset, gravity, composite, args) {
  .Call(`_cpp11imagemagick_magick_image_composite`, input, composite_image, offset, gravity, composite, args)
}

magick_image_border <- function(input, color, geometry, composite) {
  .Call(`_cpp11imagemagick_magick_image_border`, input, color, geometry, composite)
}

magick_image_frame <- function(input, color, geometry) {
  .Call(`_cpp11imagemagick_magick_image_frame`, input, color, geometry)
}

magick_image_shadow_mask <- function(input, geomstr) {
  .Call(`_cpp11imagemagick_magick_image_shadow_mask`, input, geomstr)
}

magick_image_shade <- function(input, azimuth, elevation, color) {
  .Call(`_cpp11imagemagick_magick_image_shade`, input, azimuth, elevation, color)
}

magick_image_crop <- function(input, geometry, gravity, repage) {
  .Call(`_cpp11imagemagick_magick_image_crop`, input, geometry, gravity, repage)
}

magick_image_extent <- function(input, geometry, gravity, color) {
  .Call(`_cpp11imagemagick_magick_image_extent`, input, geometry, gravity, color)
}

magick_image_artifact <- function(input, name) {
  .Call(`_cpp11imagemagick_magick_image_artifact`, input, name)
}

magick_coder_info <- function(format) {
  .Call(`_cpp11imagemagick_magick_coder_info`, format)
}

magick_config_internal <- function() {
  .Call(`_cpp11imagemagick_magick_config_internal`)
}

magick_image_fx <- function(input, expression, channel) {
  .Call(`_cpp11imagemagick_magick_image_fx`, input, expression, channel)
}

magick_image_fx_sequence <- function(input, expr) {
  .Call(`_cpp11imagemagick_magick_image_fx_sequence`, input, expr)
}

magick_image_morphology <- function(input, method, kernel, iter, opt_names, opt_values) {
  .Call(`_cpp11imagemagick_magick_image_morphology`, input, method, kernel, iter, opt_names, opt_values)
}

magick_image_convolve_kernel <- function(input, kernel, iter, scaling, bias) {
  .Call(`_cpp11imagemagick_magick_image_convolve_kernel`, input, kernel, iter, scaling, bias)
}

magick_image_convolve_matrix <- function(input, matrix, iter, scaling, bias) {
  .Call(`_cpp11imagemagick_magick_image_convolve_matrix`, input, matrix, iter, scaling, bias)
}

magick_device_internal <- function(bg, width, height, pointsize, res, clip, antialias, drawing) {
  .Call(`_cpp11imagemagick_magick_device_internal`, bg, width, height, pointsize, res, clip, antialias, drawing)
}

magick_device_get <- function(n) {
  .Call(`_cpp11imagemagick_magick_device_get`, n)
}

magick_device_pop <- function() {
  .Call(`_cpp11imagemagick_magick_device_pop`)
}

magick_image_edge <- function(input, radius) {
  .Call(`_cpp11imagemagick_magick_image_edge`, input, radius)
}

magick_image_canny <- function(input, geomstr) {
  .Call(`_cpp11imagemagick_magick_image_canny`, input, geomstr)
}

magick_image_houghline <- function(input, geomstr, col, bg, lwd) {
  .Call(`_cpp11imagemagick_magick_image_houghline`, input, geomstr, col, bg, lwd)
}

magick_image_readbitmap_native <- function(x) {
  .Call(`_cpp11imagemagick_magick_image_readbitmap_native`, x)
}

magick_image_readbitmap_raster1 <- function(x) {
  .Call(`_cpp11imagemagick_magick_image_readbitmap_raster1`, x)
}

magick_image_readbitmap_raster2 <- function(x) {
  .Call(`_cpp11imagemagick_magick_image_readbitmap_raster2`, x)
}

magick_image_readbitmap_raw <- function(x) {
  .Call(`_cpp11imagemagick_magick_image_readbitmap_raw`, x)
}

magick_image_readbitmap_double <- function(x) {
  .Call(`_cpp11imagemagick_magick_image_readbitmap_double`, x)
}

magick_image_readbin <- function(x, density, depth, strip, defines) {
  .Call(`_cpp11imagemagick_magick_image_readbin`, x, density, depth, strip, defines)
}

magick_image_readpath <- function(paths, density, depth, strip, defines) {
  .Call(`_cpp11imagemagick_magick_image_readpath`, paths, density, depth, strip, defines)
}

magick_image_read_list <- function(list) {
  .Call(`_cpp11imagemagick_magick_image_read_list`, list)
}

magick_image_write <- function(input, format, quality, depth, density, comment, compression) {
  .Call(`_cpp11imagemagick_magick_image_write`, input, format, quality, depth, density, comment, compression)
}

magick_image_write_frame <- function(input, format, i) {
  .Call(`_cpp11imagemagick_magick_image_write_frame`, input, format, i)
}

magick_image_write_integer <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_write_integer`, input)
}

magick_image_display <- function(image, animate) {
  .Call(`_cpp11imagemagick_magick_image_display`, image, animate)
}

magick_image_fft <- function(image) {
  .Call(`_cpp11imagemagick_magick_image_fft`, image)
}

magick_image_montage <- function(image, geometry, tile, gravity, bg, shadow) {
  .Call(`_cpp11imagemagick_magick_image_montage`, image, geometry, tile, gravity, bg, shadow)
}

magick_image_strip <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_strip`, input)
}

magick_image_separate <- function(input, channel) {
  .Call(`_cpp11imagemagick_magick_image_separate`, input, channel)
}

magick_image_combine <- function(input, colorspace, channel) {
  .Call(`_cpp11imagemagick_magick_image_combine`, input, colorspace, channel)
}

magick_image_set_define <- function(input, format, name, value) {
  .Call(`_cpp11imagemagick_magick_image_set_define`, input, format, name, value)
}

list_options <- function(str) {
  .Call(`_cpp11imagemagick_list_options`, str)
}

list_font_info <- function() {
  .Call(`_cpp11imagemagick_list_font_info`)
}

dump_option_list <- function(args) {
  invisible(.Call(`_cpp11imagemagick_dump_option_list`, args))
}

set_magick_tempdir <- function(new_tmpdir) {
  .Call(`_cpp11imagemagick_set_magick_tempdir`, new_tmpdir)
}

set_magick_seed <- function(seed) {
  invisible(.Call(`_cpp11imagemagick_set_magick_seed`, seed))
}

magick_image_properties <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_properties`, input)
}

magick_image_scale <- function(input, geometry) {
  .Call(`_cpp11imagemagick_magick_image_scale`, input, geometry)
}

magick_image_sample <- function(input, geometry) {
  .Call(`_cpp11imagemagick_magick_image_sample`, input, geometry)
}

magick_image_resize <- function(input, geometry, filter) {
  .Call(`_cpp11imagemagick_magick_image_resize`, input, geometry, filter)
}

magick_image_rotate <- function(input, degrees) {
  .Call(`_cpp11imagemagick_magick_image_rotate`, input, degrees)
}

magick_image_chop <- function(input, geometry) {
  .Call(`_cpp11imagemagick_magick_image_chop`, input, geometry)
}

magick_image_trim <- function(input, fuzz_percent) {
  .Call(`_cpp11imagemagick_magick_image_trim`, input, fuzz_percent)
}

magick_image_flip <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_flip`, input)
}

magick_image_flop <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_flop`, input)
}

magick_image_shear <- function(input, geometry, color) {
  .Call(`_cpp11imagemagick_magick_image_shear`, input, geometry, color)
}

magick_image_fuzzycmeans <- function(input, min_pixels, smoothing) {
  .Call(`_cpp11imagemagick_magick_image_fuzzycmeans`, input, min_pixels, smoothing)
}

magick_image_connect <- function(input, connectivity) {
  .Call(`_cpp11imagemagick_magick_image_connect`, input, connectivity)
}

magick_image_noise <- function(input, noisetype) {
  .Call(`_cpp11imagemagick_magick_image_noise`, input, noisetype)
}

magick_image_blur <- function(input, radius, sigma) {
  .Call(`_cpp11imagemagick_magick_image_blur`, input, radius, sigma)
}

magick_image_motion_blur <- function(input, radius, sigma, angle) {
  .Call(`_cpp11imagemagick_magick_image_motion_blur`, input, radius, sigma, angle)
}

magick_image_charcoal <- function(input, radius, sigma) {
  .Call(`_cpp11imagemagick_magick_image_charcoal`, input, radius, sigma)
}

magick_image_deskew <- function(input, treshold) {
  .Call(`_cpp11imagemagick_magick_image_deskew`, input, treshold)
}

magick_image_emboss <- function(input, radius, sigma) {
  .Call(`_cpp11imagemagick_magick_image_emboss`, input, radius, sigma)
}

magick_image_fill <- function(input, color, point, fuzz_percent, border_color) {
  .Call(`_cpp11imagemagick_magick_image_fill`, input, color, point, fuzz_percent, border_color)
}

magick_image_negate <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_negate`, input)
}

magick_image_oilpaint <- function(input, radius) {
  .Call(`_cpp11imagemagick_magick_image_oilpaint`, input, radius)
}

magick_image_implode <- function(input, factor) {
  .Call(`_cpp11imagemagick_magick_image_implode`, input, factor)
}

magick_image_format <- function(input, format, type, space, depth, antialias, matte, interlace, profile) {
  .Call(`_cpp11imagemagick_magick_image_format`, input, format, type, space, depth, antialias, matte, interlace, profile)
}

magick_image_page <- function(input, pagesize, density) {
  .Call(`_cpp11imagemagick_magick_image_page`, input, pagesize, density)
}

magick_image_repage <- function(input) {
  .Call(`_cpp11imagemagick_magick_image_repage`, input)
}

magick_image_orient <- function(input, orientation) {
  .Call(`_cpp11imagemagick_magick_image_orient`, input, orientation)
}

magick_image_despeckle <- function(input, times) {
  .Call(`_cpp11imagemagick_magick_image_despeckle`, input, times)
}

magick_image_reducenoise <- function(input, radius) {
  .Call(`_cpp11imagemagick_magick_image_reducenoise`, input, radius)
}

magick_image_annotate <- function(input, text, gravity, location, rot, size, font, style, weight, kerning, decoration, color, strokecolor, strokewidth, boxcolor) {
  .Call(`_cpp11imagemagick_magick_image_annotate`, input, text, gravity, location, rot, size, font, style, weight, kerning, decoration, color, strokecolor, strokewidth, boxcolor)
}

magick_image_compare <- function(input, reference_image, metric, fuzz_percent) {
  .Call(`_cpp11imagemagick_magick_image_compare`, input, reference_image, metric, fuzz_percent)
}

magick_image_distort <- function(input, method, values, bestfit) {
  .Call(`_cpp11imagemagick_magick_image_distort`, input, method, values, bestfit)
}
