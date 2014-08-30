# is_whitespace

## Synopsis

```cpp
namespace util
{
  template <class C>
  struct is_whitespace;
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

Checks if `C` is a whitespace character. Returns a boxed boolean value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_whitespace.hpp>
```

## Expression semantics

For any `C` nullary template metafunction returning a wrapped character value
the following are equivalent:

```cpp
is_whitespace<C>::type
is_whitespace<>::type::apply<C>::type
is_whitespace_c<C::type::value>::type
```

## Example

```cpp
#include <mpllibs/metaparse/util/is_whitespace.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_char
{
  using type = std::integral_constant<char, ' '>;
};

static_assert(
  util::is_whitespace<std::integral_constant<char, ' '>>::type::value,
  "a space should be a whitespace character"
);

static_assert(
  !util::is_whitespace<std::integral_constant<char, '0'>>::type::value,
  "a number should not be a whitespace character"
);

static_assert(
  util::is_whitespace<>::type
    ::apply<std::integral_constant<char, '\t'>>::type::value,
  "it should support currying"
);

static_assert(
  util::is_whitespace<returns_char>::type::value,
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

