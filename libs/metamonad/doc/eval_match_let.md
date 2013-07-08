# eval_match_let

## Synopsis

```cpp
template <class Pattern, class Exp, class Body>
struct eval_match_let
{
  // unspecified
};
```

## Description

This is similar to [`match_let`](match_let.html), but it evaluates the
substituted expression.

## Header

```cpp
#include <mpllibs/metamonad/eval_match_let.hpp>
```

## Expression semantics

For any `p`, `x` and `f` classes

```cpp
eval_match_let<p, x, f>
```

is equivalent to

```cpp
eval_syntax<match_let<p, x, f>>
```

## Example

```cpp
using namespace mpllibs::metamonad::name;

template <class A>
struct maybe_something :
  boost::mpl::if_<
    typename boost::is_same<A, int>::type,
    just<returns<double>>,
    nothing
  >
{};

typedef
  eval_match_let<
    syntax<just<var<x>>>, maybe_something<int>::type,
    syntax<x>
  >::type
  this_is_double;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



