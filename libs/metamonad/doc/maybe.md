# maybe

## Synopsis

```cpp
template <class T>
struct maybe_tag;

struct nothing;
template <class T> struct just;
```

## Description

Algebraic data type with two constructors: `just` and `nothing`. It can be used
represent an optional value. When it is used for error reporting, `just`
represents success and `nothing` represents failure.

## Header

```cpp
#include <mpllibs/metamonad/maybe.hpp>
```

## Example

```cpp
using boost::mpl::equal_to;
using boost::mpl::int_;

struct division_by_zero;

template <class A, class B>
struct divide :
  if_<
    equal_to<A, int_<0> >,
    nothing,
    just<divides<A, B> >
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



