# sequence

## Synopsis

```cpp
template <
  class P0,
  // ...
  class Pn
>
struct sequence
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator applying a number of parsers in sequence. It accepts an input
when all parsers accept it. The result of parsing is a sequence of the results
of the parsers.

The maximum number of parsers `sequence` accepts can be specified with the
`MPLLIBS_SEQUENCE_MAX_ARGUMENT` macro. Its default value is `5`.

## Header

```cpp
#include <mpllibs/metaparse/sequence.hpp>
```

## Expression semantics

For any `n > 0`, `p0`, ..., `pn` parsers the result of `sequence<p0, ..., p1>`
is a compile-time sequence of the results of the parsers, applied after each
other in order on the input string when none of them returns an error.
The remaining string is the remaining string the last parser returns.

When one of the parsers returns an error, the combinator returns that error.

## Example

```cpp
typedef
  sequence<mpllibs::metaparse::digit, mpllibs::metaparse::digit>
  two_digits;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


