# do_c

## Synopsis

```cpp
template <class MonadTag, class Step1, ..., class Stepn>
struct do_c
{
  // unspecified...
};
```

## Description

The same as [`do_`](do_.html), but the steps are angle-bracket expressions and
not syntaxes.

## Header

```cpp
#include <mpllibs/metamonad/do_c.hpp>
```

## Expression semantics

For any `n > 0` and `m`, `s1` ... `sn` classes

```cpp
do_c<m, s1, ..., sn>::type
```

is equivalent to

```cpp
do_<m, syntax<s1>, ..., syntax<sn>>::type
```

## Example

```cpp
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

do_c<exception_tag,
  set<r, may_fail1<int_<13>>,
  may_fail2<r>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



