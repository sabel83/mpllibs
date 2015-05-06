# foldrf1

## Synopsis

```cpp
template <class P, class State, class BackwardOp>
struct foldrf1;
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

The same as [`foldr1`](foldr1.html), but once `P` rejects the input, `foldrf1`
checks if `P` consumes any characters before rejecting the input. If so,
`foldrf1` rejects the input with the same error message this last application of
`P` returned. Otherwise `foldrfq` accepts the input and gives the same result as
[`foldr1`](foldr1.html).

## Header

```cpp
#include <mpllibs/metaparse/foldrf1.hpp>
```

## Expression semantics

For any `p` parser, `t` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position

```cpp
foldrf1<p, t, f>::apply<s, pos>
```

is equivalent to

```cpp
first_of<foldr1<p, t, f>, fail_at_first_char_expected<p> >::apply<s, pos>
```

## Example

```cpp
#include <mpllibs/metaparse/foldrf1.hpp>
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

using ints = foldrf1<plus_int, boost::mpl::int_<11>, sum_op>;

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

