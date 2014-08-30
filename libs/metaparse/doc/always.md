# always

## Synopsis

```cpp
template <class P, class T>
struct always;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`T`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

It accepts an input if and only if `P` accepts it, but the result of parsing
will be `T` instead of the result `P` returned.

## Header

```cpp
#include <mpllibs/metaparse/always.hpp>
```

## Expression semantics

For any `p` parser and `t` class the following are equivalent:

```cpp
always<p, t>

last_of<p, return_<t>>
```

## Example

```cpp
#include <mpllibs/metaparse/always.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using always13 = always<lit_c<'x'>, std::integral_constant<int, 13>>;

static_assert(
  !is_error<always13::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "always13 should accept x"
);

static_assert(
  std::is_same<
    get_result<always13::apply<MPLLIBS_STRING("x"), start>>::type,
    std::integral_constant<int, 13>
  >::type::value,
  "the result of parsing should be the integral_constant type"
);

static_assert(
  is_error<always13::apply<MPLLIBS_STRING("y"), start>>::type::value,
  "always13 should reject characters other than x"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


