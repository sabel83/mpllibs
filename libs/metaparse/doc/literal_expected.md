# lteral_expected

## Synopsis

```cpp
namespace error
{
  template <char C>
  struct literal_expected;
}
```

This is a [template metaprogramming value](metaprogramming_value.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C`</td>
    <td>`char` value</td>
  </tr>
</table>

## Description

Template class representing the error that a specific literal was expected. `C`
is the literal that was expected but not found.

## Header

```cpp
#include <mpllibs/metaparse/error/literal_expected.hpp>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

