<?php
// $Id: template.php,v 1.2 2010/05/01 01:13:06 hoainam12k Exp $

/**
 * Sets the body-tag class attribute.
 *
 * Adds 'sidebar-left', 'sidebar-right' or 'sidebars' classes as needed.
 */
function phptemplate_body_class($left, $right) {
  if ($left != '' && $right != '') {
    $class = 'sidebars';
  }
  else {
    if ($left != '') {
      $class = 'sidebar-left';
    }
    if ($right != '') {
      $class = 'sidebar-right';
    }
  }

  if (isset($class)) {
    print ' class="'. $class .'"';
  }
}

/**
 * Return a themed breadcrumb trail.
 *
 * @param $breadcrumb
 *   An array containing the breadcrumb links.
 * @return a string containing the breadcrumb output.
 */
function phptemplate_breadcrumb($breadcrumb) {
  if (!empty($breadcrumb)) {
    return '<div class="breadcrumb">'. implode(' › ', $breadcrumb) .'</div>';
  }
}

/**
 * Allow themable wrapping of all comments.
 */
function phptemplate_comment_wrapper($content, $node) {
  if (!$content || $node->type == 'forum') {
    return '<div id="comments">'. $content .'</div>';
  }
  else {
    return '<div id="comments"><h2 class="comments">'. t('Comments') .'</h2>'. $content .'</div>';
  }
}

/**
 * Override or insert PHPTemplate variables into the templates.
 */
function phptemplate_preprocess_page(&$vars) {
  $vars['tabs2'] = menu_secondary_local_tasks();


}

/**
 * Returns the rendered local tasks. The default implementation renders
 * them as tabs. Overridden to split the secondary tasks.
 *
 * @ingroup themeable
 */
function phptemplate_menu_local_tasks() {
  return menu_primary_local_tasks();
}

function phptemplate_comment_submitted($comment) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $comment),
      '!datetime' => format_date($comment->timestamp)
    ));
}

function phptemplate_node_submitted($node) {
  return t('!datetime — !username',
    array(
      '!username' => theme('username', $node),
      '!datetime' => format_date($node->created),
    ));
}


function absynthe_preprocess_search_theme_form(&$vars, $hook) {
   // Modify elements of the search form
  $vars['form']['search_theme_form']['#title'] = t('');
 
  // Set a default value for the search box
  $vars['form']['search_theme_form']['#value'] = t('');
 
  // Add a custom class to the search box
  $vars['form']['search_theme_form']['#attributes'] = array('class' => t('cleardefault'));
 
  // Change the text on the submit button
  $vars['form']['submit']['#value'] = t('Search');
 
  // Rebuild the rendered version (search form only, rest remains unchanged)
  unset($vars['form']['search_theme_form']['#printed']);
  $vars['search']['search_theme_form'] = drupal_render($vars['form']['search_theme_form']);
 
  // Rebuild the rendered version (submit button, rest remains unchanged)
  unset($vars['form']['submit']['#printed']);
  $vars['search']['submit'] = drupal_render($vars['form']['submit']);
 
  // Collect all form elements to make it easier to print the whole form.
  $vars['search_form'] = implode($vars['search']);
}

