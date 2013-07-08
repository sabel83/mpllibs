# spaces

## Synopsis

```cpp
struct spaces
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting any number of whitespace characters. It requires at least one
to be present.

## Header

```cpp
#include <mpllibs/metaparse/spaces.hpp>
```

## Expression semantics

```cpp
spaces
```

is equivalent to

```cpp
mpllibs::metaparse::any1<mpllibs::metaparse::space>
```

## Example

```cpp
typedef
  // ...
  some_string;

typedef
  mpllibs::metaparse::get_remaining<
    boost::mpl::apply<spaces, some_string, mpllibs::metaparse::start>
  >::type
  some_string_without_leading_whitespaces;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


