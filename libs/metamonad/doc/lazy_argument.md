# lazy_argument

## Synopsis

```cpp
template <class Exp>
struct lazy_argument
{
  // unspecified
};
```

## Description

`Exp` is an angly bracket expression of metafunctions calling each other with
other angly bracket expressions as arguments. `already_lazy` is expected to be
used in the expression passed to [`lazy`](lazy.html). The content of
`already_lazy` is transformed by `lazy` but is not evaluated.

## Header

```cpp
#include <mpllibs/metamonad/lazy_argument.hpp>
```

## Expression semantics

For any `c` class

```cpp
lazy<lazy_argument<c> >::type
```

is equivalent to

```cpp
lazy<c>
```

## Example

```cpp
using namespace boost::mpl;

template <class N>
struct fib :
  lazy<
    eval_if<
      less<N, int_<2> >,
      lazy_argument<int_<1> >,
      lazy_argument<plus<fib<minus<N, int_<1> > >, fib<minus<N, int_<2> > > >
    >
  >
{};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



