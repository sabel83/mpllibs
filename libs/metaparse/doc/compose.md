# compose

## Synopsis

```cpp
template <
  class F1,
  // ...
  class Fn
>
struct compose
{
  // unspecified
};
```

## Description

Higher order function taking metafunction classes as arguments and generating
their composition.

## Header

```cpp
#include <mpllibs/metaparse/util/compose.hpp>
```

## Expression semantics

For any `f1` ... `fn` metafunction classes taking 1 argument and
`x1`, ..., `xk` classes

```cpp
boost::mpl::apply<compose<f1, .... fn>, x1, ..., xk>
```

is equivalent to

```cpp
boost::mpl::apply<f1, ... boost::mpl::apply<fn, x1, ..., xk>::type ... >
```

## Example

```cpp
struct make_pointer
{
  template <class T>
  struct apply : boost::mpl::identity<T*> {};
};

typedef
  boost::mpl::apply<compose<make_pointer, make_pointer>, int>
  int_ptr_ptr;

```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


