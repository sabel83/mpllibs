# digit_to_int

## Synopsis

```cpp
namespace util
{
  template <class D>
  struct digit_to_int;
}
```

This is a [lazy template metafunction](lazy_metafunction.html) that supports
[currying](currying.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`D`</td>
    <td>[boxed](boxed_value.html) character value</td>
  </tr>
</table>

## Description

Converts a boxed character containing a value in the range `['0'..'9']` to an
integer.

## Return value

It returns a [boxed](boxed_value.html) integer value.

## Header

```cpp
#include <mpllibs/metaparse/util/digit_to_int.hpp>
```

## Expression semantics

For any `C` boxed character value in the range `['0'..'9']` the following
expressions are equivalent

```cpp
digit_to_int<>::apply<C>::type
digit_to_int<C>::type
digit_to_int_c<C::type::value>::type
```

## Example

```cpp
#include <mpllibs/metaparse/util/digit_to_int.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct nullary_metafunction_returning_4
{
  using type = std::integral_constant<char, '4'>;
};

static_assert(
  util::digit_to_int<std::integral_constant<char, '0'>>::type::value == 0,
  "it should convert a character to the corresponding integer value"
);

static_assert(
  util::digit_to_int<>::type
    ::apply<std::integral_constant<char, '7'>>::type::value == 7,
  "it should support currying"
);

static_assert(
  util::digit_to_int<nullary_metafunction_returning_4>::type::value == 4,
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




