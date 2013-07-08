# multi_let_c

## Synopsis

```cpp
template <class ValueMap, class Body>
struct multi_let_c
{
  // unspecified
};
```

## Description

The same as [`multi_let`](multi_let.html), but `Body` is an angle-bracket
expression and not a syntax.

## Header

```cpp
#include <mpllibs/metamonad/multi_let_c.hpp>
```

## Expression semantics

For any `m` and `b` classes

```cpp
multi_let_c<m, b>::type
```

is equivalent to

```cpp
multi_let<m, syntax<b>>::type
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
  eval_syntax<multi_let_c<map<pair<x, plus<n, int_<13>>>>, times<x, x>>>
{};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



