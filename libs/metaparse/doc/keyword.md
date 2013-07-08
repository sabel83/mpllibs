# keyword

## Synopsis

```cpp
template <class S, class ResultType>
struct keyword
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting a keyword. The result of parsing is `ResultType`. `ResultType`
is optional; when not given, the result of successful parsing is undefined.

## Header

```cpp
#include <mpllibs/metaparse/keyword.hpp>
```

## Expression semantics

For any `r` class and `s` compile-time string that is built from the characters
`c1` ... `cn` the following are equivalent:

```cpp
keyword<s, r>

mpllibs::metaparse::last_of<
  mpllibs::metaparse::lit<c1>,
  // ...
  mpllibs::metaparse::lit<cn>,
  mpllibs::metaparse::return_<r>
>
```

## Example

```cpp
typedef keyword<MPLLIBS_STRING("if")> accept_if;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


