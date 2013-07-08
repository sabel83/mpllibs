# mconcat

## Synopsis

```cpp
template <class MonadTag, class L>
struct mconcat
{
  // unspecified
};
```

## Description

`mconcat` is a metafunction for the `mconcat` operation of the
[monoid](monoid.html) typeclass.

## Header

```cpp
#include <mpllibs/metamonad/mconcat.hpp>
```

## Expression semantics

For any `monad_tag` tag and `l` list:

```cpp
mconcat<monad_tag, l>
```

is equivalent to

```cpp
apply<monoid<monad_tag>::mconcat, l>
```

## Example

```cpp
using boost::mpl::list_c;
using boost::mpl::list;

typedef
  mconcat<
    list_tag,
    list<
      list_c<int, 0, 1, 2, 3, 4>,
      list_c<int, 5, 6>,
      list_c<int, 7, 8, 9>
    >
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



