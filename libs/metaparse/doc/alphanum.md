# alphanum

## Synopsis

```cpp
struct alphanum
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one character in the range `a-z`, `A-Z` or `0-9`. The
result of the parser is the accepted character.

## Header

```cpp
#include <mpllibs/metaparse/alphanum.hpp>
```

## Expression semantics

The following are equivalent:

```cpp
alphanum

one_of<digit, letter>
```

## Example

```cpp
boost::mpl::apply<alphanum, MPLLIBS_STRING("abcd"), start>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


