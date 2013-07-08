# eval

## Synopsis

```cpp
template <class Exp>
struct eval
{
  // unspecified
};
```

## Description

Metafunction adding an extra level of evaluation to a value. When the
metafunction is evaluated, it returns `Exp::type::type`.

## Header

```cpp
#include <mpllibs/metamonad/eval.hpp>
```

## Expression semantics

For any `t` type:

```cpp
eval<t>::type
```

is equivalent to

```cpp
t::type::type
```

## Example

```cpp
template <class C, class T, class F>
struct eval_if : eval<boost::mpl::if_<C, T, F>> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



