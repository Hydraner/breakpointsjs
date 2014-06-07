<?php

/**
 * @file
 * Breakpoints JS Libraries API Implementations.
 */

/**
 * Implements hook_libraries_info().
 */
function breakpoints_js_libraries_info() {
  $libraries = array();

  $libraries['enquire'] = array(
    'name' => 'enquire.js',
    'vendor url' => 'http://wicky.nillia.ms/enquire.js/',
    'download url' => 'https://github.com/WickyNilliams/enquire.js/zipball/master',
    'version callback' => 'breakpoints_js_libraries_enquire_version',
    'files' => array(
      'js' => array(
        'dist/enquire.min.js' => array(
          'every_page' => TRUE,
        ),
      ),
    ),
  );

  $libraries['matchMedia'] = array(
    'name' => 'matchMedia',
    'vendor url' => 'https://github.com/paulirish/matchMedia.js/',
    'download url' => 'https://github.com/paulirish/matchMedia.js/zipball/master',
    'version callback' => 'breakpoints_js_libraries_matchmedia_version',
    'files' => array(
      'js' => array(
        'matchMedia.js' => array(
          'every_page' => TRUE,
        ),
        'matchMedia.addListener.js' => array(
          'every_page' => TRUE,
        ),
      ),
    ),
  );

  return $libraries;
}

/**
 * Callback for enquire.js library version.
 */
function breakpoints_js_libraries_enquire_version($library = array()) {

  $package_json = libraries_get_path('enquire') . '/package.json';
  $decoded_json = drupal_json_decode(file_get_contents($package_json, TRUE));

  return empty($decoded_json['version']) ? NULL : $decoded_json['version'];
}

/**
 * Callback for matchMedia library version.
 */
function breakpoints_js_libraries_matchmedia_version($library = array()) {

  $bower_json = libraries_get_path('matchMedia') . '/bower.json';
  $decoded_json = drupal_json_decode(file_get_contents($bower_json, TRUE));

  return empty($decoded_json['version']) ? NULL : $decoded_json['version'];
}
