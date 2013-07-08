# tmp_value

## Synopsis

```cpp
template <class T, class Tag>
struct tmp_value
{
  typedef T type;

  // unspecified
};
```

## Description

When a class is used as a value for template metaprograms, it needs to behave as
a nullary metafunction evaluating to itself to avoid issues when it is passed to
lazy metafunctions. Inheriting from `tmp_value` instead of defining `type`
explicitly makes the intent of the programmer explicit.
It has an optional second argument, `Tag`. When it is specified, `tmp_value` has
a nested `typedef tag` pointing to `Tag`.

## Header

```cpp
#include <mpllibs/metamonad/tmp_value.hpp>
```

## Expression semantics

For any `t` and `v` types the following are equivalent:

```cpp
t
tmp_value<t>::type
```

```cpp
t
tmp_value<t, v>::type
```

```cpp
v
tmp_value<t, v>::tag
```

## Example

```cpp
struct some_tag : tmp_tag<some_tag> {};

struct void_ : tmp_value<void_, some_tag> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



