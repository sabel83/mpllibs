# always

## Synopsis

```cpp
template <class P, class T>
struct always
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser and a class as arguments. It accepts an input
if and only if `P` accepts it, but the result of parsing will be `T` instead of
the result `P` returned.

## Header

```cpp
#include <mpllibs/metaparse/always.hpp>
```

## Expression semantics

For any `p` parser, `t` class the following are equivalent:

```cpp
always<p, t>

mpllibs::metaparse::last_of<p, mpllibs::metaparse::return_<t> >
```

## Example

```cpp
class alphanum_char {};

typedef
  always<mpllibs::metaparse::alphanum, alphanum_char>
  ignore_alphanum_value;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


