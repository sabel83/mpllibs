# look_ahead

## Synopsis

```cpp
template <class P>
struct look_ahead;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
</table>

## Description

Parses the input using parser `P`. When `P` returns an error, `look_ahead`
returns the error. When `P` returns a result, `look_ahead` returns the result
without consuming anything from the input string.

## Header

```cpp
#include <mpllibs/metaparse/look_ahead.hpp>
```

## Expression semantics

For any `p` parser, `s` compile-time string and `pos` source position

```cpp
look_ahead<p>::apply<s, pos>
```

is equivalent to

```cpp
return_<get_result<p::apply<s, pos>>::type>::apply<s, pos>
```

when `p::apply<s, pos>` succeeds. It is

```cpp
p::apply<s, pos>
```

otherwise.

## Example

```cpp
#include <mpllibs/metaparse/look_ahead.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  get_result<
    look_ahead<int_>::apply<MPLLIBS_STRING("13"), start>
  >::type::value == 13,
  "it should return the same result as the wrapped parser"
);

static_assert(
  std::is_same<
    MPLLIBS_STRING("13"),
    get_remaining<
      look_ahead<int_>::apply<MPLLIBS_STRING("13"), start>
    >::type
  >::type::value,
  "it should not consume any input"
);

static_assert(
  is_error<look_ahead<int_>::apply<MPLLIBS_STRING("six"), start>>::type::value,
  "it should fail when the wrapped parser fails"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

