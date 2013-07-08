# transform

## Synopsis

```cpp
template <class P, class T>
struct transform
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser, `P` and a transformation function `T` as
arguments. It accepts the same inputs `P` accepts, but transforms the result of
`P` using `T`.

## Header

```cpp
#include <mpllibs/metaparse/transform.hpp>
```

## Expression semantics

For any `p` parser, `t` metafunction class accepting one argument, `s`
compile-time string and `pos` source position

```cpp
mpllibs::metaparse::get_result<
  boost::mpl::apply<transform<p, t>, s, pos>
>::type
```

is equivalent to

```cpp
boost::mpl::apply<
  t,
  mpllibs::metaparse::get_result<boost::mpl::apply<p, s, pos> >::type
>::type
```

When `boost::mpl::apply<p, s, pos>` doesn't return an error. The combinator
returns the error otherwise.

## Example

```cpp
typedef
  mpllibs::metaparse::transform<
    mpllibs::metaparse::digit,
    mpllibs::metaparse::util::digit_to_int
  >
  digit_val;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


