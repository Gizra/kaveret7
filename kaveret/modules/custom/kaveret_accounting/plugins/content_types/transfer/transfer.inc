<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Transfer form'),
  'description' => t('Display the transfer form.'),
  'required context' => new ctools_context_required(t('User'), 'user'),
  'category' => t('Kaveret'),
);

/**
 * Render callback.
 */
function kaveret_accounting_transfer_content_type_render($subtype, $conf, $args, $context) {
  if (empty($context->data)) {
    return;
  }
  $account = $context->data;

  $block = new stdClass();
  $block->module = 'kaveret_accounting';
  $block->title = '';
  $block->content = 'Ha!';
  return $block;
}

/**
 * Edit form.
 */
function kaveret_accounting_transfer_content_type_edit_form($form, &$form_state) {
  return $form;
}
