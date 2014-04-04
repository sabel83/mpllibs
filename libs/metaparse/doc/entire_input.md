# entire_input

## Synopsis

```cpp
template <class P, class Msg = error::end_of_input_expected>
struct entire_input
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser taking a parser, `P` as argument, parsing the input using it and checking
if `P` consumes the entire input. If `P` fails or doesn't consume the entire
input, `entire_input` fails. Otherwise it returns the result of `P`. When `P`
does not consume the entire input, the error message returned by the parser is
`Msg`.

## Header

```cpp
#include <mpllibs/metaparse/entire_input.hpp>
```

## Expression semantics

For any `p` parser and `e` error message the following are equivalent

```cpp
entire_input<p, e>

mpllibs::metaparse::first_of<
  p,
  mpllibs::metaparse::change_error_message<
    mpllibs::metaparse::empty<
      // unspecified
    >,
    e
  >
>
```

## Example

```cpp
typedef entire_input<mpllibs::metaparse::one_char> expect_one_char_input;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


