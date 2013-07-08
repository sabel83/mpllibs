# digit

## Synopsis

```cpp
struct digit
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one character in the range `0-9`. The
result of the parser is the accepted character.

## Header

```cpp
#include <mpllibs/metaparse/digit.hpp>
```

## Expression semantics

The following are equivalent:

```cpp
digit

accept_when<
  one_char,
  util::is_digit,
  // unspecified
>
```

## Example

```cpp
boost::mpl::apply<digit, MPLLIBS_STRING("13"), start>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


