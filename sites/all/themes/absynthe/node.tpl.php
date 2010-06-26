<?php
// $Id: node.tpl.php,v 1.1 2009/03/18 09:32:52 hoainam12k Exp $
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> mainbg">

<?php print $picture ?>

  <div class="calendar"><small><?php print format_date($node->created, 'custom', 'M'); ?></small> <strong><?php print format_date($node->created, 'custom', 'd'); ?></strong></div>
  <?php if ($page == 0): ?>
  <div class="numbercomments">
  	<?php print '<a href="'.$node_url.'#comments">'.$comment_count.'</a>'; ?>
  </div>
  <?php endif; ?>
  <h1 class="post"><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h1>
	
  <div class="bottombg">
  	<div class="buffer">
		<?php if ($submitted): ?>
        <div class="posted"><?php print $submitted; ?></div>
      	<?php endif; ?>
    	<?php print $content ?>
        <p> <a class="more-link" href="<?php print $node_url ?>">(more...)</a></p>
        <?php if ($taxonomy): ?>
        <div class="postfooter"><span class="tags">Tags: <?php print $terms ?></span></div>
        <?php endif;?>
    </div>
  </div>
</div>