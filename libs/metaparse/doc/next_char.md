# next_char

## Synopsis

```cpp
template <class SourcePosition, class Ch>
struct next_char;
```

This is a [lazy template metafunction](lazy_metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`SourcePosition`</td>
    <td>[source position](source_position.html)</td>
  </tr>
  <tr>
    <td>`Ch`</td>
    <td>
      [boxed](boxed_value.html) character value. The character `SourcePosition`
      points to in the input.
    </td>
  </tr>
</table>

## Description

Returns a new source position, pointing to the next character of the same line.

## Header

```cpp
#include <mpllibs/metaparse/next_char.hpp>
```

## Expression semantics

For any `s` source position and `c` wrapped character the following are
equivalent

```cpp
get_col<next_char<s, c>>

boost::mpl::plus<get_col<s>::type, boost::mpl::int_<1>>
```

```cpp
get_line<next_char<s, c>>

get_line<s>
```

```cpp
get_prev_char<next_char<s, c>>::type

c
```

## Example

```cpp
#include <mpllibs/metaparse/next_char.hpp>
#include <mpllibs/metaparse/source_position.hpp>
#include <mpllibs/metaparse/get_col.hpp>
#include <mpllibs/metaparse/get_line.hpp>
#include <mpllibs/metaparse/get_prev_char.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_source_position
{
  using type =
    source_position<
      std::integral_constant<int, 11>,
      std::integral_constant<int, 13>,
      std::integral_constant<char, 'a'>
    >;
};

struct returns_char
{
  using type = std::integral_constant<char, 'x'>;
};

static_assert(
  get_col<
    next_char<
      source_position<
        std::integral_constant<int, 11>,
        std::integral_constant<int, 13>,
        std::integral_constant<char, 'a'>
      >,
      std::integral_constant<char, 'x'>
    >
  >::type::value == 14,
  "it should increase the column component of the source position"
);

static_assert(
  get_line<
    next_char<
      source_position<
        std::integral_constant<int, 11>,
        std::integral_constant<int, 13>,
        std::integral_constant<char, 'a'>
      >,
      std::integral_constant<char, 'x'>
    >
  >::type::value == 11,
  "it should not increase the line component of the source position"
);

static_assert(
  get_prev_char<
    next_char<
      source_position<
        std::integral_constant<int, 11>,
        std::integral_constant<int, 13>,
        std::integral_constant<char, 'a'>
      >,
      std::integral_constant<char, 'x'>
    >
  >::type::value == 'x',
  "it should update the prev char component of the source position"
);

static_assert(
  get_col<next_char<returns_source_position, returns_char>>::type::value == 14,
  "it should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

