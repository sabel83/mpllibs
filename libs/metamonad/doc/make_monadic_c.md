# make_monadic_c

## Synopsis

```cpp
template <class MonadTag, class Expr>
struct make_monadic_c
{
  // unspecified
};
```

## Description

The same as [`make_monadic`](make_monadic.html), but `Expr` is an
angle-bracket expression and not a syntax.

## Header

```cpp
#include <mpllibs/metamonad/make_monadic_c.hpp>
```

## Expression semantics

For any `t`, `e` classes

```cpp
make_monadic_c<t, e>::type
```

is equivalent to

```cpp
make_monadic<t, syntax<e>>::type
```

## Example

```cpp
MPLLIBS_METAFUNCTION(f, (N)) ((just<N>));
MPLLIBS_METAFUNCTION(maybe_divides, (A)(B)) ((just<divides<A, B>>));

make_monadic_c<
  maybe_tag,
  maybe_divides<already_monadic<f<int_<26>>>, already_monadic<f<int_<2>>>>
>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



