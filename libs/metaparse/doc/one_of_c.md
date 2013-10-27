# one_of_c

## Synopsis

```cpp
template <
  long P1,
  long P2,
  // ...
  long Pn
>
struct one_of_c
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a number of characters as arguments. It accepts inputs
beginning with any of the characters. The result of parsing is the first
character of the input.

The maximum number of characters that can be provided is defined by the
`MPLLIBS_ONE_OF_MAX_ARGUMENT` macro. Its default value is `20`.

## Header

```cpp
#include <mpllibs/metaparse/one_of_c.hpp>
```

## Expression semantics

For any `c1`, ..., `cn` characters

```cpp
one_of_c<c1, ..., cn>
```

is equivalent to

```cpp
mpllibs::metaparse::one_of<
  mpllibs::metaparse::lit_c<c1>,
  // ...,
  mpllibs::metaparse::lit_c<cn>
>
```

## Example

```cpp
typedef one_of_c<' ', '\t', '\n', '\r'> space;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


