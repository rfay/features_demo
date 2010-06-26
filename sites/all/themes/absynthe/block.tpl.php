<?php
// $Id: block.tpl.php,v 1.1 2009/03/18 09:32:52 hoainam12k Exp $
?>
<div id="block-<?php print $block->module .'-'. $block->delta; ?>" class="main">
	<div class="middle">
		<div class="bottom">
<?php if (!empty($block->subject)): ?>
  <h2><?php print $block->subject ?></h2>
<?php endif;?>

  <div class="content"><?php print $block->content ?></div>
		</div>
	</div>
</div>
