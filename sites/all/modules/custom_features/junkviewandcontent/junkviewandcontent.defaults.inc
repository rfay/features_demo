<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _junkviewandcontent_content_default_fields() {
  $fields = array();

  // Exported field: field_newnumber
  $fields[] = array(
    'field_name' => 'field_newnumber',
    'type_name' => 'page',
    'display_settings' => array(
      'label' => array(
        'format' => 'above',
        'exclude' => 0,
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'number_decimal',
    'required' => '0',
    'multiple' => '0',
    'module' => 'number',
    'active' => '1',
    'prefix' => '',
    'suffix' => '',
    'min' => '',
    'max' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'precision' => '10',
    'scale' => '2',
    'decimal' => '.',
    'widget' => array(
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_newnumber][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'NewNumber',
      'weight' => '31',
      'description' => '',
      'type' => 'number',
      'module' => 'number',
    ),
  );

  // Translatables
  array(
    t('NewNumber'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _junkviewandcontent_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _junkviewandcontent_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer blocks
  $permissions[] = array(
    'name' => 'administer blocks',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}

/**
 * Helper to implementation of hook_strongarm().
 */
function _junkviewandcontent_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'content_extra_weights_page';
  $strongarm->value = array(
    'title' => '-5',
    'body_field' => '0',
    'revision_information' => '20',
    'author' => '20',
    'options' => '25',
    'comment_settings' => '30',
    'menu' => '-2',
    'taxonomy' => '-3',
  );

  $export['content_extra_weights_page'] = $strongarm;
  return $export;
}
