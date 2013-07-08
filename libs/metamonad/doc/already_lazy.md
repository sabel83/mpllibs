# already_lazy

## Synopsis

```cpp
template <class Exp>
struct already_lazy
{
  // unspecified
};
```

## Description

`Exp` is an angly bracket expression of metafunctions calling each other with
other angly bracket expressions as arguments. When `already_lazy` is used inside
[`lazy`](lazy.html), the content of `already_lazy` is not transformed by `lazy`.
When it is used outside of `lazy`, it does not change the meaning of the wrapped
expression.

## Header

```cpp
#include <mpllibs/metamonad/already_lazy.hpp>
```

## Expression semantics

For any `c` class the following are equivalent

```cpp
lazy<already_lazy<c> >::type
c
```

```cpp
already_lazy<c>::type
c::type
```

## Example

```cpp
using namespace boost::mpl;

template <class N>
struct fib :
  lazy<
    eval_if<
      less<N, int_<2> >,
      already_lazy<int_<1> >,
      already_lazy<
        lazy<plus<fib<minus<N, int_<1> > >, fib<minus<N, int_<2> > > >
      >
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



