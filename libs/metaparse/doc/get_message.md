# get_message

## Synopsis

```cpp
template <class E>
struct get_message;
```

This is a [lazy template metafunction](lazy_metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`E`</td>
    <td>[reject](reject.html) value</td>
  </tr>
</table>

## Description

Returns the error message of a parsing failure.

## Header

```cpp
#include <mpllibs/metaparse/get_message.hpp>
```

## Example

```cpp
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/reject.hpp>
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
    sample_error,
    get_message<reject<sample_error, start>>::type
  >::type::value,
  "It should return the message"
);

static_assert(
  std::is_same<sample_error, get_message<returns_reject>::type>::type::value,
  "It should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

