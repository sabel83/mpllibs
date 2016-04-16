# eval_case

## Synopsis

```cpp
template <class Exp, class C1, ..., class Cn>
struct eval_case
{
  // unspecified
};
```

## Description

This is similar to [`case_`](case_.html), but it evaluates the selected
expression.

## Header

```cpp
#include <mpllibs/metamonad/eval_case.hpp>
```

## Expression semantics

For any `n > 0`, `c1`, ..., `cn` and `e` classes

```cpp
eval_case<e, c1, ..., cn>
```

is equivalent to

```cpp
eval_syntax<case_<e, c1, ..., cn>>
```

## Example

```cpp
#include <mpllibs/metamonad/name.hpp>
#include <mpllibs/metamonad/maybe.hpp>
#include <mpllibs/metamonad/eval_case.hpp>
#include <mpllibs/metamonad/var.hpp>
#include <mpllibs/metamonad/returns.hpp>
#include <mpllibs/metamonad/box.hpp>
#include <mpllibs/metamonad/unbox.hpp>

#include <boost/mpl/if.hpp>
#include <boost/type_traits/is_same.hpp>

using namespace mpllibs::metamonad::name;

using mpllibs::metamonad::just;
using mpllibs::metamonad::nothing;
using mpllibs::metamonad::eval_case;
using mpllibs::metamonad::matches_c;
using mpllibs::metamonad::var;
using mpllibs::metamonad::returns;
using mpllibs::metamonad::_;
using mpllibs::metamonad::box;
using mpllibs::metamonad::unbox;

template <class A>
struct maybe_something :
  boost::mpl::if_<
    typename boost::is_same<A, box<int> >::type,
    just<box<double>>,
    nothing
  >
{};

typedef
  unbox<
    eval_case< maybe_something<box<int>>,
      matches_c<just<x>, returns<x>>,
      matches_c<nothing, nothing>,
      matches_c<_,       nothing>
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



