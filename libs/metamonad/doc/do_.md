# do_

## Synopsis

```cpp
template <class MonadTag, class Step1, ..., class Stepn>
struct do_
{
  // unspecified...
};
```

## Description

Metafunction class for creating _do blocks_. It takes the steps of the do block
as arguments. The steps are syntaxes. The maximum number of arguments is defined
by the `MPLLIBS_LIMIT_DO_SIZE` macro. Steps are either:

* Nullary metafunctions returning a monadic value
* [`set`](set.html) constructs
* [`do_return`](do_return.html) constructs

## Header

```cpp
#include <mpllibs/metamonad/do_.hpp>
```

## Example

```cpp
using boost::mpl::int_;

using namespace mpllibs::metamonad::name;

do_<exception_tag,
  syntax<set<r, may_fail1<int_<13>>>,
  syntax<may_fail2<r>>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



