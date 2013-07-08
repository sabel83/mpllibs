# set

## Synopsis

```cpp
template <class Name, class F>
struct set
  // unspecified
;
```

## Description

Template expression that can be used inside a [do block](do_.html). `F` is a
nullary metafunction returning a monadic value. `set` binds the result of `F` to
`Name` in the rest of the do block. On how the binding works, see
[`let`](let.html).

## Header

```cpp
#include <mpllibs/metamonad/do.hpp>
```

## Example

```cpp
using boost::mpl::int_;
using namespace mpllibs::metamonad::name;

do_<exception_tag>::apply<
  set<r, may_fail1<int_<13>>,
  may_fail2<r>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



