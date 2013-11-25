# space

## Synopsis

```cpp
struct space
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting one white space character. The result of parsing is undefined.

## Header

```cpp
#include <mpllibs/metaparse/space.hpp>
```

## Expression semantics

The followin are equivalent:

```cpp
space

accept_when<
  one_char,
  util::is_whitespace<>,
  // unspecified
>
```

## Example

```cpp
typedef
  get_remaining<boost::mpl::apply<space, MPLLIBS_STRING(" abc"), start>>::type
  abc;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


