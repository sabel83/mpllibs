# verify_printf_arguments

## Synopsis

```cpp
template <class FormatString, class ArgumentTypes>
struct verify_printf_arguments
{
  // unspecified
};
```

## Description

`ArgumentTypes` is a sequence of types representing the types of arguments
passed to a `printf` function, `FormatString` is a string representing a
`printf` format string. The function returns true when the list of argument
types is valid for the format string and false otherwise.

## Header

```cpp
#include <mpllibs/safe_printf/verify_printf_arguments.hpp>
```

## Expression semantics

For any `s` `mpllibs::metaparse::string` and `t` sequence of types:

```cpp
mpllibs::safe_printf::verify_printf_arguments<s, t>::type::value
```

is `true` when the types `t` contains are correct according to `s` and `false`
otherwise.

## Example

```cpp
BOOST_STATIC_ASSERT((
  mpllibs::safe_printf::verify_printf_arguments<
    MPLLIBS_STRING("%d %d\n"),
    boost::mpl::list<int, int>
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




