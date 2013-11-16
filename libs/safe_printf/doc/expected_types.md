# expected_types

## Synopsis

```cpp
template <class FormatString>
struct expected_types
{
  // unspecified
};
```

## Description

`FormatString` is a string representing a `printf` format string. The function
returns the list of argument types the format string expects. The types are
boxed using Metamonad's boxing wrapper.

## Header

```cpp
#include <mpllibs/safe_printf/expected_types.hpp>
```

## Expression semantics

For any `s` `mpllibs::metaparse::string`:

```cpp
mpllibs::safe_printf::expected_types<s>::type
```

is the list of types `printf` needs after the format string. The types are
wrapped with `mpllibs::metamonad::box`.

## Example

```cpp
using mpllibs::metamonad::box;

BOOST_STATIC_ASSERT((
  boost::mpl::equal<
    mpllibs::safe_printf::expected_types<MPLLIBS_STRING("%d %d\n")>::type,
    boost::mpl::vector<box<int>, box<int>>
  >::type::value
));
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




