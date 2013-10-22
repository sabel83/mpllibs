# bind

## Synopsis

```cpp
template <class MonadTag, class A, class F>
struct bind
{
  // unspecified
};
```

## Description

`bind` is a metafunction for the `bind` operation of the [monad](monad.html)
typeclass.

## Header

```cpp
#include <mpllibs/metamonad/bind.hpp>
```

## Expression semantics

For any `monad_tag` tag, `a` class and `f` metafunction taking one argument:

```cpp
bind<monad_tag, a, f>
```

is equivalent to

```cpp
apply<monad<monad_tag>::bind, a, f>
```

## Example

```cpp
using boost::mpl::always;

struct one_error;
struct other_error;

typedef
  bind<
    exception_tag,
    exception<one_error>,
    always<exception<other_error>>
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



