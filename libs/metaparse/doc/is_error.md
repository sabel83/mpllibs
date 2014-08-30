# is_error

## Synopsis

```cpp
template <class C>
struct is_error;
```


This is a [lazy template metafunction](lazy_metafunction.html) that supports
[currying](currying.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C`</td>
    <td>[accept](accept.html) or [reject](reject.html) value</td>
  </tr>
</table>

## Description

Determines if `C` is a parsing error or not. Returns a [boxed](boxed_value.html)
boolean value.

## Header

```cpp
#include <mpllibs/metaparse/is_error.hpp>
```

## Expression semantics

For any `e` parsing error `is_error<c>::type` is a wrapped compile-time `true`
value, for any other `c` class `is_error<c>::type` is a wrapped compile-time
`false` value.

## Example

```cpp
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/accept.hpp>
#include <mpllibs/metaparse/reject.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/define_error.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(sample_error, "Sample error message");

struct returns_reject
{
  typedef reject<sample_error, start> type;
};

static_assert(
  !is_error<
    accept<std::integral_constant<int, 13>, MPLLIBS_STRING("foo"), start>
  >::type::value,
  "an accept should not be an error"
);

static_assert(
  is_error<reject<sample_error, start>>::type::value,
  "an reject should be an error"
);

static_assert(
  is_error<>::type::apply<reject<sample_error, start>>::type::value,
  "it should support currying"
);

static_assert(
  is_error<returns_reject>::type::value,
  "it should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

