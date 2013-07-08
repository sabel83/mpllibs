# unless_error

## Synopsis

```cpp
template <class T, class NotErrorCase>
struct unless_error
{
  // unspecified
};
```

## Description

Checks if `T` is a parsing error or not. When it is, the result is `T`. When it
is not, the result is `NotErrorCase`. Arguments are evaluated lazily.

## Header

```cpp
#include <mpllibs/metaparse/unless_error.hpp>
```

## Expression semantics

For any `t` and `c` classes the following are equivalent:

```cpp
unless_error<t, c>

boost::mpl::if_<mpllibs::metaparse::is_error<t::type>::type, t, c>
```

## Example

```cpp
struct digit_char
{
  typedef digit_char type;
};

unless_error<
  boost::mpl::apply<is_digit, boost::mpl::char_<'7'>>,
  digit_char
>::type;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



