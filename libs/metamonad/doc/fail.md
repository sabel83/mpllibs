# fail

## Synopsis

```cpp
template <class MonadTag, class S>
struct fail
{
  // unspecified
};
```

## Description

`fail` is a metafunction for the `fail` operation of the [monad](monad.html)
typeclass.

## Header

```cpp
#include <mpllibs/metamonad/fail.hpp>
```

## Expression semantics

For any `monad_tag` tag and `s` class:

```cpp
fail<monad_tag, s>
```

is equivalent to

```cpp
apply<monad<monad_tag>::fail, s>
```

## Example

```cpp
struct one_error;

typedef fail<maybe_tag, one_error>::type this_is_nothing;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



