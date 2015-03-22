# accept_when

## Synopsis

```cpp
template <class P, class Pred, class Msg>
struct accept_when;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`Pred`</td>
    <td>[predicate](predicate.html)</td>
  </tr>
  <tr>
    <td>`Msg`</td>
    <td>[parsing error message](parsing_error_message.html)</td>
  </tr>
</table>

## Description

It parses the input with `P`. When `P` rejects the input, `accept_when` rejects
it as well. When `P` accepts it, `accept_when` evaluates `Pred` with the result
of parsing the input with `P`. When `Pred` returns `true`, `accept_when` accepts
the input and the result of parsing will be what `P` returned. Otherwise
`accept_when` rejects the input and `Msg` is used as the error reason.

## Header

```cpp
#include <mpllibs/metaparse/accept_when.hpp>
```

## Expression semantics

For any `p` parser, `pred` predicate, `msg` parsing error message, `s`
compile-time string and `pos` source position

```cpp
accept_when<p, pred, msg>i::apply<s, pos>::type
```

is equivalent to

```cpp
p::apply<s, pos>::type
```

when `boost::mpl::apply<p, s, pos>` doesn't return an error and
`pred::apply<get_result<p::apply<s, pos>>>::type` is `true`. Otherwise it is
equivalent to

```cpp
fail<msg>
```

## Example

```cpp
#include <mpllibs/metaparse/accept_when.hpp>
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/util/is_digit.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/define_error.hpp>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(digit_expected, "Digit expected");

using accept_digit = accept_when<one_char, util::is_digit<>, digit_expected>;

static_assert(
  !is_error<accept_digit::apply<MPLLIBS_STRING("0"), start>>::type::value,
  "accept_digit should accept a digit"
);

static_assert(
  get_result<
    accept_digit::apply<MPLLIBS_STRING("0"), start>
  >::type::value == '0',
  "the result of parsing should be the character value"
);

static_assert(
  is_error<accept_digit::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "accept_digit should reject a character that is not a digit"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

