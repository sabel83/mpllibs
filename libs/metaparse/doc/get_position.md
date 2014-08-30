# get_position

## Synopsis

```cpp
template <class D>
struct get_position;
```

This is a [lazy template metafunction](lazy_metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`D`</td>
    <td>[accept](accept.html) or [reject](reject.html) value</td>
  </tr>
</table>

## Description

Returns the source position information of a parsing result.

## Header

```cpp
#include <mpllibs/metaparse/get_position.hpp>
```

## Example

```cpp
#include <mpllibs/metaparse/get_position.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/accept.hpp>
#include <mpllibs/metaparse/reject.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/define_error.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(sample_error, "Sample error message");

struct returns_reject
{
  using type = reject<sample_error, start>;
};

static_assert(
  std::is_same<
    start,
    get_position<reject<sample_error, start>>::type
  >::type::value,
  "It should return the position of a reject"
);

static_assert(
  std::is_same<
    start,
    get_position<accept<sample_error, MPLLIBS_STRING("foo"), start>>::type
  >::type::value,
  "It should return the position of an accept"
);

static_assert(
  std::is_same<start, get_position<returns_reject>::type>::type::value,
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

