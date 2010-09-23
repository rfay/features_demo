<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function basic_settings_ctools_plugin_api() {
  module_load_include('inc', 'basic_settings', 'basic_settings.defaults');
  $args = func_get_args();
  return call_user_func_array('_basic_settings_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function basic_settings_strongarm() {
  module_load_include('inc', 'basic_settings', 'basic_settings.defaults');
  $args = func_get_args();
  return call_user_func_array('_basic_settings_strongarm', $args);
}
