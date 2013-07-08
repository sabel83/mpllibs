# lambda_c

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

The same as [`lambda`](lambda.html), but `F` is an angle-bracket expression
and not a syntax.

## Header

```cpp
#include <mpllibs/metamonad/lambda_c.hpp>
```

## Expression semantics

For any `k > 0`, `n1` ... `nk`, `j > 0`, `t1` ... `tj` classes and `f` nullary
metafunction

```cpp
lambda_c<n1, ..., nk, f>::apply<t1, ..., tj>::type
```

is equivalent to

```cpp
lambda<n1, ..., nk, f>::apply<t1, ..., tj>::type
```

## Example

```cpp
using boost::mpl::plus;
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

typedef lambda_c<n, plus<int_<1>, n>> plus_1;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



