# MPLLIBS_DEFINE_ERROR

## Synopsis

```cpp
#define MPLLIBS_DEFINE_ERROR(name, msg) \
  // unspecified
```

This is a macro.

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`name`</td>
    <td>identifier token</td>
  </tr>
  <tr>
    <td>`msg`</td>
    <td>string literal</td>
  </tr>
</table>

## Description

Macro for defining a class which can be used as error messages returned by
parsers. `name` is the name of the class representing the error message and
`msg` is a string literal containing the description of the error.

## Header

```cpp
#include <mpllibs/metaparse/define_error.hpp>
```

## Expression semantics

For any `n` name and `m` string literal, given the following is defined:

```cpp
MPLLIBS_DEFINE_ERROR(n, m);
```

the following pairs of expressions are equivalent:

```cpp
n::get_value()
std::string(m)
```

```cpp
n::type
n
```

## Example

```cpp
#include <mpllibs/metaparse/define_error.hpp>
#include <mpllibs/metaparse/any1.hpp>
#include <mpllibs/metaparse/letter.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/token.hpp>
#include <mpllibs/metaparse/sequence.hpp>
#include <mpllibs/metaparse/change_error_message.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/get_message.hpp>
#include <mpllibs/metaparse/string.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

MPLLIBS_DEFINE_ERROR(age_expected, "Age expected");

using name_token = token<any1<letter>>;
using age_token = token<change_error_message<int_, age_expected>>;

using name_age = sequence<name_token, age_token>;

static_assert(
  std::is_same<
    age_expected,
    get_message<name_age::apply<MPLLIBS_STRING("Joe "), start>>::type
  >::type::value,
  "the error message should be age_expected when the age is missing"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

