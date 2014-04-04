# range

## Synopsis

```cpp
template <class From, class To>
struct range
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one character in the range `From-To`. The
result of the parser is the accepted character.

## Header

```cpp
#include <mpllibs/metaparse/range.hpp>
```

## Expression semantics

For any `A`, `B` wrapped characters the following are equivalent:

```cpp
range<A, B>

accept_when<
  one_char,
  util::in_range<A, B>,
  // unspecified
>
```

## Example

```cpp
using boost::mpl::char_;

boost::mpl::apply<range<char_<'0'>, char_<'9'>>, MPLLIBS_STRING("13"), start>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


