# make_monadic

## Synopsis

```cpp
template <class MonadTag, class Expr>
struct make_monadic
{
  // unspecified
};
```

## Description

Given a monadic action of the [maybe monad](maybe_monad.html)

```cpp
MPLLIBS_METAFUNCTION(f, (N)) ((just<N>));
```

A metafunction for division is also given:

```cpp
MPLLIBS_METAFUNCTION(maybe_divides, (A)(B)) ((just<divides<A, B>>));
```

To divide the result of `f<int_<26>>` to `f<int_<2>>` one has to use
[`bind`](bind.html) or a [do block](do_.html). For example:

```cpp
do_c<
  maybe_tag,
  set<a, f<int_<26>>>,
  set<b, f<int_<2>>>,
  maybe_divides<a, b>
>
```

Writing

```cpp
maybe_divides<f<int_<26>, int_<2>>>
```

would be invalid, since `maybe_divides` expects numbers and not `Maybe` numbers.
`make_monadic` expects such an invalid expression and turns it into a valid
monadic expression:

```cpp
make_monadic<
  maybe_tag,
  syntax<
    maybe_divides<already_monadic<f<int_<26>>>, already_monadic<f<int_<2>>>>
  >
>
```

The subexpressions that should not be transformed should be marked with
[`already_monadic`](already_monadic.html).

## Header

```cpp
#include <mpllibs/metamonad/make_monadic.hpp>
```

## Expression semantics

For any `monad_tag` tag, `n > 0`, `f` metafunction taking `n` arguments and
`t`, `t1`, ..., `tn` classes the following are equivalent:

```cpp
make_monadic<monad_tag, syntax<t>>::type
t::type
```

```cpp
make_monadic<monad_tag, syntax<f<t1, ..., tn>>::type
do_c<
  set<t1_, make_monadic<monad_tag, syntax<t1>>>,
  // ...
  set<tn_, make_monadic<monad_tag, syntax<tn>>>,
  f<t1_, ..., tn_>
>::type
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



