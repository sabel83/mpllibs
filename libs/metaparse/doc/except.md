# except

## Synopsis

```cpp
template <class P, class Result, class ErrorMsg>
struct except
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser and a class as arguments. It accepts the input
when `P` rejects it. The result of parsing is the `Result` argument.

## Header

```cpp
#include <mpllibs/metaparse/except.hpp>
```

## Expression semantics

For any `p` parser, `c` class, `msg` error message, `s` compile-time string and
`pos` source position the following are equivalent

```cpp
mpllibs::metaparse::get_result<except<p, c, msg>, s, pos>::type
c
```

```cpp
mpllibs::metaparse::get_remaining<except<p, c, msg>, s, pos>::type
s
```

```cpp
mpllibs::metaparse::get_position<except<p, c, msg>, s, pos>::type
pos
```

when `p` rejects the input. The result of the parser is an error with the error
message `msg` otherwise.

## Example

```cpp
struct no_digit_expected
{
  typedef no_digit_expected type;
};

typedef except<mpllibs::metaparse::digit, int, no_digit_expected> not_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


