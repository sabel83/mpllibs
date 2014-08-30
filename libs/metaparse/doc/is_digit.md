# is_digit

## Synopsis

```cpp
namespace util
{
  template <class C>
  struct is_digit;
}
```

This is a [lazy template metafunction](lazy_metafunction.html) that supports
[currying](currying.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`C`</td>
    <td>[boxed](boxed_value.html) character value</td>
  </tr>
</table>

## Description

Checks if `C` is a digit value or not. Returns a boxed boolean value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_digit.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
is_digit<boost::mpl::char_<'0'>>::type
is_digit<>::apply<boost::mpl::char_<'0'>>::type
boost::mpl::true_
```

The following expressions are also equivalent:

```cpp
is_digit<>::apply<c>::type
boost::mpl::false_
```

## Example

```cpp
#include <mpllibs/metaparse/util/is_digit.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_char
{
  using type = std::integral_constant<char, '0'>;
};

static_assert(
  util::is_digit<std::integral_constant<char, '0'>>::type::value,
  "digit character should be a digit"
);

static_assert(
  !util::is_digit<std::integral_constant<char, 'x'>>::type::value,
  "letter should not be a digit"
);

static_assert(
  util::is_digit<>::type::apply<std::integral_constant<char, '0'>>::type::value,
  "it should support currying"
);

static_assert(
  util::is_digit<returns_char>::type::value,
  "it should support lazy evaluation"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

