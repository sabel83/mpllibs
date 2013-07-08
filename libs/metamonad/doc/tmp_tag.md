# tmp_tag

## Synopsis

```cpp
template <class T>
struct tmp_tag : tmp_value<T, tag_tag> {};
```

## Description

Convenience function for defining classes that are intended to be used as tags.

## Header

```cpp
#include <mpllibs/metamonad/tmp_tag.hpp>
```

## Expression semantics

For any `t` types the following are equivalent:

```cpp
t
tmp_tag<t>::type
```

```cpp
tag_tag
tmp_tag<t>::tag
```

## Example

```cpp
struct some_tag : tmp_tag<some_tag> {};

struct void_ : tmp_value<void_, some_tag> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



