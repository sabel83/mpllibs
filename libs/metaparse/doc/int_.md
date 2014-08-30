# int_

## Synopsis

```cpp
struct int_;
```

This is a [parser](parser.html).

## Description

It accepts a non-empty sequence of characters in the range `0-9`. The result of
the parser is the decimal value represented by the accepted character sequence.

## Header

```cpp
#include <mpllibs/metaparse/int_.hpp>
```

## Expression semantics

The following are equivalent:

```cpp
int_

foldl1<
  digit_val,
  boost::mpl::int_<0>,
  boost::mpl::lambda<
    boost::mpl::plus<
      boost::mpl::times<boost::mpl::_2, boost::mpl::int_<10>>,
      boost::mpl::_1
    >
  >::type
>
```

## Example

```cpp
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

using namespace mpllibs::metaparse;

static_assert(
  get_result<int_::apply<MPLLIBS_STRING("13"), start>>::type::value == 13,
  "It should parse an integer value"
);

static_assert(
  is_error<int_::apply<MPLLIBS_STRING("six"), start>>::type::value,
  "It should reject the input if it is not a number"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

