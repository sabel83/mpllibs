# one_char_except

## Synopsis

```cpp
template <
  class C1,
  class C2,
  // ...
  class Cn
>
struct one_char_except
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

`C1` ... `Cn` are boxed character values. This parser accepts one character
except any of `C1` ... `Cn`. If the input is empty or the next character is one
of the non-accepted ones, the parser rejects the input.

## Header

```cpp
#include <mpllibs/metaparse/one_char_except.hpp>
```

## Expression semantics

For any `c1`, ..., `cn` boxed characters the following are equivalent

```cpp
one_char_except<c1, ..., cn>

mpllibs::metaparse::one_char_except_c<c1::type::value, ..., cn::type::value>
```

## Example

```cpp
struct some_string;

typedef
  mpllibs::metaparse::get_result<
    boost::mpl::apply<one_char_except<boost::mpl::char_c<'"'> >, some_string>
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


