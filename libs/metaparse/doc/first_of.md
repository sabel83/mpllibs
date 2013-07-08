# first_of

## Synopsis

```cpp
template <
  class P1,
  // ...
  class Pn
>
struct first_of
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator applying a number parsers in sequence. It accepts an input
when all parsers accept it. The result of parsing is the result of the first
parser.

## Header

```cpp
#include <mpllibs/metaparse/first_of.hpp>
```

## Expression semantics

For any `p1`, ... `pn` parsers

```cpp
first_of<p1, ..., pn>
```

is equivalent to

```cpp
mpllibs::metaparse::nth_of_c<0, p1, ..., pn>
```

## Example

```cpp
typedef
  first_of<mpllibs::metaparse::digit, mpllibs::metaparse::digit>
  first_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


