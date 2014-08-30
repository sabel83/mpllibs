# if_

## Synopsis

```cpp
template <class P, class T, class F>
struct if_;
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
  <tr>
    <td>`F`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

`if_` always accepts the input string. The result of parsing is `T`, when `P`
accepts the input and `F` otherwise.

## Header

```cpp
#include <mpllibs/metaparse/if_.hpp>
```

## Expression semantics

For any `p` parser, `t` and `f` classes the following are equivalent:

```cpp
if_<p, t, f>

one_of<last_of<p, return_<t>>, return_<f>>
```

## Example

```cpp
#include <mpllibs/metaparse/if_.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using int11 = std::integral_constant<int, 11>;
using int13 = std::integral_constant<int, 13>;

static_assert(
  get_result<
    if_<int_, int11, int13>::apply<MPLLIBS_STRING("1234"), start>
  >::type::value == 11,
  "When the int_ parser succeeds, the result of parsing should be 11"
);

static_assert(
  get_result<
    if_<int_, int11, int13>::apply<MPLLIBS_STRING("foo"), start>
  >::type::value == 13,
  "When the int_ parser fails, the result of parsing should be 13"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


