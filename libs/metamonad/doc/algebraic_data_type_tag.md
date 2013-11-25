# algebraic_data_type_tag

## Synopsis

```cpp
struct algebraic_data_type_tag
{
  // unspecified
};
```

## Description

This is the tag of the algebraic data-types created using
[`MPLLIBS_DATA`](MPLLIBS_DATA.html).

## Header

```cpp
#include <mpllibs/metamonad/algebraic_data_type_tag.hpp>
```

## Expression semantics

The following are equivalent

```cpp
tag_tag
algebraic_data_type_tag::tag
```

```cpp
algebraic_data_type_tag
algebraic_data_type_tag::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



