# instantiate

## Synopsis

```cpp
template <template <class, ..., class> class T>
struct instantiaten
{
  template <class V>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Metafunction class for template instantiation. It takes a sequence of classes
as argument and instantiates the template `T` with those classes. It returns the
instantiated template. The sequence may have less elements than the number of
template arguments `T` expects. In such cases `boost::mpl::na` is used instead
of the non-specified arguments.

## Header

```cpp
#include <mpllibs/metamonad/instantiate.hpp>
```

## Expression semantics

For any `n > 0`, `k >= 0`, `n >= k`, `c1`, ..., `ck` classes and `t` template
class taking `n` classes as template arguments

```cpp
instantiaten<t>::apply<boost::mpl::vector<c1, ..., ck> >::type
```

is equivalent with

```cpp
t<c1, ..., ck, boost::mpl::na, ..., boost::mpl::na>
```

## Example

```cpp
typedef apply<instantiate<pair>, boost::mpl::vector<int, int>>::type int_pair;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



