# start

## Synopsis

```cpp
struct start
{
  // unspecified
};
```

## Description

A compile-time source position value. It represents the beginning of an input
text.

Its tag is `source_position_tag`.

## Header

```cpp
#include <mpllibs/metaparse/source_position.hpp>
```

## Example

```cpp
accept<boost::mpl::int_<13>, MPLLIBS_STRING(""), start>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



