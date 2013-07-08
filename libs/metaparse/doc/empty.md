# empty

## Synopsis

```cpp
template <class Result>
struct empty
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser accepting empty input only. The result of parsing is the `Result`
argument.

## Header

```cpp
#include <mpllibs/metaparse/empty.hpp>
```

## Expression semantics

For any `c` class the following are equivalent:

```cpp
empty<c>

mpllibs::metaparse::except<
  mpllibs::metaparse::one_char,
  c,
  // unspecified
>
```

## Example

```cpp
typedef empty<int> end_of_input;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


