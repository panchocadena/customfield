<?php
module_load_include('inc','customfield', '/includes/views_handler_my_custom_field');
/**
 * Implements hook_views_data().
 */
function customfield_views_data() {
  $data['customfield']['table']['group'] = t('Custom field');
  $data['customfield']['table']['join'] = array(
    // Exist in all views.
    '#global' => array(),
  );

  $data['customfield']['my_custom_field'] = array(
    'title' => t('My custom field'),
    'help' => t('My custom field displays the word "Some custom markup".'),
    'field' => array(
      'handler' => 'views_handler_my_custom_field',
    ),
  );

  return $data;
}
