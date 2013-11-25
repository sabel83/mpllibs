# exception_tag

## Synopsis

```cpp
struct exception_tag
{
  // unspecified
};
```

## Description

This is the tag of the [`exception`](exception.html) values.

## Header

```cpp
#include <mpllibs/metamonad/exception_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
exception_tag::tag
```

```cpp
exception_tag
exception_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



