# in_range

## Synopsis

```cpp
template <class LowerBound, class UpperBound>
struct in_range
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
#include <mpllibs/metaparse/util/in_range.hpp>
```

## Expression semantics

For any `L`, `U` and `T` classes the following are equivalent:

```cpp
boost::mpl::apply<in_range<L, U>, T>

boost::mpl::and_<
  boost::mpl::less_equal<L, T>,
  boost::mpl::less_equal<T, U>
>
```

## Example

```cpp
boost::mpl::apply<
  in_range<boost::mpl::int_<11>, boost::mpl::int_<13>>,
  boost::mpl::int_<12>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

