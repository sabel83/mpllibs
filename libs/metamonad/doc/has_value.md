# has_value

## Synopsis

```cpp
template <class T>
struct has_value
{
  // unspecified
};
```

## Description

Check if a `T::value` value is available. Returns a wrapped boolean value.

## Header

```cpp
#include <mpllibs/metamonad/has_value.hpp>
```

## Example

```cpp
struct foo {};

assert(!has_value<foo>::type::value);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



