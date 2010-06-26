<?php 
// $Id: page.tpl.php,v 1.2 2010/05/01 01:13:06 hoainam12k Exp $
include drupal_get_path('theme', 'absynthe') . '/ab_header.php';?>
    <div id="main" class="clearfix">
    	<div id="content">
        	<div class="inner">
                <div class="nonenodepage"><div class="nnbottom">
                  <?php if ($mission): print '<div id="mission">'. $mission .'</div>'; endif; ?>
                  <?php if ($tabs): print '<div id="tabs-wrapper" class="clear-block">'; endif; ?>
                  <?php if ($title): print '<h2'. ($tabs ? ' class="with-tabs"' : '') .'>'. $title .'</h2>'; endif; ?>
                  <?php if ($tabs): print '<ul class="tabs primary">'. $tabs .'</ul></div>'; endif; ?>
                  <?php if ($tabs2): print '<ul class="tabs secondary">'. $tabs2 .'</ul>'; endif; ?>
                  <?php if ($show_messages && $messages): print $messages; endif; ?>
                  <?php print $content ?>
                </div></div>
            </div>
        </div>
        <div id="sidebar">
        	<?php print $right ?>
        </div>
    </div>
</div> 
<?php include drupal_get_path('theme', 'absynthe') . '/ab_footer.php';?>