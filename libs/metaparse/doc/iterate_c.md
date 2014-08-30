# iterate_c

## Synopsis

```cpp
template <class P, int N>
struct iterate_c;
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
    <td>non-negative integer value</td>
  </tr>
</table>

## Description

It applies `P` on the input string `N` times. The result of parsing is a
sequence of the results of the individual applications of `P`. `P` has to accept
the input `N` times for `iterate_c` to accept it.

## Header

```cpp
#include <mpllibs/metaparse/iterate_c.hpp>
```

## Expression semantics

For any `p` parser, `n` integer value the following are equivalent:

```cpp
iterate_c<p, n>

sequence<
  p, // 1.
  p, // 2.
  // ...
  p  // n.
>
```

## Example

```cpp
#include <mpllibs/metaparse/iterate_c.hpp>
#include <mpllibs/metaparse/digit.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/vector.hpp>
#include <boost/mpl/equal.hpp>
#include <boost/mpl/char.hpp>

using namespace mpllibs::metaparse;

static_assert(
  boost::mpl::equal<
    boost::mpl::vector<
      boost::mpl::char_<'1'>,
      boost::mpl::char_<'2'>,
      boost::mpl::char_<'3'>
    >,
    get_result<iterate_c<digit, 3>::apply<MPLLIBS_STRING("123"), start>>::type
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
    get_result<iterate_c<digit, 3>::apply<MPLLIBS_STRING("1234"), start>>::type
  >::type::value,
  "only three iterations should be made"
);

static_assert(
  is_error<
    iterate_c<digit, 3>::apply<MPLLIBS_STRING("12"), start>
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

