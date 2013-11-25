# one_of

## Synopsis

```cpp
template <
  class P1,
  class P2,
  // ...
  class Pn
>
struct one_of
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a number of parsers as arguments. It accepts an input
when any of the parsers accept it. The result of parsing is the result
of applying the first parser that accepts the input.

The maximum number of accepted parsers is defined by the
`MPLLIBS_LIMIT_ONE_OF_SIZE` macro. Its default value is `20`.

## Header

```cpp
#include <mpllibs/metaparse/one_of.hpp>
```

## Expression semantics

For any `p1`, ..., `pn` parsers, `s` compile-time string and `pos` source
position

```cpp
boost::mpl::apply<one_of<p1, ..., pn>, s, pos>
```

is equivalent to

```cpp
boost::mpl::apply<pk, s, pos>
```

when there is a `k`, that `boost::mpl::apply<pi, s, pos>::type` returns an error
for every `i` in the range `[1..k)` and `boost::mpl::apply<pk, s, pos>::type`
doesn't return an error.

The parser combinator returns an error when there is no such `k`.

## Example

```cpp
typedef
  one_of<
    mpllibs::metaparse::lit_c<' '>,
    mpllibs::metaparse::lit_c<'\t'>,
    mpllibs::metaparse::lit_c<'\n'>,
    mpllibs::metaparse::lit_c<'\r'>
  >
  space;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


