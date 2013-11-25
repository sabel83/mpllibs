# digit_to_int

## Synopsis

```cpp
template <class D>
struct digit_to_int
{
  // unspecified
};
```

## Description

Converts a boxed character containing a value in the range `['0'..'9']` to an
integer.

It evaluates its argument lazily and supports currying.

## Header

```cpp
#include <mpllibs/metaparse/util/digit_to_int.hpp>
```

## Expression semantics

For any `C` boxed character value in the range `['0'..'9']` the following
expressions are equivalent

```cpp
boost::mpl::apply<digit_to_int<>, C>::type
digit_to_int<C>::type
digit_to_int_c<C::type::value>::type
```

## Example

```cpp
boost::mpl::apply<digit_to_int<>, boost::mpl::char_<'7'>>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)




