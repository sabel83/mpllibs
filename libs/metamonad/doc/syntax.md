# syntax

## Synopsis

```cpp
template <class E>
struct syntax
{
  // unspecified
};
```

## Description

Wrapper for angle-bracket expressions. Wrapped expressions can be passed around
in lazy template metaprograms. Evaluating a wrapped value returns itself, thus
the wrapped expression does not get accidentally evaluated.

## Header

```cpp
#include <mpllibs/metamonad/syntax.hpp>
```

## Example

```cpp
struct my_var_id;

syntax<
  boost::mpl::plus<var<my_var_id>, boost::mpl::int_<13>>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



