<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Right sidebar menu'),
  'description' => t('Display the list of links on the right sidebar menu.'),
  'category' => t('Kaveret'),
);

/**
 * Render callback.
 */
function kaveret_page_right_sidebar_menu_content_type_render($subtype, $conf, $args, $context) {
  global $user;

  $block = new stdClass();
  $block->module = 'kaveret_page';
  $block->title = '';

  $query = new EntityFieldQuery();

  $result = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', array('offer', 'request', 'community'), 'IN')
    ->propertyCondition('uid', $user->uid)
    ->execute();

  foreach ($result['node'] as $info) {
    $wrapper = entity_metadata_wrapper('node', $info->nid);

    $type = $wrapper->getBundle();
    $items[$type][] = l( t($wrapper->label()), 'node/' . $info->nid);

  }

  $output = '<h3>' . t('My Offers') . '</h3>' . theme('item_list', array('items' => $items['offer'])) . l(t('+ Create a new offer'),'node/add/offer');
  $output .= '<h3>' . t('My Requests') . '</h3>' . theme('item_list', array('items' => $items['request'])) . l(t('+ Create a new  request'),'node/add/request');
  $output .= '<h3>' . t('My Groups') . '</h3>' . theme('item_list', array('items' => $items['community'])) . l(t('+ Create a new group'),'node/add/community');

  $block->content = $output;
  return $block;
}

/**
* Edit form.
*/
function kaveret_page_right_sidebar_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
