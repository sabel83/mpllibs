# return_

## Synopsis

```cpp
template <class C>
struct return_
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting every input. The result of parsing is `C`, the remaining string
is the input string.

## Header

```cpp
#include <mpllibs/metaparse/return_.hpp>
```

## Expression semantics

For any `c` class, `s` compile-time string and `pos` source position the
following are equivalent

```cpp
mpllibs::metaparse::get_result<boost::mpl::apply<return_<c>, s, pos>>::type

c
```

```cpp
mpllibs::metaparse::get_remaining<boost::mpl::apply<return_<c>, s, pos>>::type

s
```

```cpp
mpllibs::metaparse::get_position<boost::mpl::apply<return_<c>, s, pos>>::type

pos
```

## Example

```cpp
typedef return_<int> always_int;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


