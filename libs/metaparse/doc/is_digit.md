# is_digit

## Synopsis

```cpp
struct is_digit
{
  template <class C>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Checks if a boxed character is a digit value or not. Returns a wrapped boolean
value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_digit.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
boost::mpl::apply<is_digit, boost::mpl::char_<'0'> >
boost::mpl::true_


boost::mpl::apply<is_digit, boost::mpl::char_<'9'> >
boost::mpl::true_


boost::mpl::apply<is_digit, c>
boost::mpl::false_
```

## Example

```cpp
boost::mpl::apply<is_digit, boost::mpl::char_<'7'> >
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



