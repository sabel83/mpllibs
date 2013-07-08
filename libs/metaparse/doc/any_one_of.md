# any_one_of

## Synopsis

```cpp
template <
  class P1,
  class P2,
  // ...
  class Pn
>
struct any_one_of
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a number of parsers as arguments. It applies the
parsers repeatedly as long as any of them accepts the input. The result is a
sequence of the individual parsing results.

The maximum number of accepted parsers is defined by the
`MPLLIBS_ONE_OF_MAX_ARGUMENT` macro. Its default value is 20.

## Header

```cpp
#include <mpllibs/metaparse/any_one_of.hpp>
```

## Expression semantics

For any `p1`, ..., `pn` parsers

```cpp
any_one_of<
  p1,
  // ...
  pn
>
```

is equivalent to

```cpp
mpllibs::metaparse::any<
  mpllibs::metaparse::one_of<
    p1,
    // ...
    pn
  >
>
```

## Example

```cpp
typedef
  any_one_of<
    mpllibs::metaparse::lit_c<' '>,
    mpllibs::metaparse::lit_c<'\t'>,
    mpllibs::metaparse::lit_c<'\n'>,
    mpllibs::metaparse::lit_c<'\r'>
  >
  any_space;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


