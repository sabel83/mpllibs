# any

## Synopsis

```cpp
template <class P>
struct any
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

When the parser rejects the input for the first time, `any` still accepts the
input and the result of parsing is an empty sequence.

## Header

```cpp
#include <mpllibs/metaparse/any.hpp>
```

## Expression semantics

For any `p` parser the following are equivalent:

```cpp
any<p>

mpllibs::metaparse::foldl<
  p,
  // unspecified empty sequence
  boost::mpl::push_back<_2, _1>
>
```

## Example

```cpp
typedef any<mpllibs::metaparse::alphanum> parse_word;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


