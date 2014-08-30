# index_out_of_range

## Synopsis

```cpp
namespace error
{
  template <int From, int To, int N>
  struct index_out_of_range;
}
```

This is a [template metaprogramming value](metaprogramming_value.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`From`</td>
    <td>`int` value. The lower bound of the range.</td>
  </tr>
  <tr>
    <td>`To`</td>
    <td>`int` value. The upper bound of the range.</td>
  </tr>
  <tr>
    <td>`N`</td>
    <td>`int` value. The value outside of the range.</td>
  </tr>
</table>

## Description

Template class representing an over or under indexing error. `From` and `To`
represent the range and `N` is the value outside of the range.

## Header

```cpp
#include <mpllibs/metaparse/error/index_out_of_range.hpp>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



