# make_syntax

## Synopsis

```cpp
template <class E>
struct make_syntax
{
  // unspecified
};
```

## Description

It evaluates its argument and wraps the result with [`syntax`](syntax.html).

## Header

```cpp
#include <mpllibs/metamonad/make_syntax.hpp>
```

## Expression semantics

For any `t` type

```cpp
make_syntax<t>::type
```

is equivalent with

```cpp
syntax<t::type>
```

## Example

```cpp
typedef make_syntax<boost::mpl::plus<int_<1>, int_<2>>>::type syntax_3;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



