# in_range_c

## Synopsis

```cpp
template <class T, T LowerBound, T UpperBound>
struct in_range_c
{
  template <class T>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Metafunction class verifying that a value is in a range or not.

## Header

```cpp
#include <mpllibs/metaparse/util/in_range_c.hpp>
```

## Expression semantics

For any `T` integral type, `A`, `B` values of type `T` and `C` wrapped value the
following are equivalent:

```cpp
boost::mpl::apply<in_range_c<T, A, B>, C>

boost::mpl::bool_<(A <= C::type::value && C::type::value <= B)>
```

## Example

```cpp
boost::mpl::apply<in_range_c<int, 11, 13>, boost::mpl::int_<12>>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

