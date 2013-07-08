# eval_guard

## Synopsis

```cpp
template <class T>
struct eval_guard
{
  // unspecified
};
```

## Description

It can be used to protect an angle-bracket expression from being evaluated but
make pattern matching and let substitutions recurse into it.

## Header

```cpp
#include <mpllibs/metamonad/eval_guard.hpp>
```

## Example

```cpp
case_< eval_guard<boost::mpl::plus<x, y>>,
  matches<
    eval_guard<boost::mpl::plus<boost::mpl::int_<11>, boost::mpl::int_<2> > >,
    boost::mpl::int_<13>
  >
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



