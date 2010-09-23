<?php

/**
 * Implementation of hook_content_default_fields().
 */
function junkviewandcontent_content_default_fields() {
  module_load_include('inc', 'junkviewandcontent', 'junkviewandcontent.defaults');
  $args = func_get_args();
  return call_user_func_array('_junkviewandcontent_content_default_fields', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function junkviewandcontent_ctools_plugin_api() {
  module_load_include('inc', 'junkviewandcontent', 'junkviewandcontent.defaults');
  $args = func_get_args();
  return call_user_func_array('_junkviewandcontent_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_node_info().
 */
function junkviewandcontent_node_info() {
  module_load_include('inc', 'junkviewandcontent', 'junkviewandcontent.features.node');
  $args = func_get_args();
  return call_user_func_array('_junkviewandcontent_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function junkviewandcontent_user_default_permissions() {
  module_load_include('inc', 'junkviewandcontent', 'junkviewandcontent.defaults');
  $args = func_get_args();
  return call_user_func_array('_junkviewandcontent_user_default_permissions', $args);
}

/**
 * Implementation of hook_strongarm().
 */
function junkviewandcontent_strongarm() {
  module_load_include('inc', 'junkviewandcontent', 'junkviewandcontent.defaults');
  $args = func_get_args();
  return call_user_func_array('_junkviewandcontent_strongarm', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function junkviewandcontent_views_default_views() {
  module_load_include('inc', 'junkviewandcontent', 'junkviewandcontent.features.views');
  $args = func_get_args();
  return call_user_func_array('_junkviewandcontent_views_default_views', $args);
}
