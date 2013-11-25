# int_to_digit_c

## Synopsis

```cpp
template <char C>
struct int_to_digit_c
{
  // unspecified
};
```

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
int_to_digit_c<7>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)




