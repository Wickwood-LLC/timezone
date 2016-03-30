<?php

/**
 * Implements of hook_rules_action_info().
 */
function timezone_rules_action_info() {
  return array(
    'timezone_get_familiar_name' => array(
      'base' => 'timezone_get_familiar_name',
      'label' => t('Get timezone familiar name'),
      'group' => t('Timezone'),
      'parameter' => array(
        'timezone' => array('type' => 'text', 'label' => t('Timezone name')),
      ),
      'access callback' => 'feeds_rules_access_callback',
      'provides' => array(
        'timezone_familiar_name' => array(
          'type' => 'text',
          'label' => t('Timezone familiar name'),
        ),
      ),
    ),
  );
}

/**
 * Rules action callback for timezone_get_familiar_name
 */
function timezone_get_familiar_name($timezone) {
  $zonelist = timezone_get_configured_timezones();
  $familiar_name = isset($zonelist[$timezone]) ? $zonelist[$timezone] : $timezone;
  return array('timezone_familiar_name' => $familiar_name);
}
