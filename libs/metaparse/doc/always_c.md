# always_c

## Synopsis

```cpp
template <char C, class T>
struct always_c
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a character and a class as arguments. It accepts an
input if it begins with the `C` character. The result of parsing is `T` instead
of the character.

## Header

```cpp
#include <mpllibs/metaparse/always_c.hpp>
```

## Expression semantics

For any `c` character and `t` class the following are equivalent:

```cpp
always_c<c, t>

always<lit_c<c>, t>
```

## Example

```cpp
typedef always_c<'x', boost::mpl::void_> ignore_x;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


