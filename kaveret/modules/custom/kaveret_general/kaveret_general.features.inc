<?php
/**
 * @file
 * kaveret.features.inc
 * kaveret_general.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function kaveret_image_default_styles() {
  $styles = array();

  // Exported image style: user_picture.
  $styles['user_picture'] = array(
    'name' => 'user_picture',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '50',
          'height' => '50',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}


/**
 * Implements hook_ctools_plugin_api().
 */
function kaveret_general_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
