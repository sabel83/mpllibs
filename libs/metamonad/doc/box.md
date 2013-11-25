# box

## Synopsis

```cpp
template <class T>
struct box
{
  // unspecified
};
```

## Description

It can be used to box values that are not nullary template metafunctions. Boxed
values are nullary template metafunctions evaluating to themselves, thus they
can be passed around in lazy template metaprograms.

The content of `box` is left untouched by [`lazy`](lazy.html) and is not subject
to variable substitution in let, lambda and do expressions.

The tag of boxed values is [`box_tag`](box_tag.html). Boxed values can be
compared with `boost::mpl::equal_to` and considered equal when they wrap the
same type.

## Header

```cpp
#include <mpllibs/metamonad/box.hpp>
```

## Example

```cpp
typedef box<int> boxed_int;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



