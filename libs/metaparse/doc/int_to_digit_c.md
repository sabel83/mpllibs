# int_to_digit_c

## Synopsis

```cpp
namespace util
{
  template <int C>
  struct int_to_digit_c;
}
```

This is a template class similar to a [template metafunction](metafunction.html)
but taking an `int` value as argument.

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C`</td>
    <td>`int` value in the range `[0-9]`</td>
  </tr>
</table>

## Description

Converts an integer value in the range `[0-9]` to a character representing that
decimal value.

## Header

```cpp
#include <mpllibs/metaparse/util/int_to_digit_c.hpp>
```

## Expression semantics

The following pairs of expressions are equivalent

```cpp
int_to_digit_c<0>::type
boost::mpl::char_<'0'>
```

```cpp
int_to_digit<9>::type
boost::mpl::char_<'9'>
```

## Example

```cpp
#include <mpllibs/metaparse/util/int_to_digit_c.hpp>

using namespace mpllibs::metaparse;

static_assert(
  util::int_to_digit_c<0>::type::value == '0',
  "it should convert an integer value to the corresponding character"
);

static_assert(
  util::int_to_digit_c<3>::type::value == '3',
  "it should convert an integer to the corresponding character"
);

static_assert(
  util::int_to_digit_c<9>::type::value == '9',
  "it should convert an integer value to the corresponding character"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

