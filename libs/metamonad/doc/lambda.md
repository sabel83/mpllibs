# lambda

## Synopsis

```cpp
template <class Name1, ..., class Namen, class F>
struct lambda
{
  template <class T1, ..., class Tn>
  struct apply
    // unspecified
  ;
};
```

## Description

`Name1`, ..., `Namen` are classes, `F` is a syntax. The `lambda` metafunction
class takes classes, `T1`, ..., `Tn` as arguments and produces a new nullary
metafunction. It binds `T1`, ..., `Tn` to the names `Name1`, ..., `Namen` in the
body of `F` using [`let`](let.html).

The arguments may be `_`, in which case the value of the argument is ignored and
no substitution happens.

The metafunction classes support currying as well. Applying less arguments to
the metafunction class as `n` produces a new metafunction class taking the
missing arguments. `F` is evaluated only when all arguments are provided.

## Header

```cpp
#include <mpllibs/metamonad/lambda.hpp>
```

## Expression semantics

For any `k > 0`, `n1` ... `nk` and `t1` ... `tk` classes and `f` nullary
metafunction

```cpp
lambda<n1, ..., nk, syntax<f>>::apply<t1, ..., tk>::type
```

is equivalent to

```cpp
multi_let<
  mpl::map<
    mpl::pair<n1, t1>,
    // ...
    mpl::pair<nk, tk>
  >,
  syntax<f>
>::type::type
```

For any `0 < j < k`

```cpp
lambda<n1, ..., nk, syntax<f>>
  ::apply<t1, ..., tj>::type::apply<t(j+1), ..., tk>::type
```

is equivalent to

```cpp
lambda<n1, ..., nk, syntax<f>>::apply<t1, ..., tk>::type
```

## Example

```cpp
using boost::mpl::plus;
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

typedef lambda<n, syntax<plus<int_<1>, n>>> plus_1;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



