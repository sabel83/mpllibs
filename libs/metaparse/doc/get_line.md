# get_line

## Synopsis

```cpp
template <class SourcePosition>
struct get_line
{
  // unspecified
};
```

## Description

Returns the line of a source position.

## Header

```cpp
#include <mpllibs/metaparse/get_line.hpp>
```

## Expression semantics

For any `l`, `c` compile-time wrapped integral values and `ch` compile-time
wrapped character the following are equivalent

```cpp
get_line<mpllibs::metaparse::source_position<l, c, ch>>::type

l::type
```

## Example

```cpp
typedef
  get_line<mpllibs::metaparse::start>::type
  one;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



