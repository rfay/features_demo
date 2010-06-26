<?php

/**
 * ================== Nested form elements demonstration ==================
 */

function form_fun_tree(&$form_state) {
  $form['#tree'] = TRUE;

  $form['home'] = array(
    '#type' => 'fieldset',
    '#title' => t('Home address'),
    '#collapsible' => FALSE,
  );
  $form['home']['street'] = array(
    '#type' => 'textfield',
    '#title' => t("Street"),
  );
  $form['home']['city'] = array(
    '#type' => 'textfield',
    '#title' => t("City"),
  );
  $form['home']['state'] = array(
    '#type' => 'textfield',
    '#title' => t("State"),
  );
  $form['home']['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t("Postal code"),
  );
  $form['home']['country'] = array(
    '#type' => 'textfield',
    '#title' => t("Country"),
  );

  $form['work'] = array(
    '#type' => 'fieldset',
    '#title' => t('Work address'),
  );
  $form['work']['street'] = array(
    '#type' => 'textfield',
    '#title' => t("Street"),
  );
  $form['work']['city'] = array(
    '#type' => 'textfield',
    '#title' => t("City"),
  );
  $form['work']['state'] = array(
    '#type' => 'textfield',
    '#title' => t("State"),
  );
  $form['work']['postcode'] = array(
    '#type' => 'textfield',
    '#title' => t("Postal code"),
  );
  $form['work']['country'] = array(
    '#type' => 'textfield',
    '#title' => t("Country"),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function form_fun_tree_submit(&$form, &$form_state) {
  $form_state['redirect'] = FALSE;
  dsm($form_state);
}
