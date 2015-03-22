# transform_error_message

## Synopsis

```cpp
template <class P, class F>
struct transform_error_message;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`F`</td>
    <td>
      [template metafunction class](metafunction_class.html) taking one argument
    </td>
  </tr>
</table>

## Description

It parses the input with `P`. When this succeeds, the result of parsing with
`transform_error_message` will be the result of parsing with `P`. When it fails,
the error `P` returns is forwarded to the caller of `transform_error_message`,
but the message of it is transformed with `F`.

## Header

```cpp
#include <mpllibs/metaparse/transform_error_message.hpp>
```

## Expression semantics

For any `p` parser and `f` metafunction class accepting one argument

```cpp
transform_error_message<p, f>::apply<s, pos>
```

is equivalent to `p::apply<s, pos>` when `p` accepts the input.
It is equivalent to
`reject<boost::mpl::apply<f, get_message<p::apply<s, pos>>::type>, get_position<p::apply<s, pos>>>`
otherwise.

## Example

```cpp
#include <mpllibs/metaparse/transform_error_message.hpp>
#include <mpllibs/metaparse/any1.hpp>
#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/keyword.hpp>
#include <mpllibs/metaparse/last_of.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/define_error.hpp>
#include <mpllibs/metaparse/reject.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(name_expected, "Name expected");

struct return_name_expected
{
  typedef return_name_expected type;

  template <class>
  struct apply : name_expected {};
};

using keyword_name = token<keyword<MPLLIBS_STRING("name")>>;
using name_token = token<any1<letter>>;

using name_parser =
  last_of<
    keyword_name,
    transform_error_message<name_token, return_name_expected>
  >;

static_assert(
  !is_error<name_parser::apply<MPLLIBS_STRING("name Bela"), start>>::type::value,
  "name_parser should accept \"name <a name>\""
);

static_assert(
  is_error<name_parser::apply<MPLLIBS_STRING("name ?"), start>>::type::value,
  "name_parser should reject input when name is a question mark"
);

static_assert(
  std::is_same<
    get_message<name_parser::apply<MPLLIBS_STRING("name ?"), start>>::type,
    name_expected
  >::type::value,
  "the error message should be the one specified by change_error_message"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

