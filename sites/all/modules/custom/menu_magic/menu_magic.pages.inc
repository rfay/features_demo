<?php
// $Id$

/**
 * @file
 * This file contains page callbacks for menu_magic.module.
 */

/**
 * Page callback for the user tab.
 */
function menu_magic_user_page($account, $arg1, $arg2, $arg3) {
  return t('!name believes in magic!', array('!name' => "horrible XSS javascript here!"));
}
