# letter

## Synopsis

```cpp
struct letter
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one character in the range `a-z` or `A-Z`. The
result of the parser is the accepted character.

## Header

```cpp
#include <mpllibs/metaparse/letter.hpp>
```

## Expression semantics

The following are equivalent:

```cpp
letter

accept_when<
  one_char,
  util::is_letter,
  // unspecified
>
```

## Example

```cpp
boost::mpl::apply<letter, MPLLIBS_STRING("abcd"), start>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


