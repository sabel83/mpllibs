# lit_c

## Synopsis

```cpp
template <char C>
struct lit
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one specific character. The result of parsing is the accepted
character.

## Header

```cpp
#include <mpllibs/metaparse/lit_c.hpp>
```

## Expression semantics

For any `c` character the following are equivalent:

```cpp
lit_c<c>

lit<boost::mpl::char_<c> >
```

## Example

```cpp
typedef lit_c<'a'> accept_a;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


