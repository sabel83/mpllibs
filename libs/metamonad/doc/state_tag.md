# state_tag

## Synopsis

```cpp
struct state_tag
{
  // unspecified
};
```

## Description

This tag represents the [State monad](state_monad.html).

## Header

```cpp
#include <mpllibs/metamonad/state_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
state_tag::tag
```

```cpp
state_tag
state_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



