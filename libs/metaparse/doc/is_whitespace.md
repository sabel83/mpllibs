# is_whitespace

## Synopsis

```cpp
struct is_whitespace
{
  template <class C>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Checks if a character is a whitespace character.
Returns a wrapped boolean value.

## Header

```cpp
#include <mpllibs/metaparse/util/is_whitespace.hpp>
```

## Expression semantics

The following expressions are equivalent:

```cpp
boost::mpl::apply<is_whitespace, boost::mpl::char_<' '> >
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_whitespace, boost::mpl::char_<'\t'> >
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_whitespace, boost::mpl::char_<'\r'> >
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_whitespace, boost::mpl::char_<'\n'> >
boost::mpl::true_
```

```cpp
boost::mpl::apply<is_whitespace, c>
boost::mpl::false_
```

## Example

```cpp
boost::mpl::apply<is_whitespace, boost::mpl::char_<' '> >
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

