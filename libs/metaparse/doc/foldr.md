# foldr

## Synopsis

```cpp
template <class P, class State, class BackwardOp>
struct foldr;
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

`foldr` applies `P` on the input string repeatedly as long as `P` accepts the
input. The result of parsing is equivalent to
`boost::reverse_fold<Sequence, State, BackwardOp>`, where `Sequence` is the
sequence of the results of the applications of `P`.

When `P` rejects the input for the first time, `foldr` still accepts the input
and the result of parsing is `State`.

Here is a diagram showing how `foldr` works by example:

```cpp
using int_token = token<int_>;
using sum_op = mpl::lambda<mpl::plus<mpl::_1, mpl::_2>>::type;
```

<p align="center">
  <a href="foldr_diag1.png"><img src="foldr_diag1.png" style="width:70%" /></a>
</p>

Further details can be found in the [Introducing
foldr](manual.html#introducing-foldr) section of the [User Manual](manual.html).

## Header

```cpp
#include <mpllibs/metaparse/foldr.hpp>
```

## Expression semantics

For any `p` parser, `t` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position

```cpp
foldr<p, t, f>::apply<s, pos>
```

is equivalent to

```cpp
return_<t>::apply<s, pos>
```

when `p::apply<s, pos>` returns an error. It is

```cpp
f::apply<
  get_result<
    foldr<p, t, f>::apply<
      get_remaining<p::apply<s, pos>>,
      get_position<p::apply<s, pos>>
    >
  >::type,
  get_result<p::apply<s, pos>>::type
>
```

otherwise.

## Example

```cpp
#include <mpllibs/metaparse/foldr.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <boost/mpl/lambda.hpp>
#include <boost/mpl/plus.hpp>

using namespace mpllibs::metaparse;

using int_token = token<int_>;
using sum_op =
  boost::mpl::lambda<boost::mpl::plus<boost::mpl::_1, boost::mpl::_2>>::type;

using ints = foldr<int_token, boost::mpl::int_<0>, sum_op>;

static_assert(
  get_result<
    ints::apply<MPLLIBS_STRING("11 13 3 21"), start>
  >::type::value == 48,
  "ints should sum the numbers"
);

static_assert(
  get_result<
    ints::apply<MPLLIBS_STRING(""), start>
  >::type::value == 0,
  "the sum of no elements is 0"
);

```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


