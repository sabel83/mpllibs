# int_to_digit

## Synopsis

```cpp
namespace util
{
  template <class D>
  struct int_to_digit;
}
```

This is a [lazy template metafunction](lazy_metafunction.html) that supports
[currying](currying.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`D`</td>
    <td>[boxed](boxed_value.html) integer value</td>
  </tr>
</table>

## Description

Converts a boxed integer value in the range `[0-9]` to a character representing
that decimal value.

## Header

```cpp
#include <mpllibs/metaparse/util/int_to_digit.hpp>
```

## Expression semantics

The following pairs of expressions are equivalent

```cpp
int_to_digit<boost::mpl::int_<0>>::type
boost::mpl::char_<'0'>
```

```cpp
int_to_digit<boost::mpl::int_<9>>::type
boost::mpl::char_<'9'>
```

## Example

```cpp
#include <mpllibs/metaparse/util/int_to_digit.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct nullary_metafunction_returning_4
{
  using type = std::integral_constant<int, 4>;
};

static_assert(
  util::int_to_digit<std::integral_constant<int, 0>>::type::value == '0',
  "it should convert an integer value to the corresponding character"
);

static_assert(
  util::int_to_digit<>::type
    ::apply<std::integral_constant<int, 7>>::type::value == '7',
  "it should support currying"
);

static_assert(
  util::int_to_digit<nullary_metafunction_returning_4>::type::value == '4',
  "it should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)




