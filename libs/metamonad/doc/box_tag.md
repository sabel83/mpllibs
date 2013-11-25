# box_tag

## Synopsis

```cpp
struct box_tag
{
  // unspecified
};
```

## Description

This is the tag of the boxed values built with [`box`](box.html).

## Header

```cpp
#include <mpllibs/metamonad/box_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
box_tag::tag
```

```cpp
box_tag
box_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



