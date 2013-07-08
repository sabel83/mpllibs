# letrec_c

## Synopsis

```cpp
template <class Name, class Exp, class Body>
struct letrec_c
{
  // unspecified
};
```

## Description

The same as [`letrec`](letrec.html), but `Exp` and `Body` are angle-bracket
expressions and not syntaxes.

## Header

```cpp
#include <mpllibs/metamonad/letrec_c.hpp>
```

## Expression semantics

For any `n`, `e` and `b` classes

```cpp
letrec_c<n, e, b>::type
```

is equivalent to

```cpp
letrec<n, syntax<e>, syntax<b>>::type
```

## Example

```cpp
using boost::mpl::times;
using boost::mpl::plus;
using boost::mpl::minus;
using boost::mpl::int_;
using boost::mpl::equal_to;

struct fact_;
typedef var<fact_> fact;

typedef
  eval_syntax<
    letrec_c<
      fact,
      lambda_c<
        n,
        if_<
          equal_to<n, int_<0>>,
          int_<1>,
          lazy<times<apply<fact, minus<n, int_<1>>>, n>>
        >
      >,
      lazy<apply<fact, int_<3>>>
    >
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



