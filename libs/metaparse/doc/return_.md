# return_

## Synopsis

```cpp
template <class C>
struct return_;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

`return_` accepts every input. The result of parsing is `C`, the remaining
string is the input string.

## Header

```cpp
#include <mpllibs/metaparse/return_.hpp>
```

## Expression semantics

For any `c` class, `s` compile-time string and `pos` source position the
following are equivalent

```cpp
get_result<return_<c>::apply<s, pos>>::type

c
```

```cpp
get_remaining<return_<c>::apply<s, pos>>::type

s
```

```cpp
get_position<return_<c>::apply<s, pos>>::type

pos
```

## Example

```cpp
#include <mpllibs/metaparse/return_.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/one_of.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using default_value = std::integral_constant<int, 13>;

using optional_number = one_of<int_, return_<default_value>>;

static_assert(
  get_result<
    optional_number::apply<MPLLIBS_STRING("11"), start>
  >::type::value == 11,
  "when a number is provided, it is the result of parsing"
);

static_assert(
  get_result<
    optional_number::apply<MPLLIBS_STRING(""), start>
  >::type::value == 13,
  "when no number is provided, the default value is the result of parsing"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

