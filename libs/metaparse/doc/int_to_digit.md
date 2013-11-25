# int_to_digit

## Synopsis

```cpp
template <class D>
struct int_to_digit
{
  // unspecified
};
```

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
int_to_digit<boost::mpl::int_<7>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)




