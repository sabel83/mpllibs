# eval_multi_let

## Synopsis

```cpp
template <class ValueMap, class Body>
struct eval_multi_let
{
  // unspecified
};
```

## Description

This is similar to [`multi_let`](multi_let.html), but it evaluates the
substituted expression.

## Header

```cpp
#include <mpllibs/metamonad/eval_multi_let.hpp>
```

## Expression semantics

For any `m` `boost::mpl::map` and `f` classes

```cpp
eval_multi_let<m, f>
```

is equivalent to

```cpp
eval_syntax<multi_let<m, f>>
```

## Example

```cpp
using boost::mpl::times;
using boost::mpl::plus;
using boost::mpl::int_;
using boost::mpl::map;

using namespace mpllibs::metamonad::name;

template <class N>
struct my_metafunction :
  eval_multi_let<map<pair<x, plus<n, int_<13>>>>, syntax<times<x, x>>>
{};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



