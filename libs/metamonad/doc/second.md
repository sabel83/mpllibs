# second

## Synopsis

```cpp
template <class P>
struct second
{
  // unspecified
};
```

## Description

Returns the second element of the pair `P`.

## Header

```cpp
#include <mpllibs/metamonad/second.hpp>
```

## Expression semantics

For any `p` nullary metafunction

```cpp
second<p>::type
```

is equivalent to

```cpp
p::type::second
```

## Example

```cpp
second<pair<int_<11>, int_<13>>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



