# valid_arguments

## Synopsis

```cpp
template <class FormatString, class ArgumentTypes>
struct valid_arguments
{
  // unspecified
};
```

## Description

`ArgumentTypes` is a sequence of boxed types representing the types of arguments
passed to a `printf` function. `FormatString` is a string representing a
`printf` format string. The function returns true when the list of argument
types is valid for the format string and false otherwise.

## Header

```cpp
#include <mpllibs/safe_printf/valid_arguments.hpp>
```

## Expression semantics

For any `s` `boost::metaparse::string` and `t` sequence of boxed types:

```cpp
mpllibs::safe_printf::valid_arguments<s, t>::type::value
```

is `true` when the types `t` contains are correct according to `s` and `false`
otherwise.

## Example

```cpp
using mpllibs::metamonad::box;

BOOST_STATIC_ASSERT((
  mpllibs::safe_printf::valid_arguments<
    BOOST_METAPARSE_STRING("%d %d\n"),
    boost::mpl::list<box<int>, box<int>>
  >::type::value
));
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




