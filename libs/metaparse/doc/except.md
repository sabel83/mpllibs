# except

## Synopsis

```cpp
template <class P, class Result, class ErrorMsg>
struct except;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`Result`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
  <tr>
    <td>`ErrorMsg`</td>
    <td>[parsing error message](parsing_error_message.html)</td>
  </tr>
</table>

## Description

`except` accepts the input when `P` rejects it and the result of parsing is the
`Result` argument. When `P` accepts the input, `except` rejects it and the
reason is `ErrorMsg`.

## Header

```cpp
#include <mpllibs/metaparse/except.hpp>
```

## Expression semantics

For any `p` parser, `c` class, `msg` parsing error message, `s` compile-time
string and `pos` source position the following are equivalent

```cpp
get_result<except<p, c, msg>, s, pos>::type
c
```

```cpp
get_remaining<except<p, c, msg>, s, pos>::type
s
```

```cpp
get_position<except<p, c, msg>, s, pos>::type
pos
```

when `p` rejects the input. The result of the parser is an error with the error
message `msg` otherwise.

## Example

```cpp
#include <mpllibs/metaparse/except.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/define_error.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(number_is_not_allowed, "numbers are not allowed here");

using except_int =
  except<int_, std::integral_constant<int, 1>, number_is_not_allowed>;

static_assert(
  get_result<except_int::apply<MPLLIBS_STRING("foo"), start>>::type::value == 1,
  "it should accept the input when it is not an integer"
);

static_assert(
  std::is_same<
    number_is_not_allowed,
    get_message<except_int::apply<MPLLIBS_STRING("13"), start>>::type
  >::type::value,
  "it should reject the input when it is an integer"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

