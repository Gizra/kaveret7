<?php
 /*
 * shows a members address and offline contact details
 * variables:
 *
 * $phone
 * $email
 * $address, a multiline adress
 * $responsibility, a profile field
 * $locality, a code such as a postal code
 * $name, username (themed)
 */
?>
<div class = "offline-contact">
  <strong><?php print $name; ?></strong>
  <?php print $address; ?>
  <?php print $locality; ?>
</div>
