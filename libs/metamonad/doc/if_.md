# if_

## Synopsis

```cpp
template <class C, class T, class F>
struct if_
{
  // unspecified
};
```

## Description

Evaluates the nullary metafunction `C`, and when it returns a true logical
value, `if_` returns the result of the nullary metafunction `T`, when `C`
returns false, `if_` returns the result of the nullary metafunction `F`.

## Header

```cpp
#include <mpllibs/metamonad/if.hpp>
```

## Expression semantics

For any `ct` nullary metafunction evaluating to true, `cf` nullary metafunction
evaluating to false and `t`, `f` nullary metafunctions the following are
equivalent:

```cpp
if_<ct, t, f>::type
t::type
```

```cpp
if_<cf, t, f>::type
f::type
```

## Example

```cpp
MPLLIBS_METAFUNCTION(divide_if_not_zero, (A)(B))
((
  if_<
    boost::mpl::equal_to<boost::mpl::int_<0>, B>,
    A,
    boost::mpl::divides<A, B>
  >
));
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



