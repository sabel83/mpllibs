# calculated_value

## Synopsis

```cpp
template <class T, class ValueType, class Tag>
struct calculated_value
{
  // unspecified
};
```

## Description

Defines a `[tmp_value](tmp_value.html)<T, Tag>` with a public static
`::value` element. It will be initialised using the expression `T::get_value()`.

## Header

```cpp
#include <mpllibs/metamonad/calculated_value.hpp>
```

## Expression semantics

For any `t`, `v` and `a` types the following are equivalent:

```cpp
calculated_value<t, v, a>::type
t
```

```cpp
calculated_value<t, v, a>::tag
a
```

and the following is also provided:
```cpp
static const v calculated_value<t, v, a>::value(t::get_value());
```

## Example

```cpp
struct nothing : calculated_value<nothing, std::string>
{
  static std::string get_value() { return "nothing"; }
};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



