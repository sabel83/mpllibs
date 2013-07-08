# return_

## Synopsis

```cpp
template <class MonadTag, class T>
struct return_
{
  // unspecified
};
```

## Description

`return_` is a metafunction for the `return_` operation of the
[monad](monad.html) typeclass.

## Header

```cpp
#include <mpllibs/metamonad/return_.hpp>
```

## Expression semantics

For any `monad_tag` tag and `t` class

```cpp
return_<monad_tag, t>
```

is equivalent to

```cpp
apply<monad<monad_tag>::return_, t>
```

## Example

```cpp
typedef return_<exception_tag, int> lifted_int;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



