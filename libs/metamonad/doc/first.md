# first

## Synopsis

```cpp
template <class P>
struct first
{
  // unspecified
};
```

## Description

Returns the first element of the pair `P`.

## Header

```cpp
#include <mpllibs/metamonad/first.hpp>
```

## Expression semantics

For any `p` nullary metafunction

```cpp
first<p>::type
```

is equivalent to

```cpp
p::type::first
```

## Example

```cpp
first<pair<int_<11>, int_<13>>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



