# digit_to_int

## Synopsis

```cpp
struct digit_to_int
{
  template <class D>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Converts a boxed character containing a value in the range `['0'..'9']` to an
integer.

It evaluates its argument lazily.

## Header

```cpp
#include <mpllibs/metaparse/util/digit_to_int.hpp>
```

## Expression semantics

The following pairs of expressions are equivalent

```cpp
boost::mpl::apply<digit_to_int, boost::mpl::char_<'0'>>
boost::mpl::int_<0>


boost::mpl::apply<digit_to_int, boost::mpl::char_<'9'>>
boost::mpl::int_<9>
```

## Example

```cpp
boost::mpl::apply<digit_to_int, boost::mpl::char_<'7'>>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)




