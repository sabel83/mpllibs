# reader_tag

## Synopsis

```cpp
struct reader_tag
{
  // unspecified
};
```

## Description

This tag represents the [Reader monad](reader_monad.html).

## Header

```cpp
#include <mpllibs/metamonad/reader_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
reader_tag::tag
```

```cpp
reader_tag
reader_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



