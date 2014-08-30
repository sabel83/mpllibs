# range

## Synopsis

```cpp
template <class From, class To>
struct range;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`From`</td>
    <td>[boxed](boxed_value.html) character value</td>
  </tr>
  <tr>
    <td>`To`</td>
    <td>[boxed](boxed_value.html) character value</td>
  </tr>
</table>

## Description

`range` accepts one character in the range `[From..To]`. The result of the
parser is the accepted character.

## Header

```cpp
#include <mpllibs/metaparse/range.hpp>
```

## Expression semantics

For any `A`, `B` wrapped characters the following are equivalent:

```cpp
range<A, B>

accept_when<one_char, util::in_range<A, B>, errors::unexpected_character>
```

## Example

```cpp
#include <mpllibs/metaparse/range.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using one_digit =
  range<std::integral_constant<char, '0'>, std::integral_constant<char, '9'>>;

static_assert(
  !is_error<one_digit::apply<MPLLIBS_STRING("0"), start>>::type::value,
  "one_digit should accept a digit"
);

static_assert(
  is_error<one_digit::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "one_digit should reject a value outside of ['0'..'9']"
);

static_assert(
  get_result<one_digit::apply<MPLLIBS_STRING("0"), start>>::type::value == '0',
  "the result of parsing should be the character value"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

