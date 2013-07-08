# source_position

## Synopsis

```cpp
template <class Line, class Col>
struct source_position
{
  // unspecified
};
```

## Description

Compile-time data-structure describing a position of the input text. It can be
queried using [`get_col`](get_col.html) and [`get_line`](get_line.html).

The values of this data-structure store the last character that was parsed
before reaching that position of the input text. This can be queried using
[`get_prev_char`](get_prev_char).

The following operations are also supported: [`next_char`](next_char.html) and
[`next_line`](next_line.html).

Its tag is `source_position_tag`.

The beginning of the input text is represented by [`start`](start.html).

## Header

```cpp
#include <mpllibs/metaparse/source_position.hpp>
```

## Expression semantics

For any `l`, `c` compile-time wrapped integral values, the following are
equivalent

```cpp
mpllibs::metaparse::get_col<source_position<l, c> >::type
c::type
```

```cpp
mpllibs::metaparse::get_line<source_position<l, c> >::type
l::type
```

## Example

```cpp
typedef
  source_position<boost::mpl::int_<1>, boost::mpl::int_<1> >
  start;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



