# unbox

## Synopsis

```cpp
template <class T>
struct unbox
{
  // unspecified
};
```

## Description

Metafunction for unboxing [boxed values](box.html).

## Header

```cpp
#include <mpllibs/metamonad/unbox.hpp>
```

## Expression semantics

For any `t` type

```cpp
unbox<box<t>>::type
```

is equivalent with

```cpp
t
```

## Example

```cpp
typedef unbox<box<int>>::type int_t;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



