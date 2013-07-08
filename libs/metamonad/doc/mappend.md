# mappend

## Synopsis

```cpp
template <class MonadTag, class A, class B>
struct mappend
{
  // unspecified
};
```

## Description

`mappend` is a metafunction for the `mappend` operation of the
[monoid](monoid.html) typeclass.

## Header

```cpp
#include <mpllibs/metamonad/mappend.hpp>
```

## Expression semantics

For any `monad_tag` tag and `a` and `b` classes:

```cpp
mappend<monad_tag, a, b>
```

is equivalent to

```cpp
apply<monoid<monad_tag>::mappend, a, b>
```

## Example

```cpp
using boost::mpl::list_c;

typedef
  mappend<
    list_tag,
    list_c<int, 0, 1, 2, 3, 4>,
    list_c<int, 5, 6, 7, 8, 9>
  >::type
  list_0_to_10;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



