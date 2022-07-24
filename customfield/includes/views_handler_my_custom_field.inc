<?php
/**
 * @file
 * Custom views handler definition.
 *
 * Place this code in
 * /sites/all/[custom_module_name]/includes/views_handler_my_custom_field.inc
 */

/**
 * Custom handler class.
 *
 * @ingroup views_field_handlers
 */
class views_handler_my_custom_field extends views_handler_field {
  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */

 function query() {
    // public $r = t('xxx');
  }

  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    // dpm($options);
    return $options;
  }

  /**
   * {@inheritdoc}
   *
   * Make changes to the field settings form seen by the end user when adding
   * your field.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }
  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */

  function render($values) {
      $r =  return_field_value($values);
      if($r == 0) {
        return 'show';
      }
      if($r != 0) {
        return 'hide';
      }
    }
  }

function return_field_value($values){

  global $user;
  $uuid = $user->uid;
  $edad = 'edad_paciente'. $uuid;
  $genero = 'genero_paciente' . $uuid;
  $edad_paciente = variable_get($edad);
  $genero_paciente = variable_get($genero);

  $bool = TRUE;
  $bool_edad = TRUE;
  $bool_genero = TRUE;
  $node = $values->_field_data['nid']['entity'];

  $min = $node->field_estudio_valor_minimo_dias[LANGUAGE_NONE][0]['value'];
  $max = $node->field_estudio_valor_maximo_dias[LANGUAGE_NONE][0]['value'];
  $genero_estudio = $node->field_estudio_genero[LANGUAGE_NONE][0]['value'];

  if($edad_paciente >= $min AND $edad_paciente <= $max) {
    $bool_edad = FALSE;
  }
  else {
    $bool_edad = TRUE;
  }

  if($genero_estudio == 2 ){
    $bool_genero = FALSE;
  }
  if($genero_estudio == $genero_paciente){
    $bool_genero = FALSE;
  }

  if($bool_edad == FALSE && $bool_genero == FALSE) {
    $bool = FALSE;
  } else {
    $bool = TRUE;
  }

  return $bool;
}
