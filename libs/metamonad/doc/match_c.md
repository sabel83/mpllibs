# match_c

## Synopsis

```cpp
template <class Pattern, class Expression>
struct match_c
{
  // unspecified
};
```

## Description

The same as [`match`](match.html), but `Pattern` is an angle-bracket
expression and not a syntax.

## Header

```cpp
#include <mpllibs/metamonad/match_c.hpp>
```

## Expression semantics

For any `p` and `e` classes

```cpp
match_c<p, e>::type
```

is equivalent to

```cpp
match<syntax<p>, e>::type
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
  boost::mpl::at<
    match_c<just<var<x>>, maybe_something<int>::type>::type,
    var<x>
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



