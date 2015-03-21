# lit

## Synopsis

```cpp
template <class C>
struct lit;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C`</td>
    <td>[boxed](boxed_value.html) character value</td>
  </tr>
</table>

## Description

Parser accepting only the `C` character. The result of parsing is the accepted
character.

## Header

```cpp
#include <mpllibs/metaparse/lit.hpp>
```

## Expression semantics

For any `c` boxed character the following are equivalent:

```cpp
lit<c>

accept_when<
  one_char,
  boost::mpl::lambda<boost::mpl::equal_to<boost::mpl::_1, c>>::type,
  error::literal_expected<c::type::value>
>
```

## Example

```cpp
#include <mpllibs/metaparse/lit.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  is_error<lit<std::integral_constant<char, 'x'>>::apply<MPLLIBS_STRING("a"), start>>::type::value,
  "a different character should be an error"
);

static_assert(
  is_error<lit<std::integral_constant<char, 'x'>>::apply<MPLLIBS_STRING(""), start>>::type::value,
  "empty input should be an error"
);

static_assert(
  get_result<lit<std::integral_constant<char, 'x'>>::apply<MPLLIBS_STRING("x"), start>>::type::value == 'x',
  "result of parsing should be the accepted character"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

