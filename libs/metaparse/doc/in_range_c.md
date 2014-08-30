# in_range_c

## Synopsis

```cpp
namespace util
{
  template <class T, T LowerBound, T UpperBound>
  struct in_range_c
  {
    template <class U>
    struct apply;
  };
}
```

This is a [template metafunction class](metafunction_class.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`T`</td>
    <td>integral type</td>
  </tr>
  <tr>
    <td>`LowerBound`</td>
    <td>value of type `T`</td>
  </tr>
  <tr>
    <td>`UpperBound`</td>
    <td>value of type `T`</td>
  </tr>
  <tr>
    <td>`U`</td>
    <td>[boxed integral value](boxed_value.html)</td>
  </tr>
</table>

## Description

Metafunction class verifying that `U` is in the `[LowerBound..UpperBound]` range
or not.

## Header

```cpp
#include <mpllibs/metaparse/util/in_range_c.hpp>
```

## Expression semantics

For any `T` integral type, `A`, `B` values of type `T` and `C` wrapped value the
following are equivalent:

```cpp
in_range_c<T, A, B>::apply<C>::type::value

A <= C::type::value && C::type::value <= B
```

## Example

```cpp
#include <mpllibs/metaparse/util/in_range_c.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  !util::in_range_c<int, 11, 13>
    ::apply<std::integral_constant<int, 10>>::type::value,
  "A value below the lower bound should not be in the range"
);

static_assert(
  !util::in_range_c<int, 11, 13>
    ::apply<std::integral_constant<int, 14>>::type::value,
  "A value above the upper bound should not be in the range"
);

static_assert(
  util::in_range_c<int, 11, 13>
    ::apply<std::integral_constant<int, 11>>::type::value,
  "The lower bound should be in the range"
);

static_assert(
  util::in_range_c<int, 11, 13>
    ::apply<std::integral_constant<int, 13>>::type::value,
  "The upper bound should be in the range"
);

static_assert(
  util::in_range_c<int, 11, 13>
    ::apply<std::integral_constant<int, 12>>::type::value,
  "A value between the bounds should be in the range"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

