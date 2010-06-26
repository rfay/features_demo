<?php

/**
 * ================== Multi-step form demonstration ==================
 */

function form_fun_more(&$form_state) {
  $form['#tree'] = TRUE;

  // If we have stored values from a previous step, re-create
  // the fields for address and populate them properly.
  if (!empty($form_state['storage'])) {
    foreach($form_state['storage'] as $key => $values) {
      $form['addresses'][] = form_fun_address_fields($values);
    }
  }

  // Always put a blank field at the end.
  $form['addresses'][] = form_fun_address_fields();

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['more'] = array(
    '#type' => 'submit',
    '#value' => t('Give me another address'),
    '#submit' => array('form_fun_more_more'),
  );
  return $form;
}



function form_fun_more_submit(&$form, &$form_state) {
  unset($form_state['storage']);
  drupal_set_message(t('Your addresses were submitted!'));
  dsm($form_state['values']['addresses']);
}



function form_fun_more_more(&$form, &$form_state) {
  $form_state['storage'] = $form_state['values']['addresses'];
  $form_state['rebuild'] = TRUE;
}



function form_fun_address_fields($values = array()) {
  $values += array(
    'addresstype' => 'home',
    'street' => '',
    'city' => '',
    'state' => '',
    'postcode' => '',
    'country' => '',
  );

  $address_fields = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
  );
  $address_fields['addresstype'] = array(
    '#type' => 'select',
    '#options' => array(
      'home' => t('Home address'),
      'work' => t('Work address'),
      'pobox' => t('Post office box'),
      'other' => t('Other address'),
    ),
    '#default_value' => $values['addresstype'],
  );
  $address_fields['street'] = array(
    '#type' => 'textfield',
    '#title' => t("Street"),
    '#default_value' => $values['street'],
  );
  $address_fields['city'] = array(
    '#type' => 'textfield',
    '#title' => t("City"),
    '#default_value' => $values['city'],
  );
  $address_fields['state'] = array(
    '#type' => 'textfield',
    '#title' => t("State"),
    '#default_value' => $values['state'],
  );
  $address_fields['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t("Postal code"),
    '#default_value' => $values['postcode'],
  );
  $address_fields['country'] = array(
    '#type' => 'textfield',
    '#title' => t("Country"),
    '#default_value' => $values['country'],
  );
  return $address_fields;
}
