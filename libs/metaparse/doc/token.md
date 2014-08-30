# token

## Synopsis

```cpp
template <class P>
struct token;
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

`token` parses the input using `P` when it succeeds, `token` consumes all
whitespaces afterwards. The result of parsing is the result of `P`.

## Header

```cpp
#include <mpllibs/metaparse/token.hpp>
```

## Expression semantics

For any `p` parser the following are equivalent:

```cpp
token<p>

first_of<p, spaces>
```

## Example

```cpp
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using int_token = token<int_>;

static_assert(
  get_result<int_token::apply<MPLLIBS_STRING("13 "), start>>::type::value,
  "the result of int_token is the number"
);

static_assert(
  std::is_same<
    MPLLIBS_STRING(""),
    get_remaining<int_token::apply<MPLLIBS_STRING("13 "), start>>::type
  >::type::value,
  "token consumes whitespaces after the number"
);

static_assert(
  get_result<int_token::apply<MPLLIBS_STRING("13"), start>>::type::value,
  "whitespaces after the number are optional"
);

static_assert(
  is_error<int_token::apply<MPLLIBS_STRING("foo"), start>>::type::value,
  "when there is no number, token fails"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

