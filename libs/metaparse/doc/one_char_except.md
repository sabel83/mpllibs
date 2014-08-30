# one_char_except

## Synopsis

```cpp
template <class C1, class C2, /* ... */, class Cn>
struct one_char_except;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C1`..`Cn`</td>
    <td>[boxed](boxed_value.html) character values</td>
  </tr>
</table>

## Description

`one_char_except` accepts one character except any of `C1` ... `Cn`. When the
input is empty or begins with one of the non-accepted characters,
`one_char_except` rejects the input. Otherwise it accepts the input and the
result of parsing is the character value.

The maximum number of template arguments this class can have is the value the
macro `MPLLIBS_LIMIT_ONE_CHAR_EXCEPT_SIZE` expands to. Its default value is 10.

## Header

```cpp
#include <mpllibs/metaparse/one_char_except.hpp>
```

## Expression semantics

For any `c1`, ..., `cn` boxed characters the following are equivalent

```cpp
one_char_except<c1, ..., cn>

one_char_except_c<c1::type::value, ..., cn::type::value>
```

## Example

```cpp
#include <mpllibs/metaparse/one_char_except.hpp>
#include <mpllibs/metaparse/lit_c.hpp>
#include <mpllibs/metaparse/middle_of.hpp>
#include <mpllibs/metaparse/any.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/char.hpp>
#include <boost/mpl/equal.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

using string_literal_parser =
  middle_of<
    lit_c<'"'>,
    any<one_char_except<std::integral_constant<char, '"'>>>,
    lit_c<'"'>
  >;

static_assert(
  boost::mpl::equal<
    boost::mpl::vector<
      boost::mpl::char_<'h'>,
      boost::mpl::char_<'e'>,
      boost::mpl::char_<'l'>,
      boost::mpl::char_<'l'>,
      boost::mpl::char_<'o'>
    >,
    get_result<
      string_literal_parser::apply<MPLLIBS_STRING("\"hello\""), start>
    >::type
  >::type::value,
  "it should return the content of the string literal"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

