# last_of

## Synopsis

```cpp
template <class P1, /* ... */, class Pn>
struct last_of;
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

`last_of` applies the `P1` ... `Pn` parsers in sequence. It accepts an input
when all parsers accept it. The result of parsing is the result of the last
parser.

## Header

```cpp
#include <mpllibs/metaparse/last_of.hpp>
```

## Expression semantics

For any `p1`, ... `pn` parsers

```cpp
first_of<p1, ..., pn>
```

is equivalent to

```cpp
nth_of_c<n, p1, ..., pn>
```

## Example

```cpp
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using comma_int = last_of<lit_c<','>, int_>;

static_assert(
  is_error<comma_int::apply<MPLLIBS_STRING("13"), start>>::type::value,
  "int without comma is rejected"
);

static_assert(
  get_result<comma_int::apply<MPLLIBS_STRING(",13"), start>>::type::value,
  "the result is the result of the last parser"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

