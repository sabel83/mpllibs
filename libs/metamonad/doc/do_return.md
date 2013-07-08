# do_return

## Synopsis

```cpp
template <class Value>
struct do_return
  // unspecified
;
```

## Description

Template expression that can be used inside a [`do_`](do_.html) block.
`do_return` evaluates [`return_`](return_.html)`<MonadTag, Value>` using the
`MonadTag` of the do block containing `do_return`.

## Header

```cpp
#include <mpllibs/metamonad/do.hpp>
```

## Example

```cpp
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

do_<exception_tag>::apply<
  do_return<int_<13>>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