function phptemplate_preprocess_node(&$vars) {
  // Build array of handy node classes
  $node_classes = array();
  $node_classes[] = $vars['zebra'];                                      // Node is odd or even
  $node_classes[] = (!$vars['node']->status) ? 'node-unpublished' : '';  // Node is unpublished
  $node_classes[] = ($vars['sticky']) ? 'sticky' : '';                   // Node is sticky
  $node_classes[] = (isset($vars['node']->teaser)) ? 'teaser' : 'full-node';    // Node is teaser or full-node
  $node_classes[] = 'node-type-'. $vars['node']->type;                   // Node is type-x, e.g., node-type-page
  $node_classes = array_filter($node_classes);                           // Remove empty elements
  $vars['node_classes'] = implode(' ', $node_classes);                   // Implode class list with spaces
  
  // Node Theme Settings
 
  // Node Links
  if (isset($vars['node']->links['node_read_more'])) {
    $node_content_type = (theme_get_setting('readmore_enable_content_type') == 1) ? $vars['node']->type : 'default';
    $vars['node']->links['node_read_more'] = array(
      'title' => _themesettings_link(
      theme_get_setting('readmore_prefix_'. $node_content_type),
      theme_get_setting('readmore_suffix_'. $node_content_type),
      t(theme_get_setting('readmore_'. $node_content_type)),
      'node/'. $vars['node']->nid,
      array(
        'attributes' => array('title' => t(theme_get_setting('readmore_title_'. $node_content_type))), 
        'query' => NULL, 'fragment' => NULL, 'absolute' => FALSE, 'html' => TRUE
        )
      ),
      'attributes' => array('class' => 'readmore-item'),
      'html' => TRUE,
    );
  }
  if (isset($vars['node']->links['comment_add'])) {
    $node_content_type = (theme_get_setting('comment_enable_content_type') == 1) ? $vars['node']->type : 'default';
    if ($vars['teaser']) {
      $vars['node']->links['comment_add'] = array(
        'title' => _themesettings_link(
        theme_get_setting('comment_add_prefix_'. $node_content_type),
        theme_get_setting('comment_add_suffix_'. $node_content_type),
        t(theme_get_setting('comment_add_'. $node_content_type)),
        "comment/reply/".$vars['node']->nid,
        array(
          'attributes' => array('title' => t(theme_get_setting('comment_add_title_'. $node_content_type))), 
          'query' => NULL, 'fragment' => 'comment-form', 'absolute' => FALSE, 'html' => TRUE
          )
        ),
        'attributes' => array('class' => 'comment-add-item'),
        'html' => TRUE,
      );
    }
    else {
      $vars['node']->links['comment_add'] = array(
        'title' => _themesettings_link(
        theme_get_setting('comment_node_prefix_'. $node_content_type),
        theme_get_setting('comment_node_suffix_'. $node_content_type),
        t(theme_get_setting('comment_node_'. $node_content_type)),
        "comment/reply/".$vars['node']->nid,
        array(
          'attributes' => array('title' => t(theme_get_setting('comment_node_title_'. $node_content_type))), 
          'query' => NULL, 'fragment' => 'comment-form', 'absolute' => FALSE, 'html' => TRUE
          )
        ),
        'attributes' => array('class' => 'comment-node-item'),
        'html' => TRUE,
      );
    }
  }
  if (isset($vars['node']->links['comment_new_comments'])) {
    $node_content_type = (theme_get_setting('comment_enable_content_type') == 1) ? $vars['node']->type : 'default';
    $vars['node']->links['comment_new_comments'] = array(
      'title' => _themesettings_link(
        theme_get_setting('comment_new_prefix_'. $node_content_type),
        theme_get_setting('comment_new_suffix_'. $node_content_type),
        format_plural(
          comment_num_new($vars['node']->nid),
          t(theme_get_setting('comment_new_singular_'. $node_content_type)),
          t(theme_get_setting('comment_new_plural_'. $node_content_type))
        ),
        "node/".$vars['node']->nid,
        array(
          'attributes' => array('title' => t(theme_get_setting('comment_new_title_'. $node_content_type))), 
          'query' => NULL, 'fragment' => 'new', 'absolute' => FALSE, 'html' => TRUE
        )
      ),
      'attributes' => array('class' => 'comment-new-item'),
      'html' => TRUE,
    );
  }
  if (isset($vars['node']->links['comment_comments'])) {
    $node_content_type = (theme_get_setting('comment_enable_content_type') == 1) ? $vars['node']->type : 'default';
    $vars['node']->links['comment_comments'] = array(
      'title' => _themesettings_link(
        theme_get_setting('comment_prefix_'. $node_content_type),
        theme_get_setting('comment_suffix_'. $node_content_type),
        format_plural(
          comment_num_all($vars['node']->nid),
          t(theme_get_setting('comment_singular_'. $node_content_type)),
          t(theme_get_setting('comment_plural_'. $node_content_type))
        ),
        "node/".$vars['node']->nid,
        array(
          'attributes' => array('title' => t(theme_get_setting('comment_title_'. $node_content_type))), 
          'query' => NULL, 'fragment' => 'comments', 'absolute' => FALSE, 'html' => TRUE
        )
      ),
      'attributes' => array('class' => 'comment-item'),
      'html' => TRUE,
    );
  }
  $vars['links'] = theme('links', $vars['node']->links, array('class' => 'links inline')); 
}

function _themesettings_link($prefix, $suffix, $text, $path, $options) {
  return $prefix . (($text) ? l($text, $path, $options) : '') . $suffix;
}

/**
 * Generates IE Fix
 */
function phptemplate_get_ie_fix() {
	$iefix = '<!--[if lte IE 6]>';
	$iefix .= '<style type="text/css">';
	$iefix .= '.feed-icon {margin-top: 31px}';
	$iefix .= '</style>';
	$iefix .= '<script type="text/javascript" src="'. base_path() . path_to_theme() .'/js/DD_belatedPNG.js"></script>';
	$iefix .= '<script type="text/javascript" src="'. base_path() . path_to_theme() .'/js/styleie6.js"></script>';
	$iefix .= '<![endif]-->';
	return $iefix;
}

?>