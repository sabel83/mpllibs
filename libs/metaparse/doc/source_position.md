# source_position

## Synopsis

```cpp
template <class Line, class Col, class PrevChar>
struct source_position;
```

This is a [template metaprogramming value](metaprogramming_value.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`Line`</td>
    <td>[boxed](boxed_value.html) integer value</td>
  </tr>
  <tr>
    <td>`Col`</td>
    <td>[boxed](boxed_value.html) integer value</td>
  </tr>
  <tr>
    <td>`PrevChar`</td>
    <td>[boxed](boxed_value.html) character value</td>
  </tr>
</table>

## Description

Compile-time data-structure describing a position of the input text.

The values of this data-structure store the last character that was parsed
before reaching the position of the input described by the `source_position`
value.

Its tag is [`source_position_tag`](source_position_tag.html).

The beginning of the input text is represented by [`start`](start.html).

## Header

```cpp
#include <mpllibs/metaparse/source_position.hpp>
```

## Expression semantics

For any `l`, `c` compile-time boxed integral values and `p` compile-time boxed
character value, the following are equivalent

```cpp
get_col<source_position<l, c, p>>::type
c::type
```

```cpp
get_line<source_position<l, c, p>>::type
l::type
```

```cpp
get_prev_char<source_position<l, c, p>>::type
p::type
```

## Constant values of this type

* [`start`](start.html)

## Operations

* `boost::mpl::equal_to`
* `boost::mpl::greater`
* `boost::mpl::greater_equal`
* `boost::mpl::less`
* `boost::mpl::less_equal`
* `boost::mpl::not_equal_to`
* [`get_col`](get_col.html)
* [`get_line`](get_line.html)
* [`get_prev_char`](get_prev_char.html)
* [`next_char`](next_char.html)
* [`next_line`](next_line.html)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

