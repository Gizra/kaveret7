<?php
currencies_load();

/*
 * Implements ctools hook mcapi_default_forms
 * N.B. Because ctools doesn't seem to run cache as well as might be expected, this is called any time a form is needed
 * Also: these are saved in the menu item arguments which may cause unexpected cacheing behaviour
 */
function mcapi_forms_mcapiforms_default() {
  $forms = array('1stparty', '3rdparty');
  foreach ($forms as $form_id) {
    $function = 'mcapiform_default_'.$form_id;
    $mcapiforms[$form_id] = $function();
  }
  return $mcapiforms;
}

function mcapiform_default_1stparty() {
  $currencies = &drupal_static('currencies');
  $mcapiform = new stdClass;
  $mcapiform->disabled = FALSE; /* Edit this to true to make a default mcapi_form disabled initially */
  $mcapiform->api_version = 3;
  $mcapiform->name = '1stparty';
  $mcapiform->data = array(
    'info' => array(
      'name' => '1stparty',
    ),
    'perspective' => '1',
    'architecture' => array(
      'path' => 'transact/1stparty',
      'access' => 'user_access:transact',
      'menu_link' => MENU_DEFAULT_LOCAL_TASK,
      'use_block' => 1,
    ),
    'secondperson' => array(
      'preset' => '',
      'args' => 'user_chooser_permissions:transact',
    ),
    'direction' => array(
      'preset' => 'outgoing',
      'incoming' => 'Request',
      'outgoing' => 'Payment',
      'widget' => 'select',
    ),
    'worth' => array(
      'preset' => array(
        'und' => array(
          0 => array(
            'currcode' => key($currencies),
            'quantity' => '0',
            'main_quant' => '0',
            'division' => '0'
          ),
        ),
        'disable' => 0,
        'required' => 1,
      ),
    ),
    'submission' => array(
      'button' => 'Submit',
      'redirect' => '',
      'feedback' => ''
    ),
    'experience' => array(
      'title' => t('Make a payment'),
      'template' => t('Partner: [mcapiform:secondperson]<br />
Direction: [mcapiform:direction]<br />
Amount: [mcapiform:worth]<br />'),
      'sure_title' => t('Are you sure?'),
      'sure_format' => t('certificate'),
    )
  );
  return $mcapiform;
}

function mcapiform_default_3rdparty() {
  $currencies = &drupal_static('currencies');
  $mcapiform = new stdClass;
  $mcapiform->disabled = FALSE; /* Edit this to true to make a default form disabled initially */
  $mcapiform->api_version = 3;
  $mcapiform->name = '3rdparty';
  $mcapiform->data = array(
    'info' => array(
      'name' => '3rdparty',
    ),
    'perspective' => '3',
    'architecture' => array(
      'path' => 'transact/3rdparty',
      'access' => 'user_access:manage all transactions',
      'menu_link' => MENU_LOCAL_TASK,
      'use_block' => 1,
    ),
    'payer' => array(
      'preset' => '',
      'args' => 'user_chooser_permissions:transact',
      'multiple' => 0,
    ),
    'payee' => array(
      'preset' => '',
      'args' => 'user_chooser_permissions:transact',
      'multiple' => 0,
    ),
    'worth' => array(
      'preset' => array(
        'und' => array(
          0 => array(
            'currcode' => key($currencies),
            'quantity' => '0',
            'main_quant' => '0',
            'division' => '0'
          ),
        ),
      ),
    ),
    'submission' => array(
      'button' => 'Submit',
      'redirect' => '',
      'feedback' => ''
    ),
    'experience' => array(
      'title' => t('Record a transaction'),
      'template' => t('Payer: [mcapiform:payer]<br />
Payee: [mcapiform:payee]<br />
Amount: [mcapiform:worth]<br />'),
      'sure_title' => t('Are you sure?'),
      'sure_format' => t('certificate'),
    ),
  );
  return $mcapiform;
}
