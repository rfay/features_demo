<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function junkfeature_ctools_plugin_api() {
  module_load_include('inc', 'junkfeature', 'junkfeature.defaults');
  $args = func_get_args();
  return call_user_func_array('_junkfeature_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function junkfeature_strongarm() {
  module_load_include('inc', 'junkfeature', 'junkfeature.defaults');
  $args = func_get_args();
  return call_user_func_array('_junkfeature_strongarm', $args);
}
