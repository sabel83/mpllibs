# already_monadic

## Synopsis

```cpp
template <class Expr>
struct already_monadic
{
  // unspecified
};
```

## Description

It can be used to mark a subexpression of a [`make_monadic`](make_monadic.html)
expression as already monadic and avoid it being transformed.

## Header

```cpp
#include <mpllibs/metamonad/already_monadic.hpp>
```

## Expression semantics

For any `monad_tag` tag, `n > 0`, `f` metafunction taking `n` arguments and
`t1`, ..., `tn` classes

```cpp
make_monadic<monad_tag, syntax<already_monadic<f<t1, ..., tn>>>>::type
```

is equivalent to

```cpp
f<t1, ..., tn>::type
```

## Example

```cpp
MPLLIBS_METAFUNCTION(f, (N)) ((just<N>));
MPLLIBS_METAFUNCTION(maybe_divides, (A)(B)) ((just<divides<A, B>>));

make_monadic<
  maybe_tag,
  syntax<
    maybe_divides<already_monadic<f<int_<26>>>, already_monadic<f<int_<2>>>>
  >
>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



