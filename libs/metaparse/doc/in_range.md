# in_range

## Synopsis

```cpp
namespace util
{
  template <class LowerBound, class UpperBound, class Item>
  struct in_range;
}
```

This is a [template metafunction](metafunction.html) supporting
[currying](currying.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`LowerBound`</td>
    <td>[boxed integral value](boxed_value.html)</td>
  </tr>
  <tr>
    <td>`UpperBound`</td>
    <td>[boxed integral value](boxed_value.html)</td>
  </tr>
  <tr>
    <td>`Item`</td>
    <td>[boxed integral value](boxed_value.html)</td>
  </tr>
</table>

## Description

It returns a boxed boolean value. The value is `true` when `Item` is in the
range `[LowerBound..UpperBound]` and `false` otherwise. `boost::mpl::less_equal`
is used for comparison.

## Header

```cpp
#include <mpllibs/metaparse/util/in_range.hpp>
```

## Expression semantics

For any `L`, `U` and `T` classes the following are equivalent:

```cpp
in_range<L, U>::apply<T>::type::value

boost::mpl::less_equal<L, T>::type::value
  && boost::mpl::less_equal<T, U>::type::value
```

## Example

```cpp
#include <mpllibs/metaparse/util/in_range.hpp>

#include <boost/mpl/int.hpp>

using namespace mpllibs::metaparse;

static_assert(
  !util::in_range<
    boost::mpl::int_<11>,
    boost::mpl::int_<13>,
    boost::mpl::int_<10>
  >::type::value,
  "A value below the lower bound should not be in the range"
);

static_assert(
  !util::in_range<
    boost::mpl::int_<11>,
    boost::mpl::int_<13>,
    boost::mpl::int_<14>
  >::type::value,
  "A value above the upper bound should not be in the range"
);

static_assert(
  util::in_range<
    boost::mpl::int_<11>,
    boost::mpl::int_<13>,
    boost::mpl::int_<11>
  >::type::value,
  "The lower bound should be in the range"
);

static_assert(
  util::in_range<
    boost::mpl::int_<11>,
    boost::mpl::int_<13>,
    boost::mpl::int_<13>
  >::type::value,
  "The upper bound should be in the range"
);

static_assert(
  util::in_range<
    boost::mpl::int_<11>,
    boost::mpl::int_<13>,
    boost::mpl::int_<12>
  >::type::value,
  "A value between the bounds should be in the range"
);

static_assert(
  util::in_range<>
    ::apply<boost::mpl::int_<11>>::type
    ::apply<boost::mpl::int_<13>>::type
    ::apply<boost::mpl::int_<12>>::type
    ::type::value,
  "It should support currying"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

