# mempty

## Synopsis

```cpp
template <class MonadTag>
struct mempty
{
  // unspecified
};
```

## Description

`mempty` is a metafunction for the `mempty` operation of the
[monoid](monoid.html) typeclass.

## Header

```cpp
#include <mpllibs/metamonad/mempty.hpp>
```

## Expression semantics

For any `MonadTag` tag:

```cpp
mempty<MonadTag>
```

is equivalent to

```cpp
monoid<MonadTag>::mempty
```

## Example

```cpp
typedef mempty<list_tag>::type empy_list;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



