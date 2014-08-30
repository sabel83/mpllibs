# unless_error

## Synopsis

```cpp
template <class T, class NotErrorCase>
struct unless_error;
```

This is a [lazy template metafunction](lazy_metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`T`</td>
    <td>[accept](accept.html) or [reject](reject.html) value</td>
  </tr>
  <tr>
    <td>`NotErrorCase`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

Checks if `T` is a parsing error or not. When it is, the result is `T`. When it
is not, the result is `NotErrorCase`.

## Header

```cpp
#include <mpllibs/metaparse/unless_error.hpp>
```

## Expression semantics

For any `t` and `c` classes the following are equivalent:

```cpp
unless_error<t, c>

boost::mpl::if_<is_error<t::type>::type, t, c>
```

## Example

```cpp
#include <mpllibs/metaparse/unless_error.hpp>
#include <mpllibs/metaparse/accept.hpp>
#include <mpllibs/metaparse/reject.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/define_error.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(sample_error, "Sample error message");

using accept1 =
  accept<std::integral_constant<int, 11>, MPLLIBS_STRING("foo"), start>;

using accept2 =
  accept<std::integral_constant<int, 13>, MPLLIBS_STRING("bar"), start>;

using reject1 = reject<sample_error, start>;

struct returns_accept1 { using type = accept1; };
struct returns_accept2 { using type = accept2; };

static_assert(
  std::is_same<accept2, unless_error<accept1, accept2>::type>::type::value,
  "it returns the second argument when the first argument is an accept"
);

static_assert(
  std::is_same<reject1, unless_error<reject1, accept2>::type>::type::value,
  "it returns the first argument when that is a reject"
);

static_assert(
  std::is_same<
    accept2,
    unless_error<returns_accept1, returns_accept2>::type
  >::type::value,
  "it supports lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

