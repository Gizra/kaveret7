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

  /*$wrapper = entity_metadata_wrapper('node', $node);
  $account = user_load($node->uid);*/

  $block = new stdClass();
  $block->module = 'kaveret_page';
  $block->title = '';

  $query = new EntityFieldQuery();

  $result = $query->entityCondition('entity_type', 'node')
    ->propertyCondition('type', array('offer'), 'IN')
    ->propertyCondition('uid', $user->uid)
    ->execute();

  foreach ($result['node'] as $info) {
    $wrapper = entity_metadata_wrapper('node', $info->nid);
    $offers_item[] = l( t($wrapper->label()), 'node/' . $info->nid);
 }

  $query_r = new EntityFieldQuery();

  $result_r = $query_r->entityCondition('entity_type', 'node')
    ->propertyCondition('type', array('request'), 'IN')
    ->propertyCondition('uid', $user->uid)
    ->execute();

  foreach ($result_r['node'] as $info_r) {
    $wrapper_r = entity_metadata_wrapper('node', $info_r->nid);
    $requests_item[] = l( t($wrapper_r->label()), 'node/' . $info_r->nid);
  }

  $output = '<h3>' . t('My Offers') . '</h3>' . theme('item_list', array('items' => $offers_item)) . l(t('+ Create a new offer'),'node/add/offer');
  $output .= '<h3>' . t('My Requests') . '</h3>' . theme('item_list', array('items' => $requests_item)) . l(t('+ Create a new  request'),'node/add/request');
  $output .= '<h3>' . t('My Groups') . '</h3>' . l(t('+ Create a new  request'),'node/add/request');




  $block->content = $output;
 return $block;
}

/**
* Edit form.
*/
function kaveret_page_right_sidebar_menu_content_type_edit_form($form, &$form_state) {
  return $form;
}
