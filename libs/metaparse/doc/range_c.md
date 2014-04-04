# range_c

## Synopsis

```cpp
template <char From, char To>
struct range_c
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
#include <mpllibs/metaparse/range_c.hpp>
```

## Expression semantics

For any `A`, `B` characters the following are equivalent:

```cpp
range_c<A, B>

accept_when<
  one_char,
  util::in_range_c<char, A, B>,
  // unspecified
>
```

## Example

```cpp
boost::mpl::apply<range_c<'0', '9'>, MPLLIBS_STRING("13"), start>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


