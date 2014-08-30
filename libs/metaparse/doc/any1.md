# any1

## Synopsis

```cpp
template <class P>
struct any1;
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

It applies `P` on the input string repeatedly as long as the parser accepts the
input. The result of parsing is a sequence of the results of the individual
applications of `P`.

When `P` rejects the input for the first time, `any1` rejects it as well.
At least one successful application of `P` is required for `any1` to accept the
input.

## Header

```cpp
#include <mpllibs/metaparse/any1.hpp>
```

## Expression semantics

For any `p` parser the following are equivalent:

```cpp
any1<p>

last_of<look_ahead<p>, any<p>>
```

## Example

```cpp
#include <mpllibs/metaparse/any1.hpp>
#include <mpllibs/metaparse/digit_val.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <boost/mpl/equal.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/int.hpp>

using namespace mpllibs::metaparse;

using digits = any1<digit_val>;

static_assert(
  boost::mpl::equal<
    get_result<digits::apply<MPLLIBS_STRING("1234"), start>>::type,
    boost::mpl::vector<
      boost::mpl::int_<1>,
      boost::mpl::int_<2>,
      boost::mpl::int_<3>,
      boost::mpl::int_<4>
    >
  >::type::value,
  "the result of parsing should be the list of digit values"
);

static_assert(
  is_error<digits::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "any1 should reject the input when it can't parse anything with digit_val"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


