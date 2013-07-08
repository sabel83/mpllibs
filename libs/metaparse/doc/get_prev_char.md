# get_prev_char

## Synopsis

```cpp
template <class SourcePosition>
struct get_prev_char
{
  // unspecified
};
```

## Description

Returns the last character the source position was updated with. The value it
returns for `mpllibs::metaparse::start` is unspecified.

## Header

```cpp
#include <mpllibs/metaparse/get_prev_char.hpp>
```

## Expression semantics

For any `l`, `c` compile-time wrapped integral values and `ch` compile-time
wrapped character the following are equivalent

```cpp
get_prev_char<mpllibs::metaparse::source_position<l, c, ch>>::type

ch::type
```

## Example

```cpp
typedef
  get_prev_char<mpllibs::metaparse::start>::type
  unspecified;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



