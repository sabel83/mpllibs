# apply

## Synopsis

```cpp
template <class F, class T1, ..., class Tn>
struct apply
{
  // unspecified
};
```

## Description

Lazy wrapper for `F::apply<T1, ..., Tn>`.

## Header

```cpp
#include <mpllibs/metamonad/apply.hpp>
```

## Expression semantics

For any `n` and `f` , `t1`, ..., `tn` types

```cpp
apply<f, t1, ..., tn>::type
```

is equivalent to

```cpp
f::type::apply<t1::type, ..., tn::type>::type
```

## Example

```cpp
using namespace mpllibs::metamonad::name;

apply<lambda_c<a, b, mpl::plus<a, b>>, mpl::int_<1>, mpl::int_<2>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



