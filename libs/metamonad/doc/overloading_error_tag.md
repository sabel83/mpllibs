# overloading_error_tag

## Synopsis

```cpp
struct overloading_error_tag
{
  // unspecified
};
```

## Description

`tag` that can be used as `tag` of errors, when an overloaded function is called
with an argument there is no overload for. The `tag` of this `tag` is
`[tag_tag](tag_tag.html)`.

## Header

```cpp
#include <mpllibs/metamonad/overloading_error.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
overloading_error::tag
```

```cpp
overloading_error
overloading_error::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



