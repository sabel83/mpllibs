# is_ucase_letter

## Synopsis

```cpp
struct is_ucase_letter
{
  template <class C>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Checks if a character is an upper case letter. Returns a wrapped boolean value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_ucase_letter.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
boost::mpl::apply<is_ucase_letter, boost::mpl::char_<'A'>>
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_ucase_letter, boost::mpl::char_<'Z'>>
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_ucase_letter, c>
boost::mpl::false_
```

## Example

```cpp
boost::mpl::apply<is_lcase_letter, boost::mpl::char_<'X'>>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


