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
* [return_](return_.html)
* [sequence](sequence.html)
* [space](space.html)
* [spaces](spaces.html)
* [token](token.html)
* [transform](transform.html)

## Compile-time data structures and values

### Result of parsing

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
* [start](start.html)

## Metafunctions and metafunction classes

* [build_parser](build_parser.html)
* [unless_error](unless_error.html)

## Strings

* [string](string.html)
* [MPLLIBS_STRING](MPLLIBS_STRING.html)

## Utilities

* [debug_parsing_error](debug_parsing_error.html)

Metaparse uses a number of general purpose metafunctions and metafunction
classes.

* [compose](compose.html)
* [curry](curry.html)
* [digit_to_int](digit_to_int.html)
* [int_to_digit](int_to_digit.html)
* [in_range](in_range.html)
* [is_digit](is_digit.html)
* [is_lcase_letter](is_lcase_letter.html)
* [is_letter](is_letter.html)
* [is_ucase_letter](is_ucase_letter.html)
* [is_whitespace](is_whitespace.html)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)


