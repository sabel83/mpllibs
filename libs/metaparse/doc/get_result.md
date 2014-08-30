# get_result

## Synopsis

```cpp
template <class D>
struct get_result;
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

Returns the result information of a parsing result.

## Header

```cpp
#include <mpllibs/metaparse/get_result.hpp>
```

## Example

```cpp
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/accept.hpp>
#include <mpllibs/metaparse/string.hpp>

using namespace mpllibs::metaparse;

struct returns_accept
{
  using type =
    accept<std::integral_constant<int, 13>, MPLLIBS_STRING("foo"), start>;
};

static_assert(
  get_result<
    accept<std::integral_constant<int, 13>, MPLLIBS_STRING("foo"), start>
  >::type::value == 13,
  "It should return the result of parsing"
);

static_assert(
  get_result<returns_accept>::type::value == 13,
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

