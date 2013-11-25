# index_out_of_range

## Synopsis

```cpp
template <int From, int To, int N>
struct index_out_of_range
{
  // unspecified
};
```

## Description

Template class representing an over or under indexing error. `From` and `To`
represent the range and `N` is the value outside of the range.

This class is in the `error` namespace.

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



