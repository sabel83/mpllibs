# get_remaining

## Synopsis

```cpp
template <class D>
struct get_remaining;
```

This is a [lazy template metafunction](lazy_metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`D`</td>
    <td>[accept](accept.html) value</td>
  </tr>
</table>

## Description

Returns the remaining string information of a parsing result.

## Header

```cpp
#include <mpllibs/metaparse/get_remaining.hpp>
```

## Example

```cpp
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/accept.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_accept
{
  using type =
    accept<std::integral_constant<int, 13>, MPLLIBS_STRING("foo"), start>;
};

static_assert(
  std::is_same<
    MPLLIBS_STRING("foo"),
    get_remaining<
      accept<std::integral_constant<int, 13>, MPLLIBS_STRING("foo"), start>
    >::type
  >::type::value,
  "It should return the remaining input"
);

static_assert(
  std::is_same<
    MPLLIBS_STRING("foo"),
    get_remaining<returns_accept>::type
  >::type::value,
  "It should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

