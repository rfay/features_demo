<?php

/**
 * ================== Basic form demonstration ==================
 */

/**
 * This function is a standard plain-vanilla page callback. Its job is
 * to return a bunch of HTML to Drupal when the user hits this page's URL.
 */
function form_fun_cake_page() {
  return drupal_get_form('form_fun_cake');
}


/**
 * This function's name is the same as the 'form id'. It gets called by
 * drupal_get_form() to build the array that defines the form's structure.
 * Usually, $form_state is empty. If the form is a multi-step form,
 * $form_state will contain information that has been accumulated in previous
 * steps.
 */
function form_fun_cake(&$form_state) {
  $form['choice'] = array(
    '#type' => 'select',
    '#title' => t('Cake or death'),
    '#description' => t('You must have tea and cake with the vicar... or you die!'),
    '#options' => array(
      'cake' => t('Cake with the vicar'),
      'death' => t('Death'),
      'chicken' => t('Chicken'),
    ),
    '#default_value' => !empty($form_state['values']['choice']) ? $form_state['values']['choice'] : 'cake',
    '#required' => TRUE,
  );

  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  
  // Because the 'unsure' button has a #submit property, that function
  // will be called if it is clicked instead of the form's default
  // submit handler.
  $form['buttons']['unsure'] = array(
    '#type' => 'submit',
    '#value' => t('Equivocate'),
    '#submit' => array('form_fun_cake_equivocate'),
    '#validate' => array(),
  );

  return $form;
}


/**
 * The function {$form_id}_validate() is called automatically whenever the
 * user submits the form. Its job is to look at the $form_state['values'],
 * and call form_set_error() if any data is incorrect.
 */
function form_fun_cake_validate($form, &$form_state) {
  if ($form_state['values']['choice'] == 'cake') {
    form_set_error('choice', t("We're out of cake! We only had three bits and we didn't expect such a rush."));
  }
}


/**
 * The function {$form_id}_submit() is called if no form errors are found.
 * After the data is processed, FormAPI will reload the page with an empty
 * copy of the form. Setting $form_state['redirect'] to a path will cause it
 * to redirect to a diffent page when processing is finished.
 */
function form_fun_cake_submit($form, &$form_state) {
  $choice = $form_state['values']['choice'];
  switch ($choice) {
    case 'cake':
      $form_state['redirect'] = 'http://tinyurl.com/pq3ya';
      break;
    case 'death':
      $form_state['redirect'] = 'http://tinyurl.com/3bmxla';
      break;
    case 'chicken':
      $form_state['redirect'] = 'http://tinyurl.com/34h68j';
      break;
  }
}

/**
 * The function is ONLY called if the 'equivocate' button is clicked.
 * Otherwise, the normal submit handler is called.
 */
function form_fun_cake_equivocate(&$form, &$form_state) {
  drupal_set_message(t('Make up your mind!'), 'warning');
  $form_state['rebuild'] = TRUE;
}
