<?php

/*
 * callback function for help page
 */

function islandora_xml_form_builder_states_help_page() {
 $render_array = array();
 $render_array['title'] = array(
   '#prefix' => '<h1>',
   '#markup' => t('Islandora XML Form Builder States'),
   '#postfix' => '</h1>',
 );
 $render_array['introduction_title'] = array(
   '#prefix' => '<h2>',
   '#markup' => t('Introduction & Background'),
   '#postfix' => '</h2>',
 );
 $render_array['introduction'] = array(
   '#prefix' => '<p>',
   '#markup' => t('The Islandora XML Form Builder is an '
       . 'extremely powerful tool for developing XML ingest '
       . 'forms.  Unfortunately the system does not support the '
       . '"#states" function inherent in Drupal 7 core.  In an '
       . 'attempt to remedy this problem, this module modifies '
       . 'the way forms work to add basic support for '
       . '"#states".  While this module has limitations in '
       . 'support of multiple values on a condition, it does '
       . 'extend basic functionality.  This module assumes you '
       . 'know how to use the Islandora XML Form Builder.  If '
       . 'you need to learn how to use the Islandora XML Form '
       . 'Builder, please consult the help for that module.'),
   '#postfix' => '</p>',
 );
 $render_array['implementation'] = array(
   '#prefix' => '<h2>',
   '#markup' => t('Implementation'),
   '#postfix' => '</h2>',
 );
 $render_array['steps'] = array(
   '#theme' => 'item_list',
   '#items' => array(
     array(
       'data' => t('Add a hidden field to the root of the form.'),
       'children' => array(
         t('The hidden field should have a title of '
             . '<em>islandora_states_id</em>'),
         t('The default value may eventually be used for further '
             . 'purposes in this module.  While at this time the '
             . 'field should not have a default value, any default '
             . 'value supplied is currently ignored.'
         ),),
     ),
     array(
       'data' => t('Determine the jQuery selector for the '
           . 'control field.'),
       'children' => array(
         t('In most browsers you can preview the form, right-'
             . 'click on an element and then choose "inspect '
             . 'element".'),
         t('Many people have found more success using a selector '
             . 'such as "<em>:input[name=blah]</em>" selecting '
             . 'by id seems to be unreliable.'),
         t('A full reference for jQuery selectors is available at'
             . '<a href="@url">@url</a>.'
             , array(url('http://api.jquery.com/category/selectors/'))
         ),
       ),
     ),
     'value 2',
     array('data' => 'value 3', 'id' => 'key3', 'class' => array(
         'item-3-class')),
     array(
       'data' => 'value 4',
       'class' => array('item-4-class'),
       'children' => array(
         '4.1',
         '4.2',
         array('data' => '4.3', 'class' => array('list-4-3-class'),
           'children' => array('4.3.1', '4.3.2'))
       ),
     ),
   ),
   '#type' => 'ol',
   '#attributes' => array('class' => 'list-class'),
 );
 return $render_array;
}
