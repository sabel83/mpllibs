# digit_to_int_c

## Synopsis

```cpp
namespace util
{
  template <char D>
  struct digit_to_int_c;
}
```

This is a template class similar to a [template metafunction](metafunction.html)
but taking a `char` value as argument.

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`D`</td>
    <td>character value</td>
  </tr>
</table>

## Description

Converts a character containing a value in the range `['0'..'9']` to an integer.

## Return value

It returns a [boxed](boxed_value.html) integer value.

## Header

```cpp
#include <mpllibs/metaparse/util/digit_to_int_c.hpp>
```

## Expression semantics

The following pairs of expressions are equivalent

```cpp
digit_to_int_c<'0'>::type
boost::mpl::int_<0>

digit_to_int_c<'9'>::type
boost::mpl::int_<9>
```

## Example

```cpp
#include <mpllibs/metaparse/util/digit_to_int_c.hpp>

using namespace mpllibs::metaparse;

static_assert(
  util::digit_to_int_c<'0'>::type::value == 0,
  "it should convert a character to the corresponding integer value"
);

static_assert(
  util::digit_to_int_c<'3'>::type::value == 3,
  "it should convert a character to the corresponding integer value"
);

static_assert(
  util::digit_to_int_c<'9'>::type::value == 9,
  "it should convert a character to the corresponding integer value"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

