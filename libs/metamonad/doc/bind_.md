# bind_

## Synopsis

```cpp
template <class MonadTag, class A, class B>
struct bind_
{
  // unspecified
};
```

## Description

`bind_` is a metafunction for the `bind_` operation of the [monad](monad.html)
typeclass.

## Header

```cpp
#include <mpllibs/metamonad/bind_.hpp>
```

## Expression semantics

For any `monad_tag` tag and `a`, `b` classes:

```cpp
bind_<monad_tag, a, b>
```

is equivalent to

```cpp
apply<monad<monad_tag>::bind_, a, b>
```

## Example

```cpp
struct one_error;
struct other_error;

typedef
  bind_<
    exception_tag,
    exception<one_error>,
    exception<other_error>
  >::type
  exception_one_error;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



