<?php
/*
 * COPYRIGHT © 2014 
 * MICHIGAN STATE UNIVERSITY BOARD OF TRUSTEES
 * ALL RIGHTS RESERVED
 * 
 * PERMISSION IS GRANTED TO USE, COPY, CREATE DERIVATIVE WORKS AND REDISTRIBUTE
 * THIS SOFTWARE AND SUCH DERIVATIVE WORKS FOR ANY PURPOSE, SO LONG AS THE NAME
 * OF MICHIGAN STATE UNIVERSITY IS NOT USED IN ANY ADVERTISING OR PUBLICITY
 * PERTAINING TO THE USE OR DISTRIBUTION OF THIS SOFTWARE WITHOUT SPECIFIC,
 * WRITTEN PRIOR AUTHORIZATION.  IF THE ABOVE COPYRIGHT NOTICE OR ANY OTHER
 * IDENTIFICATION OF MICHIGAN STATE UNIVERSITY IS INCLUDED IN ANY COPY OF ANY
 * PORTION OF THIS SOFTWARE, THEN THE DISCLAIMER BELOW MUST ALSO BE INCLUDED.
 * 
 * THIS SOFTWARE IS PROVIDED AS IS, WITHOUT REPRESENTATION FROM MICHIGAN STATE
 * UNIVERSITY AS TO ITS FITNESS FOR ANY PURPOSE, AND WITHOUT WARRANTY BY
 * MICHIGAN STATE UNIVERSITY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING
 * WITHOUT LIMITATION THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE. THE MICHIGAN STATE UNIVERSITY BOARD OF TRUSTEES SHALL
 * NOT BE LIABLE FOR ANY DAMAGES, INCLUDING SPECIAL, INDIRECT, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, WITH RESPECT TO ANY CLAIM ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OF THE SOFTWARE, EVEN IF IT HAS BEEN OR IS HEREAFTER
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * 
 * Module originally created by Kevin Finkenbinder
 * June 1, 2014 - August 25, 2014
 * (c) Michigan State University Board of Trustees
 * Licensed under GNU General Public License (GPL) Version 2.
 */

/*
 * callback function for help page
 */

