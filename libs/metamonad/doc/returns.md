# returns

## Synopsis

```cpp
template <class T>
struct returns
{
  typedef T type;
};
```

## Description

This metafunction returns its argument. It does not inherit from it, it is
intended to be used for defining metafunctions where it is important to make
sure that the metafunction needs to be evaluated to get the result.

## Header

```cpp
#include <mpllibs/metamonad/returns.hpp>
```

## Expression semantics

For any `t` type the following are equivalent:

```cpp
t
returns<t>::type
```

## Example

```cpp
struct void_ : returns<void_> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



