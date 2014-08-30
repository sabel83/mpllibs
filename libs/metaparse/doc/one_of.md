# one_of

## Synopsis

```cpp
template <class P1, class P2, /* ... */, class Pn>
struct one_of;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P1` .. `Pn`</td>
    <td>[parser](parser.html)s</td>
  </tr>
</table>

## Description

It accepts an input when any of the `P1`, ... `Pn` parsers accept it. The result
of parsing is the result of applying the first parser that accepts the input.
The parsers are tried in order.

The maximum number of accepted parsers is defined by the
`MPLLIBS_LIMIT_ONE_OF_SIZE` macro. Its default value is `20`.

## Header

```cpp
#include <mpllibs/metaparse/one_of.hpp>
```

## Expression semantics

For any `p1`, ..., `pn` parsers, `s` compile-time string and `pos` source
position

```cpp
one_of<p1, ..., pn>::apply<s, pos>
```

is equivalent to

```cpp
pk::apply<s, pos>
```

when there is a `k`, that `pi::apply<s, pos>::type` returns an error for every
`i` in the range `[1..k)` and `pk::apply<s, pos>::type` doesn't return an error.

The parser combinator returns an error when there is no such `k`.

## Example

```cpp
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

using namespace mpllibs::metaparse;

using whitespace =
  one_of<lit_c<' '>, lit_c<'\n'>, lit_c<'\r'>, lit_c<'\t'>, lit_c<'\v'>>;

static_assert(
  get_result<whitespace::apply<MPLLIBS_STRING(" "), start>>::type::value == ' ',
  "the result of parsing should be the first character of the input"
);

static_assert(
  is_error<whitespace::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "it should return an error when the input does not begin with a whitespace"
);

```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

