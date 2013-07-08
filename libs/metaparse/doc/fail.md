# fail

## Synopsis

```cpp
template <class Msg>
struct fail
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser rejecting every input.

## Header

```cpp
#include <mpllibs/metaparse/fail.hpp>
```

## Expression semantics

For any `msg` error message and `s` compile-time string

```cpp
boost::mpl::apply<fail<msg>, s>::type
```

returns an error with `msg` as the error message.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


