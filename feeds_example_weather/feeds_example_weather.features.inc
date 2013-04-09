<?php
/**
 * @file
 * feeds_example_weather.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feeds_example_weather_node_info() {
  $items = array(
    'weather_observation' => array(
      'name' => t('Weather observation'),
      'base' => 'node_content',
      'description' => t('Single weather observation reading.'),
      'has_title' => '1',
      'title_label' => t('Place'),
      'help' => '',
    ),
  );
  return $items;
}
