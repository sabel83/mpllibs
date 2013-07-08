# token

## Synopsis

```cpp
template <class P>
struct token
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator parsing taking a parser, `P` as argument. It uses `P` to parse
the input and consumes all whitespaces afterwards. The result of parsing is the
result of `P`.

## Header

```cpp
#include <mpllibs/metaparse/token.hpp>
```

## Expression semantics

For any `p` parser the following are equivalent:

```cpp
token<p>

mpllibs::metaparse::first_of<p, mpllibs::metaparse::spaces>
```

## Example

```cpp
typedef
  mpllibs::metaparse::token<mpllibs::metaparse::digit_val>
  one_digit_word;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


