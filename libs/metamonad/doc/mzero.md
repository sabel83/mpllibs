# mzero

## Synopsis

```cpp
template <class MonadTag>
struct mzero
{
  // unspecified
};
```

## Description

`mzero` is a metafunction for the `mzero` operation of the
[monad plus](monad_plus.html) typeclass.

## Header

```cpp
#include <mpllibs/metamonad/mzero.hpp>
```

## Expression semantics

For any `MonadTag` tag:

```cpp
mzero<MonadTag>
```

is equivalent to

```cpp
monad_plus<MonadTag>::mzero
```

## Example

```cpp
typedef mzero<list_tag>::type empy_list;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



