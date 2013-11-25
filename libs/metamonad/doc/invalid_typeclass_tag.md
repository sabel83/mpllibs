# invalid_typeclass_tag

## Synopsis

```cpp
struct invalid_typeclass_tag
{
  // unspecified
};
```

## Description

This is the tag of the [`invalid_typeclass`](invalid_typeclass.html) value.

## Header

```cpp
#include <mpllibs/metamonad/invalid_typeclass_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
invalid_typeclass_tag::tag
```

```cpp
invalid_typeclass_tag
invalid_typeclass_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



