# eval_let

## Synopsis

```cpp
template <class Name, class Exp, class Body>
struct eval_let
{
  // unspecified
};
```

## Description

This is similar to [`let`](let.html), but it evaluates the substituted
expression.

## Header

```cpp
#include <mpllibs/metamonad/eval_let.hpp>
```

## Expression semantics

For any `n`, `x` and `f` classes

```cpp
eval_let<n, x, f>
```

is equivalent to

```cpp
eval_syntax<let<n, x, f>>
```

## Example

```cpp
using boost::mpl::times;
using boost::mpl::plus;
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

template <class N>
struct my_metafunction :
  eval_let<
    x, syntax<plus<n, int_<13>>>,
    syntax<times<x, x>>
  >
{};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



