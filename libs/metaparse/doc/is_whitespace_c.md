# is_whitespace_c

## Synopsis

```cpp
template <char C>
struct is_whitespace_c
{
  // unspecified
};
```

## Description

Checks if a character is a whitespace character.
Returns a wrapped boolean value.

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
is_whitespace_c<' '>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

