# foldlp

## Synopsis

```cpp
template <class P, class StateP, class ForwardOp>
struct foldlp;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`StateP`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`ForwardOp`</td>
    <td>
      [template metafunction class](metafunction_class.html) taking two
      arguments
    </td>
  </tr>
</table>

## Description

The same as [`foldl`](foldl.html), but before folding it applies a parser,
`StateP` on the input. If it fails, `foldlp` fails. If it succeeds, `foldlp`
works as `foldl` taking the result of `StateP` as the initial state.

Here is a diagram showing how `foldlp` works by example:

```cpp
using int_token = token<int_>;
using plus_token = token<lit_c<'+'>>;
using plus_int = last_of<plus_token, int_token>;
using sum_op = mpl::lambda<mpl::plus<mpl::_1, mpl::_2>>::type;
```

<p align="center">
  <a href="foldlp_diag1.png"><img src="foldlp_diag1.png" style="width:70%" /></a>
</p>

Further details can be found in the [Introducing
foldlp](manual.html#introducing-foldlp) section of the [User
Manual](manual.html).

## Header

```cpp
#include <mpllibs/metaparse/foldlp.hpp>
```

## Expression semantics

For any `p` parser, `pt` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position

```cpp
foldlp<p, pt, f>::apply<s, pos>
```

is equivalent to

```cpp
pt::apply<s, pos>
```

when the above expression returns a parsing error. It is

```cpp
foldl<p, get_result<pt::apply<s, pos>>::type, f>::apply<
  get_remaining<pt::apply<s, pos>>::type,
  get_position<pt::apply<s, pos>>::type
>
```

otherwise.

## Example

```cpp
#include <mpllibs/metaparse/foldlp.hpp>
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

using namespace mpllibs::metaparse;

using int_token = token<int_>;
using plus_token = token<lit_c<'+'>>;
using plus_int = last_of<plus_token, int_token>;
using sum_op =
  boost::mpl::lambda<boost::mpl::plus<boost::mpl::_1, boost::mpl::_2>>::type;

using ints = foldlp<plus_int, int_token, sum_op>;

static_assert(
  get_result<
    ints::apply<MPLLIBS_STRING("11 + 13 + 3 + 21"), start>
  >::type::value == 48,
  "ints should sum the numbers"
);

static_assert(
  is_error<ints::apply<MPLLIBS_STRING(""), start>>::type::value,
  "when no numbers are provided, it should be an error"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


