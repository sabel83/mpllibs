# tag_tag

## Synopsis

```cpp
struct tag_tag
{
  // unspecified
};
```

## Description

`tag` that can be used as the tag of other tags. Its tag is itself.

## Header

```cpp
#include <mpllibs/metamonad/tag_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
tag_tag::tag
```

```cpp
tag_tag
tag_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



