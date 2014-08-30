# first_of

## Synopsis

```cpp
template <class P1, /* ... */, class Pn>
struct first_of;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P1` .. `Pn`</td>
    <td>[parser](parser.html)</td>
  </tr>
</table>

## Description

`first_of` applies the `P1` ... `Pn` parsers in sequence. It accepts an input
when all parsers accept it. The result of parsing is the result of the first
parser.

## Header

```cpp
#include <mpllibs/metaparse/first_of.hpp>
```

## Expression semantics

For any `p1`, ... `pn` parsers

```cpp
first_of<p1, ..., pn>
```

is equivalent to

```cpp
nth_of_c<0, p1, ..., pn>
```

## Example

```cpp
#include <mpllibs/metaparse/first_of.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using int_with_semicolon = first_of<int_, lit_c<';'>>;

static_assert(
  is_error<int_with_semicolon::apply<MPLLIBS_STRING("13"), start>>::type::value,
  "int without semicolon is rejected"
);

static_assert(
  get_result<
    int_with_semicolon::apply<MPLLIBS_STRING("13;"), start>
  >::type::value,
  "the result is the result of the first parser"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


