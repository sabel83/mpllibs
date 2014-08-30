# entire_input

## Synopsis

```cpp
template <class P, class Msg = error::end_of_input_expected>
struct entire_input;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`Msg`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

It parses the input using `P` and checks if it consumes the entire input. If `P`
fails or doesn't consume the entire input, `entire_input` fails. Otherwise
`entire_input` returns the result of `P`. When `P` does not consume the entire
input, the error message returned by `entire_input` is `Msg`.

## Header

```cpp
#include <mpllibs/metaparse/entire_input.hpp>
```

## Expression semantics

For any `p` parser and `e` error message the following are equivalent

```cpp
entire_input<p, e>

first_of<
  p,
  change_error_message<empty</* some metaprogramming value */>, e>
>
```

## Example

```cpp
#include <mpllibs/metaparse/entire_input.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/define_error.hpp>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(extra_chars_at_end, "Extra chars at end");

using int_parser = entire_input<int_, extra_chars_at_end>;

static_assert(
  get_result<
    int_parser::apply<MPLLIBS_STRING("1113"), start>
  >::type::value == 1113,
  "it should parse the input if it contains only an integer"
);

static_assert(
  std::is_same<
    get_message<int_parser::apply<MPLLIBS_STRING("1113mm"), start>>::type,
    extra_chars_at_end
  >::type::value,
  "it should return the specified error message when there are extra characters"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

