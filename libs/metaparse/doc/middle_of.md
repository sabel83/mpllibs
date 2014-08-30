# middle_of

## Synopsis

```cpp
template <class P1, class P2, class P3>
struct middle_of;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P1`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`P2`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`P3`</td>
    <td>[parser](parser.html)</td>
  </tr>
</table>

## Description

`middle_of` applies `P1`, `P2` and `P3` in sequence. It accepts an input when
all of these three parsers accept it. The result of parsing is the result of
`P2`.

## Header

```cpp
#include <mpllibs/metaparse/middle_of.hpp>
```

## Expression semantics

For any `p1`, `p2` and `p3` parsers

```cpp
middle_of<p1, p2, p3>
```

is equivalent to

```cpp
nth_of<1, p1, p2, p3>
```

## Example

```cpp
#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

using namespace mpllibs::metaparse;

using int_token = token<int_>;
using left_paren_token = token<lit_c<'('>>;
using right_paren_token = token<lit_c<')'>>;

using int_in_parens = middle_of<left_paren_token, int_token, right_paren_token>;

static_assert(
  get_result<
    int_in_parens::apply<MPLLIBS_STRING("(13)"), start>
  >::type::value == 13,
  "it should return the result of the middle parser"
);

static_assert(
  is_error<int_in_parens::apply<MPLLIBS_STRING("13"), start>>::type::value,
  "it should reject the input when there are no parens"
);

static_assert(
  is_error<int_in_parens::apply<MPLLIBS_STRING("(13"), start>>::type::value,
  "it should reject the input when there is no closing paren"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

