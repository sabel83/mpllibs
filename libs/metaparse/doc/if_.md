# if_

## Synopsis

```cpp
template <class P, class T, class F>
struct if_
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser and two classes as arguments. It always
accepts the input string. The result of parsing is `T`, when `P` accepts the
input. It is `F` otherwise.

## Header

```cpp
#include <mpllibs/metaparse/if.hpp>
```

## Expression semantics

For any `p` parser, `t` and `f` classes the following are equivalent:

```cpp
if_<p, t, f>

mpllibs::metaparse::one_of<
  mpllibs::metaparse::last_of<p, mpllibs::metaparse::return_<t> >,
  mpllibs::metaparse::return_<f>
>
```

## Example

```cpp
typedef
  if_<mpllibs::metaparse::digit, boost::mpl::true_, boost::mpl::false_>
  begins_with_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


