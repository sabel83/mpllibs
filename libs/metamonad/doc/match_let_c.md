# match_let_c

## Synopsis

```cpp
template <class Pattern, class Exp, class Body>
struct match_let_c
{
  // unspecified
};
```

## Description

The same as [`match_let`](match_let.html), but `Pattern` and `Body` are
angle-bracket expressions and not syntaxes.

## Header

```cpp
#include <mpllibs/metamonad/match_let_c.hpp>
```

## Expression semantics

For any `p`, `e` and `b` classes

```cpp
match_let_c<p, e, b>::type
```

is equivalent to

```cpp
match_let<syntax<p>, e, syntax<b>>::type
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
  eval_syntax<
    match_let_c<
      just<var<x>>, maybe_something<int>::type,
      x
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



