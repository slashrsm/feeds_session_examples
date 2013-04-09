<?php
/**
 * @file
 * feeds_example_rss.features.inc
 */

/**
 * Implements hook_node_info().
 */
function feeds_example_rss_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'base' => 'node_content',
      'description' => t('RSS Feed that is imported to this site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'rss_article' => array(
      'name' => t('RSS article'),
      'base' => 'node_content',
      'description' => t('Article imported from RSS.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
