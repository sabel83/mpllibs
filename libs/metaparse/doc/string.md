# string

## Synopsis

```cpp
template <char C1, ..., char Cn>
struct string
{
  // unspecified
};
```

## Description

Compile-time data-structure describing a string object. These string objects are
compatible with `boost::mpl::string`, but they accept only individual characters
as arguments. When `constexpr` is available, they should be constructed using
the [`MPLLIBS_STRING`](MPLLIBS_STRING.html) macro.

The tag of the strings is [`string_tag`](string_tag.html).

*C++98*: The maximum length of these strings is controlled by the
`MPLLIBS_LIMIT_STRING_SIZE` macro.

*C++11*: The strings use variadic templates.

## Header

```cpp
#include <mpllibs/metaparse/string.hpp>
```

## Example

```cpp
typedef string<'H','e','l','l','o',' ','w','o','r','l','d'> hello_world;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



