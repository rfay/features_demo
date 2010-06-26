<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function development_tools_ctools_plugin_api() {
  module_load_include('inc', 'development_tools', 'development_tools.defaults');
  $args = func_get_args();
  return call_user_func_array('_development_tools_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function development_tools_strongarm() {
  module_load_include('inc', 'development_tools', 'development_tools.defaults');
  $args = func_get_args();
  return call_user_func_array('_development_tools_strongarm', $args);
}
