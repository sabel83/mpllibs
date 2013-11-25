# monad_plus

## Synopsis

```cpp
template <class MonadTag>
struct monad_plus;
  // Requires:
  //   struct mzero;
  //   struct mplus { template <class, class> struct apply; };
```

## Description

This is a typeclass for monad pluses. A monad plus represents a monad that
satisfies the expectations of a [monoid](monoid.html). The indentity value is
called `mzero`, the operation is called `mplus`.

Due to the way Metamonad [handles versioning](versioning.html), the `monad_plus`
template class has to be specialised in the `mpllibs::metamonad::v1` namespace.

## Header

```cpp
#include <mpllibs/metamonad/monad_plus.hpp>
```

## Example

```cpp
using boost::mpl;

struct list_tag;

template <>
struct monad_plus<list_tag>
{
  typedef list<> mzero;
  
  struct mplus
  {
    template <class A, class B>
    struct apply : insert_range<A, typename end<A>::type, B> {};
  };
};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



