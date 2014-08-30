# empty

## Synopsis

```cpp
template <class Result>
struct empty;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`Result`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

It accepts empty input only. The result of parsing is the `Result`
argument.

## Header

```cpp
#include <mpllibs/metaparse/empty.hpp>
```

## Expression semantics

For any `c` class the following are equivalent:

```cpp
empty<c>

except<one_char, c, error::end_of_input_expected>
```

## Example

```cpp
#include <mpllibs/metaparse/empty.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using want_empty = empty<MPLLIBS_STRING("result")>;

static_assert(
  !is_error<want_empty::apply<MPLLIBS_STRING(""), start>>::type::value,
  "empty accepts the empty input"
);

static_assert(
  is_error<want_empty::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "empty should reject non-empty input"
);

static_assert(
  std::is_same<
    get_result<want_empty::apply<MPLLIBS_STRING(""), start>>::type,
    MPLLIBS_STRING("result")
  >::type::value,
  "the result of parsing should be the given value"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