function islandora_xml_form_builder_states_help_page() {
  drupal_add_css(
      '.MSUL-four-column-list{width:100%; float:left;}', 'inline');
  drupal_add_css(
      '.MSUL-four-column-list li{width:20%; min-width:9em; float:left; display:inline}', 'inline');
  $render_array = array();
  $render_array['title'] = array(
    '#prefix' => '<h1>',
    '#markup' => t('Islandora XML Form Builder States'),
    '#suffix' => '</h1>',
  );
  $render_array['introduction_title'] = array(
    '#prefix' => '<h2>',
    '#markup' => t('Introduction & Background'),
    '#suffix' => '</h2>',
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
    '#suffix' => '</p>',
  );
  $render_array['implementation'] = array(
    '#prefix' => '<h2>',
    '#markup' => t('Implementation'),
    '#suffix' => '</h2>',
  );

  $valid_states = array(
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => array('class' => 'MSUL-four-column-list'),
    '#items' => array(
      t('enabled'),
      t('disabled'),
      t('required'),
      t('optional'),
      t('visible'),
      t('invisible'),
      t('checked'),
      t('unchecked'),
      t('expanded'),
      t('collapsed'),
    ),
  );
  $valid_conditions = array(
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => array('class' => 'MSUL-four-column-list'),
    '#items' => array(
      t('empty'),
      t('filled'),
      t('checked'),
      t('unchecked'),
      t('expanded'),
      t('collapsed'),
      t('value'),
    ),
  );
  $unemplemented_states = array(
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => array('class' => 'MSUL-four-column-list'),
    '#items' => array(
      t('relevant'),
      t('irrelevant'),
      t('valid'),
      t('invalid'),
      t('touched'),
      t('untouched'),
      t('readwrite'),
      t('readonly'),
    ),
  );
  $unemplemented_conditions = array(
    '#theme' => 'item_list',
    '#type' => 'ul',
    '#attributes' => array('class' => 'MSUL-four-column-list'),
    '#items' => array(
      t('relevant'),
      t('irrelevant'),
      t('valid'),
      t('invalid'),
      t('touched'),
      t('untouched'),
      t('readwrite'),
      t('readonly'),
    ),
  );
  $render_array['steps'] = array(
    '#theme' => 'item_list',
    '#type' => 'ol',
    '#items' => array(
      array(
        'data' => t('Add a hidden field to the root of the form.'),
        'children' => array(
          t('The hidden field should have a title of '
              . '<em>islandora_states_id</em>'),
          t('The <em>value</em> may eventually be used for further '
              . 'purposes in this module.  At this time the value '
              . 'should be either <em>debug</em> or not have a '
              . 'value, any value other than debug is currently '
              . 'ignored.'),
          t('If the value is set to <em>debug</em> then the '
              . 'module will display a list of the form fields '
              . 'to reference for the required/optional states.'),
        ),
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
          t('A full reference for jQuery selectors is available '
              . 'at <a href="@url">'
              . 'http://api.jquery.com/category/selectors/</a>.'
              , array("@url" => url('http://api.jquery.com/category/selectors/'))
          ),
        ),
      ),
      array(
        'data' => t('Add a new User Data entry on the <em>More '
            . 'Advanced Controls</em> tab.'),
        'children' => array(
          array(
            t('The key of the entry should be islandora_states_'
                . '<em><strong>STATE</strong></em> where '
                . '<em><strong>STATE</strong></em> is one of the '
                . 'following:<br />'
                . '<em>These are valid states for elements:</em>'
                . '!valid_states'
                . '<br clear=all/><em>These states are valid but may not be '
                . 'implemented by Drupal core:</em><br />'
                . '!unemplemented_states', array(
              '!valid_states' => drupal_render(
                  $valid_states),
              '!unemplemented_states' => drupal_render(
                  $unemplemented_states)
                )
            ),
          ),
          array(
            'data' => t('The value of the entry should be a JSON string.'),
            'children' => array(
              t('The general form of the JSON string is '
                  . '{"<strong>selector</strong>":'
                  . '{"<strong>condition</strong>":'
                  . '"<strong>test</strong>"}}'),
              t('<strong>selector</strong> is the jQuery '
                  . 'selector identified above.'),
              t('<strong>condition</strong> is one of the '
                  . 'following:<br /><em>These are valid '
                  . 'conditions for elements:'
                  . '</em>!valid_conditions<br clear=all/>'
                  . '<em>These conditions are valid but may not '
                  . 'be implemented by Drupal core:</em><br />'
                  . '!unemplemented_conditions', array(
                '!valid_conditions' => drupal_render(
                    $valid_conditions),
                '!unemplemented_conditions' => drupal_render(
                    $unemplemented_conditions)
                  )
              ),
              t('<strong>test</strong> is the value that applies '
                  . 'to the condition.  Such as true or a value.'),
              array(
                'data' => t('<em>By changing this JSON structure you may '
                    . 'also be able to implement more complicated '
                    . 'conditions.</em>'),
                'children' => array(
                  t('To add multiple tests on the same '
                      . 'selector use: <em>[[{"<strong>selector</strong>":{<strong>condition1</strong>:<strong>test1</strong>}},{"<strong>selector</strong>":{<strong>condition2</strong>:<strong>test2</strong>}}...]]</em>'),
                ),
              ),
              t('If the STATE is either <em>optional</em> or '
                  . '<em>required</em> then the jQuery string '
                  . 'must contain \'name=<strong>"key"</strong>\', '
                  . '\'id=<strong>"key"</strong>\', or '
                  . '\'#<strong>"key"</strong>\'. Without this, '
                  . 'it will not be truly required,even though it '
                  . 'will be marked with a red *.'),
              t('In addition, if the STATE is either '
                  . '<em>optional</em> or <em>required</em> then '
                  . 'the Root(form) validate attribute (on the '
                  . '<em>More Advanced Controls</em> tab) should '
                  . 'be set to <em>islandora_xml_form_builder_'
                  . 'states_required_field_validation</em>.  '
                  . 'Without this, optional/required fields will '
                  . 'not be truly required, even though marked '
                  . 'with a red *.'),
            ),
          ),
        ),
      ),
    ),
  );
  return $render_array;
}
