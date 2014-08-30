# nth_of_c

## Synopsis

```cpp
template <int N, class P0, /* ... */, class Pk>
struct nth_of_c;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`N`</td>
    <td>`int` value in the range `[0..k]`</td>
  </tr>
  <tr>
    <td>`P0`..`Pk`</td>
    <td>[parser](parser.html)s</td>
  </tr>
</table>

## Description

`nth_of_c` applies the `P0` .. `Pk` parsers in sequence. It accepts an input
when all of these parsers accept it. The result of parsing is the result of the
`N`. parser.

The maximum number of parsers `nth_of_c` accepts can be specified with the
`MPLLIBS_LIMIT_SEQUENCE_SIZE` macro. Its default value is `5`.

## Header

```cpp
#include <mpllibs/metaparse/nth_of.hpp>
```

## Expression semantics
For any `p0`, ..., `pn` parsers and `k` integer value, where `0 <= k < n` the
following are equivalent

```cpp
nth_of_c<k, p0, ..., pn>

transform<sequence<p0, ..., pn>, boost::mpl::at_c<boost::mpl::_1, k>>
```

## Example

```cpp
#include <mpllibs/metaparse/nth_of_c.hpp>
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

using int_in_parens =
  nth_of_c<1, left_paren_token, int_token, right_paren_token>;

static_assert(
  get_result<
    int_in_parens::apply<MPLLIBS_STRING("(13)"), start>
  >::type::value == 13,
  "it should return the result of the second parser"
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

