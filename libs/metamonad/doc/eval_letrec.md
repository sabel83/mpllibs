# eval_letrec

## Synopsis

```cpp
template <class Name, class Exp, class Body>
struct eval_letrec
{
  // unspecified
};
```

## Description

This is similar to [`letrec`](letrec.html), but it evaluates the substituted
expression.

## Header

```cpp
#include <mpllibs/metamonad/eval_letrec.hpp>
```

## Expression semantics

For any `n`, `x` and `f` classes

```cpp
eval_letrec<n, x, f>
```

is equivalent to

```cpp
eval_syntax<letrec<n, x, f>>
```

## Example

```cpp
using boost::mpl::times;
using boost::mpl::plus;
using boost::mpl::minus;
using boost::mpl::int_;
using boost::mpl::equal_to;

struct fact;

typedef
  eval_letrec<
    fact,
    syntax<
      lambda_c<
        n,
        if_<
          equal_to<n, int_<0>>,
          int_<1>,
          lazy<times<apply<fact, minus<n, int_<1>>>, n>>
        >
      >
    >,
    lazy<apply<fact, int_<3>>>
  >::type
  fact_3;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



