# lit

## Synopsis

```cpp
template <class C>
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
#include <mpllibs/metaparse/lit.hpp>
```

## Expression semantics

For any `c` wrapped character the following are equivalent:

```cpp
lit<c>

mpllibs::metaparse::accept_when<
  mpllibs::metaparse::one_char,
  boost::mpl::lambda<boost::mpl::equal_to<boost::mpl::_1, c> >::type,
  // unspecified
>
```

## Example

```cpp
typedef lit<boost::mpl::char_<'a'> > accept_a;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


