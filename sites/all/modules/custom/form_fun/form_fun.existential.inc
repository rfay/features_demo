<?php

/**
 * ================== Form State demonstration ==================
 */

function form_fun_existential(&$form_state) {
  $form['identity'] = array(
    '#type' => 'fieldset',
    '#title' => t('Existential questions'),
    '#description' => t('Please validate your existence.'),
    '#collapsible' => TRUE,
  );

  $form['identity']['existence'] = array(
    '#type' => 'checkbox',
    '#title' => t('Yes, I exist.'),
    '#default_value' => TRUE,
  );
  $form['identity']['fruitiness'] = array(
    '#type' => 'checkbox',
    '#title' => t('Also, I am a banana.'),
    '#default_value' => FALSE,
  );
  $form['identity']['euthyphro'] = array(
    '#type' => 'textarea',
    '#title' => t("Is moral goodness implicit or ascribed?"),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

function form_fun_existential_submit($form, &$form_state) {
  dsm($form_state);
}
