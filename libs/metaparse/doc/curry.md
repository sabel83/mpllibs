# curry

## Synopsis

```cpp
template <
  template <
    class1,
    // ...
    classn
  > class T
>
struct curryn
{
  // unspecified
};
```

## Description

Higher order functions taking metafunctions as arguments and generating a
curried version of them.

## Header

```cpp
#include <mpllibs/metaparse/util/curry.hpp>
```

## Expression semantics

For any `T` metafunction class taking n arguments and `C1` ... `Cn` classes the
following are equivalent:

```cpp
boost::mpl::apply<
  ...
    boost::mpl::apply<
      boost::mpl::apply<
        curryn<T>,
        C1
      >::type,
      C2
    >::type
  ...
  Cn
>

boost::mpl::apply<T, C1, ..., Cn>
```

## Example

```cpp
template <class a, class b>
struct always_second : boost::mpl::identity<b> {};

typedef curry2<always_second> curried_second;

typedef
  boost::mpl::apply<
    boost::mpl::apply<curried_second, int>::type,
    double
  >
  this_is_double;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


