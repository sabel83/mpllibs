# one_char_except_c

## Synopsis

```cpp
template <
  char C1,
  char C2,
  // ...
  char Cn
>
struct one_char_except_c
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

`C1` ... `Cn` are character values. This parser accepts one character
except any of `C1` ... `Cn`. If the input is empty or the next character is one
of the non-accepted ones, the parser rejects the input.

## Header

```cpp
#include <mpllibs/metaparse/one_char_except_c.hpp>
```

## Expression semantics

For any `s` compile-time string and `c1`, ..., `cn` characters the following are
equivalent

```cpp
boost::mpl::apply<one_char_except_c<c1, ..., cn>, s, pos>

boost::mpl::apply<mpllibs::metaparse::one_char, s, pos>
```

when `s` is empty or it begins with a character other than `c1`, ..., `cn`.
Otherwise `boost::mpl::apply<one_char_except_c<c1, ..., cn>, s, pos>` returns a
parsing error.

## Example

```cpp
struct some_string;

typedef
  mpllibs::metaparse::get_result<
    boost::mpl::apply<one_char_except_c<'"'>, some_string>
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


