# iterate

## Synopsis

```cpp
template <class P, class N>
struct iterate;
```

This is a [parser combinator](parser_combinator.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
  <tr>
    <td>`N`</td>
    <td>[boxed](boxed_value.html) non-negative integer value</td>
  </tr>
</table>

## Description

It applies `P` on the input string `N` times. The result of parsing is a
sequence of the results of the individual applications of `P`. `P` has to accept
the input `N` times for `iterate` to accept it.

## Header

```cpp
#include <mpllibs/metaparse/iterate.hpp>
```

## Expression semantics

For any `p` parser, `n` wrapped integer the following are equivalent:

```cpp
iterate<p, n>

iterate_c<p, n::type::value>
```

## Example

```cpp
#include <mpllibs/metaparse/iterate.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/char.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  boost::mpl::equal<
    boost::mpl::vector<
      boost::mpl::char_<'1'>,
      boost::mpl::char_<'2'>,
      boost::mpl::char_<'3'>
    >,
    get_result<
      iterate<digit, std::integral_constant<int, 3>>::apply<
        MPLLIBS_STRING("123"),
        start
      >
    >::type
  >::type::value,
  "the result should be the sequence of the individual applications of digit"
);

static_assert(
  boost::mpl::equal<
    boost::mpl::vector<
      boost::mpl::char_<'1'>,
      boost::mpl::char_<'2'>,
      boost::mpl::char_<'3'>
    >,
    get_result<
      iterate<digit, std::integral_constant<int, 3>>::apply<
        MPLLIBS_STRING("1234"),
        start
      >
    >::type
  >::type::value,
  "only three iterations should be made"
);

static_assert(
  is_error<
    iterate<digit, std::integral_constant<int, 3>>::apply<
      MPLLIBS_STRING("12"),
      start
    >
  >::type::value,
  "it should fail when digit can not be applied three times"
);

```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

