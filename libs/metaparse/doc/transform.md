# transform

## Synopsis

```cpp
template <class P, class T>
struct transform;
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
    <td>
      [template metafunction class](metafunction_class.html) taking one argument
    </td>
  </tr>
</table>

## Description

`transform` parses the input using `P` and transforms the result `P` returns
with `T`. The result of parsing is what `T` returns. When `P` fails, the faliure
is returned unchanged.

## Header

```cpp
#include <mpllibs/metaparse/transform.hpp>
```

## Expression semantics

For any `p` parser, `t` metafunction class accepting one argument, `s`
compile-time string and `pos` source position

```cpp
get_result<transform<p, t>::apply<s, pos>>::type
```

is equivalent to

```cpp
t::apply<get_result<p::apply<s, pos>>::type>::type
```

When `p::apply<s, pos>` doesn't return an error. The combinator returns the
error otherwise.

## Example

```cpp
#include <mpllibs/metaparse/transform.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <mpllibs/metaparse/util/digit_to_int.hpp>

using namespace mpllibs::metaparse;

using digit_value = transform<digit, util::digit_to_int<>>;

static_assert(
  !is_error<digit_value::apply<MPLLIBS_STRING("0"), start>>::type::value,
  "digit_val should accept a digit"
);

static_assert(
  is_error<digit_value::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "digit_val should reject a character"
);

static_assert(
  get_result<digit_value::apply<MPLLIBS_STRING("0"), start>>::type::value == 0,
  "the result of parsing should be the int value"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

