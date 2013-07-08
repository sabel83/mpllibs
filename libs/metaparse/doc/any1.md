# any1

## Synopsis

```cpp
template <class P>
struct any1
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser as argument. It applies the parser on the
input string repeatedly as long as the parser accepts the input. The result of
parsing is a sequence of the results of the individual applications of the
parser.

When the parser rejects the input for the first time, `any1` rejects it as well.
At least one successful application of `P` is required for `any1` to accept the
input.

## Header

```cpp
#include <mpllibs/metaparse/any1.hpp>
```

## Expression semantics

For any `p` parser the following are equivalent:

```cpp
any1<p>

mpllibs::metaparse::last_of<
  mpllibs::metaparse::look_ahead<p>,
  mpllibs::metaparse::any<p>
>
```

## Example

```cpp
typedef any1<mpllibs::metaparse::alphanum> parse_non_empty_word;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


