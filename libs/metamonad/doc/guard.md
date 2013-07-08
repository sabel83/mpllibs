# guard

## Synopsis

```cpp
template <class MonadTag, class C>
struct guard
{
  // unspecified
};
```

## Description

When `C` is true, it returns `return_<MonadTag, mpl::void_>`, when it is false,
it returns `mzero<MonadTag>`.

It can be used to implement guards when using [do notation](do_.html) for
implementing list comprehension.

## Header

```cpp
#include <mpllibs/metamonad/guard.hpp>
```

## Expression semantics

For any `monad_plus_tag` tag and `c` nullary metafunction

```cpp
guard<monad_plus_tag, c>
```

is equivalent to

```cpp
if_<B, return_<monad_plus_tag, boost::mpl::void_>, mzero<monad_plus_tag>>
```

## Example

```cpp
do_c<list_tag,
  set<i, list_c<int, 1, 2>>,
  set<j, range_c<int, 1, 5>>,
  guard<list_tag, equal_to<i, j>>,
  do_return<pair<i, j>>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



