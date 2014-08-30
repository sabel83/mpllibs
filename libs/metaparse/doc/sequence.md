# sequence

## Synopsis

```cpp
template <class P1, /* ... */, class Pn>
struct sequence;
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

`sequence` applies the `P1`, ..., `Pn` parsers in sequence on the input. It
accepts an input when all of these parsers accept it. The result of parsing is a
sequence of the results of the parsers.

The maximum number of parsers `sequence` accepts can be specified with the
`MPLLIBS_LIMIT_SEQUENCE_SIZE` macro. Its default value is `5`.

## Header

```cpp
#include <mpllibs/metaparse/sequence.hpp>
```

## Expression semantics

For any `n > 0`, `p0`, ..., `pn` parsers the result of `sequence<p0, ..., p1>`
is a compile-time sequence of the results of the parsers, applied after each
other in order on the input string when none of them returns an error.
The remaining string is the remaining string the last parser returns.

When one of the parsers returns an error, the combinator returns that error.

## Example

```cpp
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <boost/mpl/at.hpp>

using namespace mpllibs::metaparse;

using int_token = token<int_>;
using plus_token = token<lit_c<'+'>>;

using a_plus_b = sequence<int_token, plus_token, int_token>;

static_assert(
  boost::mpl::at_c<
    get_result<a_plus_b::apply<MPLLIBS_STRING("1 + 2"), start>>::type,
    0
  >::type::value == 1,
  "the first element of the sequence should be the first number"
);

static_assert(
  boost::mpl::at_c<
    get_result<a_plus_b::apply<MPLLIBS_STRING("1 + 2"), start>>::type,
    1
  >::type::value == '+',
  "the second element of the sequence should be the plus"
);

static_assert(
  boost::mpl::at_c<
    get_result<a_plus_b::apply<MPLLIBS_STRING("1 + 2"), start>>::type,
    2
  >::type::value == 2,
  "the third element of the sequence should be the second number"
);

static_assert(
  is_error<a_plus_b::apply<MPLLIBS_STRING("1 +"), start>>::type::value,
  "when not all of the parsers accept the input, sequence should fail"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

