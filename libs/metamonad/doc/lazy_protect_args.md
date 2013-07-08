# lazy_protect_args

## Synopsis

```cpp
template <class Exp>
struct lazy_protect_args
{
  // unspecified
};
```

## Description

`Exp` is an angly bracket expression of metafunctions calling each other with
other angly bracket expressions as arguments. When `lazy_protect_args` is used
inside [`lazy`](lazy.html), the content of `lazy_protect_args` is not
transformed by `lazy`, but `Exp` itself is evaluated before it is passed to the
metafunction calling it. When `lazy_protect_args` is used outside of `lazy`, it
does not change the meaning of the wrapped expression.

## Header

```cpp
#include <mpllibs/metamonad/lazy_protect_args.hpp>
```

## Expression semantics

For any `t1`, `t2` template classes, `i >= 0`, `j >= 0`, `k >= 0` and
`a1`, ..., `ai`, `b1`, ..., `bj`, `c1`, ..., `ck` classes, the following are
equivalent

```cpp
lazy<t1<a1, ..., ai, lazy_protect_args<t2<b1, ..., bj>>, c1, ..., ck>>::type
lazy<t1<a1, ..., ai, t2<already_lazy<b1>, ..., already_lazy<bj>>, c1, ..., ck>
  ::type
```

```cpp
lazy_protect_args<t2<b1, ..., bj>>::type
t2<b1, ..., bj>::type
```

## Example

```cpp
using namespace mpllibs::metamonad::name;

lazy<
  mpl::plus<
    lazy_protect_args<eval_let<x, mpl::int_<13>, mpl::times<x, x>>>,
    mpl::int_<11>
  >
>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



