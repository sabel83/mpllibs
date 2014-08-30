# is_ucase_letter

## Synopsis

```cpp
namespace util
{
  template <class C>
  struct is_ucase_letter;
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

Checks if `C` is an upper case letter. Returns a boxed boolean value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_ucase_letter.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
is_ucase_letter<>::apply<boost::mpl::char_<'A'>>::type
boost::mpl::true_
```

```cpp
is_ucase_letter<>::apply<boost::mpl::char_<'Z'>>::type
boost::mpl::true_
```

```cpp
is_ucase_letter<>::apply<c>::type
boost::mpl::false_
```

## Example

```cpp
#include <mpllibs/metaparse/util/is_ucase_letter.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_char
{
  using type = std::integral_constant<char, 'A'>;
};

static_assert(
  util::is_ucase_letter<std::integral_constant<char, 'A'>>::type::value,
  "A should be an upper case letter"
);

static_assert(
  !util::is_ucase_letter<std::integral_constant<char, 'a'>>::type::value,
  "a should not be an upper case letter"
);

static_assert(
  util::is_ucase_letter<>::type
    ::apply<std::integral_constant<char, 'A'>>::type::value,
  "it should support currying"
);

static_assert(
  util::is_ucase_letter<returns_char>::type::value,
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

