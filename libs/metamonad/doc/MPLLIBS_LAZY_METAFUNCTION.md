# MPLLIBS_LAZY_METAFUNCTION

## Synopsis

```cpp
#define MPLLIBS_LAZY_METAFUNCTION(name, args) \
  // unspecified
```

## Description

This macro is similar to [`MPLLIBS_METAFUNCTION`](MPLLIBS_METAFUNCTION.html)
but it uses the evaluated arguments in its `body`.

The metafunctions defined using this macro support currying.

The macro defines a helper metafunction as well. The name of it is generated
using the `MPLLIBS_HELPER_METAFUNCION` macro. When it is not defined, the
following default is used:

```cpp
#define MPLLIBS_HELPER_METAFUNCTION(name) BOOST_PP_CAT(name, __impl)
```

## Header

```cpp
#include <mpllibs/metamonad/lazy_metafunction.hpp>
```

## Expression semantics

For any `body` angly-bracket expression, `n > 0` and `arg1` ... `argn` template
arguments the following

```cpp
MPLLIBS_LAZY_METAFUNCTION(name, (arg1)(arg2)...(argn)) ((body));
```

is equivalent to

```cpp
MPLLIBS_METAFUNCTION(name, (arg1)(arg2)...(argn)) ((body));
```

but when `arg1`, `arg2`, ..., `argn` is referred to in `body`, it refers to
`arg1::type`, `arg2::type`, ..., `argn::type`.


## Example

```cpp
using namespace boost::mpl;

MPLLIBS_LAZY_METAFUNCTION(double_value, (N)) (times<int_<2>, N>));
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



