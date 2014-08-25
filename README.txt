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

Islandora XML Form Builder States

Introduction & Background
===========================
The Islandora XML Form Builder is an extremely powerful tool for developing XML ingest forms. Unfortunately the system does not support the "#states" function inherent in Drupal 7 core. In an attempt to remedy this problem, this module modifies the way forms work to add basic support for "#states". While this module has limitations in support of multiple values on a condition, it does extend basic functionality. This module assumes you know how to use the Islandora XML Form Builder. If you need to learn how to use the Islandora XML Form Builder, please consult the help for that module.

Implementation
================
1) Add a hidden field to the root of the form.
   -------------------------------------------
   The hidden field should have a title of islandora_states_id
   The value may eventually be used for further purposes in this module.
   At this time the value should be either debug or not have a value, any value
   other than debug is currently ignored.  If the value is set to debug then
   the module will display a list of the form fields to reference for the
   required/optional states.

2) Determine the jQuery selector for the control field.
   ----------------------------------------------------
   In most browsers you can preview the form, right-click on an element and
   then choose "inspect element".  Many people have found more success using a
   selector such as ":input[name=blah]" selecting by id seems to be unreliable.
   A full reference for jQuery selectors is available at
   http://api.jquery.com/category/selectors/.

3) Add a new User Data entry on the More Advanced Controls tab.
   ------------------------------------------------------------
   The key of the entry should be islandora_states_STATE where STATE is one of
   the following:
      These are valid states for elements:
            enabled
            disabled
            required
            optional
            visible
            invisible
            checked
            unchecked
            expanded
            collapsed
      These states are valid but may not be implemented by Drupal core:
            relevant
            irrelevant
            valid
            invalid
            touched
            untouched
            readwrite
            readonly

   The value of the entry should be a JSON string.
      The general form of the JSON string is {"selector":{"condition":"test"}}
         "selector" is the jQuery selector identified above.
         "condition" is one of the following:
            These are valid conditions for elements:
                  empty
                  filled
                  checked
                  unchecked
                  expanded
                  collapsed
                  value
            These conditions are valid but may not be implemented by Drupal core:
                  relevant
                  irrelevant
                  valid
                  invalid
                  touched
                  untouched
                  readwrite
                  readonly
         "test" is the value that applies to the condition.
                  Such as true or a value.
      By changing this JSON structure you may also be able to implement more
      complicated conditions.
4) To add multiple tests on the same selector use:
   [[{"selector":{condition1:test1}},{"selector":{condition2:test2}}...]]
5) If the STATE is either optional or required then the jQuery string must
   contain 'name="key"', 'id="key"', or '#"key"'. Without this, it will not
   be truly required,even though it will be marked with a red *.
6) In addition, if the STATE is either optional or required then the Root(form)
   validate attribute (on the More Advanced Controls tab) should be set to
   islandora_xml_form_builder_states_required_field_validation. Without this,
   optional/required fields will not be truly required, even though marked with
   a red *.