# keyword

## Synopsis

```cpp
template <class S, class ResultType = /* unspecified */>
struct keyword;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`S`</td>
    <td>[string](string.html)</td>
  </tr>
  <tr>
    <td>`ResultType`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

Parser accepting the keyword `S`. The result of parsing is `ResultType`, which
is optional; when not given, the result of successful parsing is undefined.

## Header

```cpp
#include <mpllibs/metaparse/keyword.hpp>
```

## Expression semantics

For any `r` class and `s` compile-time string that is built from the characters
`c1` ... `cn` the following are equivalent:

```cpp
keyword<s, r>

last_of<lit<c1>, /* ... */, lit<cn>, return_<r>>
```

## Example

```cpp
#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  get_result<
    keyword<MPLLIBS_STRING("for"), std::integral_constant<int, 13>>::apply<
      MPLLIBS_STRING("for"),
      start
    >
  >::type::value == 13,
  "the result of parsing the keyword is keyword's second argument"
);

static_assert(
  is_error<
    keyword<MPLLIBS_STRING("for"), std::integral_constant<int, 13>>::apply<
      MPLLIBS_STRING("if"),
      start
    >
  >::type::value,
  "a word other than the keyword is an error"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

