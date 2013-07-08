# let

## Synopsis

```cpp
template <class Name, class Exp, class Body>
struct let
{
  // unspecified
};
```

## Description

`Name` a class, `Exp` and `Body` are syntaxes. `let` replaces all occurances of
`Name` with `Exp` in `Body`. It recurses into template instantiations. The
return value of the `let` metafunction is the updated `Body`.

## Header

```cpp
#include <mpllibs/metamonad/let.hpp>
```

## Expression semantics

For any `n`, `x` and `f` classes, where none of them are the same and `t`
template the following are equivalent:

```cpp
let<n, syntax<x>, syntax<f>>::type
f
```

```cpp
let<n, syntax<x>, syntax<n>>::type
x
```

```cpp
let<n, syntax<x>, syntax<t<f>>>::type
t<f>
```

```cpp
let<n, syntax<x>, syntax<t<n>>>::type
t<x>
```

```cpp
let<n, syntax<x>, syntax<let<n, f, f>>>::type
let<n, f, f>
```

## Example

```cpp
using boost::mpl::times;
using boost::mpl::plus;
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

template <class N>
struct my_metafunction :
  eval_syntax<
    let<
      x, syntax<plus<n, int_<13>>>,
      syntax<times<x, x>>
    >
  >
{};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



