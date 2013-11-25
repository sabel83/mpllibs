# digit_to_int_c

## Synopsis

```cpp
template <char D>
struct digit_to_int_c
{
  // unspecified
};
```

## Description

Converts a character containing a value in the range `['0'..'9']` to an integer.

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
digit_to_int_c<'7'>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)




