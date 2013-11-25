# is_whitespace

## Synopsis

```cpp
template <class C>
struct is_whitespace
{
  // unspecified
};
```

## Description

Checks if a character is a whitespace character.
Returns a wrapped boolean value. It supports currying.

## Header

```cpp
#include <mpllibs/metaparse/util/is_whitespace.hpp>
```

## Expression semantics

For any `C` nullary template metafunction returning a wrapped character value
the following are equivalent:

```cpp
boost::mpl::apply<is_whitespace, C>::type
is_whitespace_c<C::type::value>::type
```

## Example

```cpp
is_whitespace<boost::mpl::char_<' '>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

