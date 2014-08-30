# is_whitespace_c

## Synopsis

```cpp
namespace util
{
  template <char C>
  struct is_whitespace_c;
}
```

This is a template class similar to a [template metafunction](metafunction.html)
but taking a `char` value as argument.

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`D`</td>
    <td>`char` value</td>
  </tr>
</table>

## Description

Checks if `C` is a whitespace character. Returns a boxed boolean value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_whitespace_c.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
is_whitespace_c<' '>::type
boost::mpl::true_
```

```cpp
is_whitespace_c<'\t'>::type
boost::mpl::true_
```

```cpp
is_whitespace_c<'\r'>::type
boost::mpl::true_
```

```cpp
is_whitespace_c<'\n'>::type
boost::mpl::true_
```

For any `c` character other than the above listed ones the following are
equivalent:

```cpp
is_whitespace_c<c>::type
boost::mpl::false_
```

## Example

```cpp
#include <mpllibs/metaparse/util/is_whitespace_c.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  util::is_whitespace_c<' '>::type::value,
  "a space should be a whitespace character"
);

static_assert(
  !util::is_whitespace_c<'0'>::type::value,
  "a number should not be a whitespace character"
);

```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

