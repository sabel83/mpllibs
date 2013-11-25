# is_lcase_letter

## Synopsis

```cpp
template <class C>
struct is_lcase_letter
{
  // unspecified
};
```

## Description

Checks if a character is a lower case letter. Returns a wrapped boolean value.
It supports currying.

## Header

```cpp
#include <mpllibs/metaparse/util/is_lcase_letter.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
boost::mpl::apply<is_lcase_letter<>, boost::mpl::char_<'a'>>::type
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_lcase_letter<>, boost::mpl::char_<'z'>>::type
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_lcase_letter<>, c>::type
boost::mpl::false_
```

## Example

```cpp
is_lcase_letter<boost::mpl::char_<'x'>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


