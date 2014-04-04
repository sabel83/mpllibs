# mpllibs::metaparse reference

## Table of contents

## Parsers and combinators provided by the library

* [accept_when](accept_when.html)
* [alphanum](alphanum.html)
* [always](always.html)
* [always_c](always_c.html)
* [any](any.html)
* [any1](any1.html)
* [any_one_of](any_one_of.html)
* [any_one_of1](any_one_of1.html)
* [change_error_message](change_error_message.html)
* [digit](digit.html)
* [digit_val](digit_val.html)
* [empty](empty.html)
* [entire_input](entire_input.html)
* [except](except.html)
* [fail](fail.html)
* [first_of](first_of.html)
* [foldl](foldl.html)
* [foldl1](foldl1.html)
* [foldlp](foldlp.html)
* [foldr](foldr.html)
* [foldr1](foldr1.html)
* [foldrp](foldrp.html)
* [grammar](grammar.html)
* [if_](if_.html)
* [int_](int_.html)
* [iterate](iterate.html)
* [iterate_c](iterate_c.html)
* [keyword](keyword.html)
* [last_of](last_of.html)
* [letter](letter.html)
* [lit](lit.html)
* [lit_c](lit_c.html)
* [look_ahead](look_ahead.html)
* [middle_of](middle_of.html)
* [nth_of](nth_of.html)
* [nth_of_c](nth_of_c.html)
* [one_char](one_char.html)
* [one_char_except](one_char_except.html)
* [one_char_except_c](one_char_except_c.html)
* [one_of](one_of.html)
* [one_of_c](one_of_c.html)
* [range](range.html)
* [range_c](range_c.html)
* [return_](return_.html)
* [sequence](sequence.html)
* [space](space.html)
* [spaces](spaces.html)
* [token](token.html)
* [transform](transform.html)

## Compile-time data structures and values

### Result of parsing

* [get_message](get_message.html)
* [get_position](get_position.html)
* [get_remaining](get_remaining.html)
* [get_result](get_result.html)
* [is_error](is_error.html)

### Source position

* [get_col](get_col.html)
* [get_line](get_line.html)
* [get_prev_char](get_prev_char.html)
* [next_char](next_char.html)
* [next_line](next_line.html)
* [source_position](source_position.html)
* [source_position_tag](source_position_tag.html)
* [start](start.html)

## String

* [string](string.html)
* [string_tag](string_tag.html)
* [MPLLIBS_STRING](MPLLIBS_STRING.html)

## Errors

* [digit_expected](digit_expected.html)
* [end_of_input_expected](end_of_input_expected.html)
* [index_out_of_range](index_out_of_range.html)
* [letter_expected](letter_expected.html)
* [literal_expected](literal_expected.html)
* [none_of_the_expected_cases_found](none_of_the_expected_cases_found.html)
* [unexpected_character](unexpected_character.html)
* [unexpected_end_of_input](unexpected_end_of_input.html)
* [whitespace_expected](whitespace_expected.html)

## Tags

* [accept_tag](accept_tag.html)
* [fail_tag](fail_tag.html)
* [parser_tag](parser_tag.html)
* [source_position_tag](source_position_tag.html)

## Metafunctions and metafunction classes

* [build_parser](build_parser.html)
* [unless_error](unless_error.html)

## Utilities

* [debug_parsing_error](debug_parsing_error.html)
* [MPLLIBS_DEFINE_ERROR](MPLLIBS_DEFINE_ERROR.html)

Metaparse uses a number of general purpose metafunctions and metafunction
classes.

* [digit_to_int](digit_to_int.html)
* [digit_to_int_c](digit_to_int_c.html)
* [int_to_digit](int_to_digit.html)
* [int_to_digit_c](int_to_digit_c.html)
* [in_range](in_range.html)
* [in_range_c](in_range_c.html)
* [is_digit](is_digit.html)
* [is_lcase_letter](is_lcase_letter.html)
* [is_letter](is_letter.html)
* [is_ucase_letter](is_ucase_letter.html)
* [is_whitespace](is_whitespace.html)
* [is_whitespace_c](is_whitespace_c.html)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


