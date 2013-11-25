# pair

## Synopsis

```cpp
struct pair_tag;

template <class Fist, class Second>
struct pair;
```

## Description

Algebraic data-type representing pairs of values. It is compatible with
`mpl::pair` values. The tag of the values is [`pair_tag`](pair_tag.html).

## Header

```cpp
#include <mpllibs/metamonad/pair.hpp>
```

## Example

```cpp
pair<mpl::int_<11>, mpl::int_<13>>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



