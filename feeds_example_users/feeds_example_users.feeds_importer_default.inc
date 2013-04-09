<?php
/**
 * @file
 * feeds_example_users.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function feeds_example_users_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'users';
  $feeds_importer->config = array(
    'name' => 'Users',
    'description' => 'Import users from CSV.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv',
        'direct' => 0,
        'directory' => 'public://users-csv',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          3 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'user',
            'target' => 'name',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'mail',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'pass',
            'target' => 'pass',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['users'] = $feeds_importer;

  return $export;
}
