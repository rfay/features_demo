<?php 
// $Id$
?><!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language ?>" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>">
  <head>
    <title><?php print $head_title ?></title>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
	<?php print phptemplate_get_ie_fix();?>
  </head>
  <body <?php if ($is_front) { ?>id="home"<?php } else { ?>id="interior"<?php } ?>>
<!-- Layout -->
<div id="container">
	<?php print $feed_icons ?>
    <div id="header" class="clearfix">
        <?php
		  // Prepare header
		  $site_fields = array();
		  if ($site_name) {
			$site_fields[] = check_plain($site_name);
		  }
		  if ($site_slogan) {
			$site_fields[] = check_plain($site_slogan);
		  }
		  $site_title = implode(' ', $site_fields);
		  if ($site_fields) {
			$site_fields[0] = '<span>'. $site_fields[0] .'</span>';
		  }
		  $site_html = implode(' ', $site_fields);
		?>
		<h1><a href="<?php print check_url($front_page);?>" title="<?php print $site_title;?>"><?php 
			print $site_name;
			if ($site_slogan) { print ' <span>'.$site_slogan.'</span>';}
			?></a></h1>
    
		<?php if (isset($primary_links)) : ?>
		  <?php print theme('links', $primary_links, array('id' => 'nav')) ?>
		<?php endif; ?>
		<?php if ($search_box): ?><div class="searchbox"><?php print $search_box ?></div><?php endif; ?>
    </div>