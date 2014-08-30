# foldrp

## Synopsis

```cpp
template <class P, class StateP, class BackwardOp>
struct foldrp;
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
    <td>`BackwardOp`</td>
    <td>
      [template metafunction class](metafunction_class.html) taking two
      arguments
    </td>
  </tr>
</table>

## Description

The same as [`foldr`](foldr.html), but after folding it applies a parser,
`StateP` on the input. If `StateP` fails, `foldrp` fails. If it succeeds,
the result of parsing is equivalent to
`boost::reverse_fold<Sequence, State, BackwardOp>`, where `Sequence` is the
sequence of the results of the applications of `P` and `State` is the result
`StateP` returned _after_ the repeated application of `P` on the input.

Here is a diagram showing how `foldrp` works by example:

```cpp
using int_token = token<int_>;
using plus_token = token<lit_c<'+'>>;
using int_plus = first_of<int_token, plus_token>;
using sum_op = mpl::lambda<mpl::plus<mpl::_1, mpl::_2>>::type;
```

<p align="center">
  <a href="foldrp_diag1.png"><img src="foldrp_diag1.png" style="width:70%" /></a>
</p>

Further details can be found in the [Introducing
foldrp](manual.html#introducing-foldrp) section of the [User
Manual](manual.html).

## Header

```cpp
#include <mpllibs/metaparse/foldrp.hpp>
```

## Expression semantics

For any `p` parser, `pt` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position let `pos_` be the position
where the repeated application of `p` on `s` fails for the first time. Let
`s_` be the postfix of `s` starting at that position.

```cpp
foldrp<p, pt, f>::apply<s, pos>
```

is equivalent to

```cpp
pt::apply<s_, pos_>
```

when the above expression returns a parsing error. It is

```cpp
return_<
  foldr<p, get_result<pt::apply<s_, pos_>>::type, f>::apply<s, pos>
>::apply<
  get_remaining<pt::apply<s_, pos_>>::type,
  get_position<pt::apply<s_, pos_>>::type
>
```

otherwise.

## Example

```cpp
#include <mpllibs/metaparse/foldrp.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/first_of.hpp>
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
using int_plus = first_of<int_token, plus_token>;
using sum_op =
  boost::mpl::lambda<boost::mpl::plus<boost::mpl::_1, boost::mpl::_2>>::type;

using ints = foldrp<int_plus, int_token, sum_op>;

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

