# match_let

## Synopsis

```cpp
template <class Pattern, class Exp, class Body>
struct match_let
{
  // unspecified
};
```

## Description

Pattern matching version of [`let`](let.html). The angly-bracket expression
`Exp` is evaluated and matched against the pattern `Pattern`. The open variables
of the match can be used in `Body`. `Pattern` and `Body` are syntaxes.

## Header

```cpp
#include <mpllibs/metamonad/match_let.hpp>
```

## Expression semantics

For any `p`, `e` and `b` angly-bracket expressions

```cpp
match_let<p, e, b>::type
```

is equivalent to

```cpp
multi_let<match<p, e>::type, b>::type
```

## Example

```cpp
using namespace mpllibs::metamonad::name;

template <class A>
struct maybe_something :
  boost::mpl::if_<
    typename boost::is_same<A, int>::type,
    just<double>,
    nothing
  >
{};

typedef
  eval_syntax<
    match_let<
      syntax<just<var<x>>>, maybe_something<int>::type,
      syntax<x>
    >
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



