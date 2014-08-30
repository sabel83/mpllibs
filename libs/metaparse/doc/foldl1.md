# foldl1

## Synopsis

```cpp
template <class P, class State, class ForwardOp>
struct foldl1;
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
    <td>`ForwardOp`</td>
    <td>
      [template metafunction class](metafunction_class.html) taking two
      arguments
    </td>
  </tr>
</table>

## Description

`foldl1` applies `P` on the input string repeatedly as long as `P` accepts the
input. The result of parsing is equivalent to
`boost::mpl::fold<Sequence, State, ForwardOp>`, where `Sequence` is the sequence
of the results of the applications of `P`.

When `P` rejects the input for the first time, `foldl1` rejects it as well. At
least one successful application of `P` is required for `foldl1` to accept the
input.

## Header

```cpp
#include <mpllibs/metaparse/foldl1.hpp>
```

## Expression semantics

For any `p` parser, `t` class, `f` metafunction class taking two arguments the
following are equivalent:

```cpp
foldl1<p, t, f>

last_of<look_ahead<p>, foldl<p, t, f>>
```

## Example

```cpp
#include <mpllibs/metaparse/foldl1.hpp>
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
using sum_op =
  boost::mpl::lambda<boost::mpl::plus<boost::mpl::_1, boost::mpl::_2>>::type;

using ints = foldl1<int_token, boost::mpl::int_<0>, sum_op>;

static_assert(
  get_result<
    ints::apply<MPLLIBS_STRING("11 13 3 21"), start>
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


