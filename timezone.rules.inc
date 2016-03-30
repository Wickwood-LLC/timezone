<?php

/**
 * Implements of hook_rules_action_info().
 */
function timezone_rules_action_info() {
  return array(
    'timezone_get_label' => array(
      'base' => 'timezone_get_label',
      'label' => t('Get timezone label'),
      'group' => t('Timezone'),
      'parameter' => array(
        'timezone' => array('type' => 'text', 'label' => t('Timezone name')),
      ),
      'access callback' => 'feeds_rules_access_callback',
      'provides' => array(
        'timezone_label' => array(
          'type' => 'text',
          'label' => t('Timezone label'),
        ),
      ),
    ),
  );
}

/**
 * Rules action callback for timezone_get_label
 */
function timezone_get_label($timezone) {
  $zonelist = timezone_get_configured_timezones();
  $label = isset($zonelist[$timezone]) ? $zonelist[$timezone] : $timezone;
  return array('timezone_label' => $label);
}
