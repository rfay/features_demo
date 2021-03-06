<?php
// $Id: theme.inc,v 1.1.2.1 2010/02/03 01:18:58 merlinofchaos Exp $

/**
 * @file
 * Plugin to provide access control based on user themeission strings.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Current theme"),
  'description' => t('Control access by checking which theme is in use.'),
  'callback' => 'ctools_theme_ctools_access_check',
  'default' => array('theme' => variable_get('theme_default', 'garland')),
  'settings form' => 'ctools_theme_ctools_access_settings',
  'summary' => 'ctools_theme_ctools_access_summary',
);

/**
 * Settings form for the 'by theme' access plugin
 */
function ctools_theme_ctools_access_settings(&$form, &$form_state, $conf) {
  $themes = array();
  foreach (list_themes() as $key => $theme) {
    $themes[$key] = $theme->info['name'];
  }

  $form['settings']['theme'] = array(
    '#type' => 'select',
    '#options' => $themes,
    '#title' => t('Themes'),
    '#default_value' => $conf['theme'],
    '#description' => t('This will only be accessed if the current theme is the selected theme.'),
  );
}

/**
 * Check for access.
 */
function ctools_theme_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context->data)) {
    return FALSE;
  }
  return $conf['theme'] == $GLOBALS['theme'];
}

/**
 * Provide a summary description based upon the checked roles.
 */
function ctools_theme_ctools_access_summary($conf, $context) {
  if (!isset($conf['theme'])) {
    return t('Error, unset theme');
  }
  $themes = list_themes();

  return t('Current theme is "@theme"', array('@theme' => $themes[$conf['theme']]->info['name']));
}
