# get_col

## Synopsis

```cpp
template <class SourcePosition>
struct get_col;
```

This is a [lazy template metafunction](lazy_metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`SourcePosition`</td>
    <td>[source position](source_position.html)</td>
  </tr>
</table>

## Description

Returns the column of a source position.

## Header

```cpp
#include <mpllibs/metaparse/get_col.hpp>
```

## Expression semantics

For any `l`, `c` compile-time wrapped integral values and `ch` compile-time
wrapped character the following are equivalent

```cpp
get_col<source_position<l, c, ch>>::type

c::type
```

## Example

```cpp
#include <mpllibs/metaparse/get_col.hpp>
#include <mpllibs/metaparse/source_position.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_source_position
{
  using type =
    source_position<
      std::integral_constant<int, 11>,
      std::integral_constant<int, 13>,
      std::integral_constant<char, 0>
    >;
};

static_assert(
  get_col<
    source_position<
      std::integral_constant<int, 11>,
      std::integral_constant<int, 13>,
      std::integral_constant<char, 0>
    >
  >::type::value == 13,
  "It should return the column of a source position"
);

static_assert(
  get_col<returns_source_position>::type::value == 13,
  "It should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

