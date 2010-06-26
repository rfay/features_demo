<?php

/**
 * ================== Multi-step form with AHAH demonstration ==================
 */


/**
 * This menu callback accepts a $_POST submission from FormAPI's client-side
 * jQuery code. It's responsible for retrieving the form from the cache,
 * changing it, saving it back to the cache, rendering the changed elements
 * (not the whole form), and returning it.
 */
function form_fun_ahah_callback() {
  // Build our new form element.
  $new_address_fields = form_fun_address_fields();

  // Build the new form. We change these settings to ensure that FormAPI
  // doesn't try to process and submit the form when we build the changed
  // version.
  $form_state = array('submitted' => FALSE);
  $form_build_id = $_POST['form_build_id'];

  // Add the new element to the stored form. Without adding the element to the
  // form, Drupal is not aware of this new elements existence and will not
  // process it. We retreive the cached form, add the element, and resave.
  $form = form_get_cache($form_build_id, $form_state);
  $form['addresses'][] = $new_address_fields;
  form_set_cache($form_build_id, $form, $form_state);
  $form += array(
    '#post' => $_POST,
    '#programmed' => FALSE,
  );

  // Rebuild the form. The form_builder() function is used internally
  // by FormAPI to prepare forms for processing and rendering. We'll use
  // it here to ensure that everything renders properly.
  $form = form_builder('form_fun_ahah', $form, $form_state);

  // Now that the entire form is prepared, we'll pull out the addresses,
  // and give the new one we've just added a special CSS class. FormAPI's
  // AHAH functions use it to apply visual effects when the element appears.
  $addresses = $form['addresses'];
  $index = count(element_children($addresses)) - 1;
  unset($addresses['#prefix'], $addresses['#suffix']); // Prevent duplicate wrappers.
  $addresses[$index]['#attributes']['class'] = empty($addresses[$index]['#attributes']['class']) ? 'ahah-new-content' : $addresses[$index]['#attributes']['class'] .' ahah-new-content';
  $output = drupal_render($addresses);

  // Convert the resulting output to a format
  drupal_json(array('status' => TRUE, 'data' => $output));
}


function form_fun_ahah(&$form_state) {
  // This is new! We've wrapped all of the addresses in a hard-coded
  // CSS ID so that jQuery can find the group of addresses easily.
  $form['addresses'] = array(
    '#tree' => TRUE,
    '#prefix' => '<div id="form-fun-addresses-wrapper">',
    '#suffix' => '</div>',
  );

  // If we have stored values from a previous step, re-create
  // the fields for address and populate them properly.
  if (!empty($form_state['storage']['addresses'])) {
    foreach($form_state['storage']['addresses'] as $key => $values) {
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
    '#submit' => array('form_fun_ahah_more'),
    // We've added the 'ahah' element to this button, telling FormAPI
    // to add its jQuery to the page and initialize it with these settings.
    '#ahah' => array(
      'path' => 'form_fun/ahah_callback',        // The menu path of our callback
      'wrapper' => 'form-fun-addresses-wrapper', // The ID of the AHAH-enabled element
      'method' => 'replace',                     // What jQuery should do to the element
      'effect' => 'slide',                       // The visual effect to use
    ),
  );

  return $form;
}



function form_fun_ahah_submit(&$form, &$form_state) {
  unset($form_state['storage']['addresses']);
  drupal_set_message(t('Your addresses were submitted!'));
  dsm($form_state['values']['addresses']);
}



function form_fun_ahah_more(&$form, &$form_state) {
  $form_state['storage']['addresses'] = $form_state['values']['addresses'];
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
