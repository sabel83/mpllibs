# foldrf

## Synopsis

```cpp
template <class P, class State, class BackwardOp>
struct foldrf;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`State`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
  <tr>
    <td>`BackwardOp`</td>
    <td>
      [template metafunction class](metafunction_class.html) taking two
      arguments
    </td>
  </tr>
</table>

## Description

The same as [`foldr`](foldr.html), but once `P` rejects the input, `foldrf`
checks if `P` consumes any characters before rejecting the input. If so,
`foldrf` rejects the input with the same error message this last application of
`P` returned. Otherwise `foldrf` accepts the input and gives the same result as
[`foldr`](foldr.html).

Here is a diagram showing how `foldrf` works by example:

```cpp
using int_token = token<int_>;
using plus_token = token<lit_c<'+'>>;
using plus_int = last_of<plus_token, int_token>;
using sum_op = mpl::lambda<mpl::plus<mpl::_1, mpl::_2>>::type;
```

<p align="center">
  <a href="foldrf_diag1.png"><img src="foldrf_diag1.png" style="width:70%" /></a>
</p>

Note that `foldrf` folds from right to left and therefore does not start folding
until it reaches the end of the sequence. Since at the end of the sequence it
finds an error, folding does not happen at all.

## Header

```cpp
#include <mpllibs/metaparse/foldrf.hpp>
```

## Expression semantics

For any `p` parser, `t` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position

```cpp
foldrf<p, t, f>::apply<s, pos>
```

is equivalent to

```cpp
first_of<foldr<p, t, f>, fail_at_first_char_expected<p> >::apply<s, pos>
```

## Example

```cpp
#include <mpllibs/metaparse/foldrf.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/lambda.hpp>
#include <boost/mpl/plus.hpp>
#include <boost/mpl/int.hpp>

using namespace mpllibs::metaparse;

using int_token = token<int_>;
using plus_token = token<lit_c<'+'>>;
using plus_int = last_of<plus_token, int_token>;
using sum_op =
  boost::mpl::lambda<boost::mpl::plus<boost::mpl::_1, boost::mpl::_2>>::type;

using ints = foldrf<plus_int, boost::mpl::int_<11>, sum_op>;

static_assert(
  get_result<
    ints::apply<MPLLIBS_STRING("+ 13 + 3 + 21"), start>
  >::type::value == 48,
  "ints should sum the numbers"
);

static_assert(
  is_error<ints::apply<MPLLIBS_STRING("+ 13 + 3 +"), start>>::type::value,
  "when the last number is missing, it should be an error"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

