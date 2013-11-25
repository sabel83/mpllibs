# writer_tag

## Synopsis

```cpp
template <class M>
struct writer_tag
{
  // unspecified
};
```

## Description

This tag represents the [Writer monad](writer_monad.html). `M` represents the
tag of the state. [`monoid`](monoid.html)`<M>` is expected to be defined.

## Header

```cpp
#include <mpllibs/metamonad/writer_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
writer_tag::tag
```

```cpp
writer_tag
writer_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



