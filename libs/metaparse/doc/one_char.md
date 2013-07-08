# one_char

## Synopsis

```cpp
struct one_char
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one character. The result of parsing is the accepted
character. It fails for empty input.

## Header

```cpp
#include <mpllibs/metaparse/one_char.hpp>
```

## Expression semantics

For any `s` non-empty compile-time string and `pos` source position the
following are equivalent

```cpp
mpllibs::metaparse::get_result<boost::mpl::apply<one_char, s, pos> >

boost::mpl::front<s>
```

```cpp
mpllibs::metaparse::get_remaining<boost::mpl::apply<one_char, s, pos> >

boost::mpl::pop_front<s>
```

The value of
`mpllibs::metaparse::get_position<boost::mpl::apply<one_char, s, pos> >` depends
on the first character of the sequence and the value of the one parsed before
that (which is stored in the source position). `one_char` updates the source
position's `col` and `line` values based on the new line characters. It detects
Linux (`\n`), Windows (`\r\n`) and Mac (`\r`) line endings.

`boost::mpl::apply<one_char, MPLLIBS_STRING(""), pos>` returns an error for
every `pos` source position.

## Example

```cpp
struct some_string;

typedef
  mpllibs::metaparse::get_result<
    boost::mpl::apply<one_char, some_string>
  >::type
  first_character_of_some_string;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


