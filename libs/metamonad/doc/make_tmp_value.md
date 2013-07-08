# make_tmp_value

## Synopsis

```cpp
template <class T, class Tag>
struct make_tmp_value
{
  typedef T type;

  // unspecified
};
```

## Description

When a class is used as a value for template metaprograms, it needs to behave as
a nullary metafunction evaluating to itself to avoid issues when it is passed to
lazy metafunctions. This metafunction can be used to add `::type` and optionally
`::tag` to a type that doesn't have one.

## Header

```cpp
#include <mpllibs/metamonad/make_tmp_value.hpp>
```

## Expression semantics

For any `t` and `v` types the following are equivalent:

```cpp
make_tmp_value<t>::type
make_tmp_value<t>
```

```cpp
tmp_value<t, v>::type
tmp_value<t, v>
```

```cpp
tmp_value<t, v>::tag
v
```

For any `t` and `v` types `make_tmp_value<t>` and `make_tmp_value<t, v>`
publicly inherit from `t`.

## Example

```cpp
make_tmp_value<boost::mpl::always<int> >
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



