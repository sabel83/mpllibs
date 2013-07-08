# middle_of

## Synopsis

```cpp
template <class P1, class P2, class P3>
struct middle_of
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator applying three parsers in sequence. It accepts an input when
all parsers accept it. The result of parsing is the result of the second parser.

## Header

```cpp
#include <mpllibs/metaparse/middle_of.hpp>
```

## Expression semantics

For any `p1`, `p2` and `p3` parsers

```cpp
middle_of<p1, p2, p3>
```

is equivalent to

```cpp
mpllibs::metaparse::nth_of<1, p1, p2, p3>
```

## Example

```cpp
typedef
  middle_of<
    mpllibs::metaparse::digit,
    mpllibs::metaparse::digit,
    mpllibs::metaparse::digit
  >
  middle_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


