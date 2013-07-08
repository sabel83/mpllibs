# is_error

## Synopsis

```cpp
template <class C>
struct is_error
{
  // unspecified
};
```

## Description

Determines if `C` is a parsing error or not.

## Header

```cpp
#include <mpllibs/metaparse/is_error.hpp>
```

## Expression semantics

For any `e` parsing error `is_error<c>::type` is a wrapped compile-time `true`
value, for any other `c` class `is_error<c>::type` is a wrapped compile-time
`false` value.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



