# catch_all

## Synopsis

```cpp
template <class E, class Handler>
struct catch_all
{
  // unspecified
};
```

## Description

Evaluates the angle-bracket expression `E`. When it evaluates to an
[`exception`](exception.html), the value wrapped by `exception` is passed to
the metafunction class `Handler` and its result is returned by `catch_all`.
Otherwise `catch_all` returns the result of `E`.

## Header

```cpp
#include <mpllibs/metamonad/catch_all.hpp>
```

## Expression semantics

For any `t` angle-bracket expression not evaluating to an instance of
`exception`, `u` angle-bracket expression evaluating to `exception<e>` for some
`e` type and `g` metafunction class taking one argument the following are
equivalent:

```cpp
catch_all<syntax<t>, f>::type
t::type
```

```cpp
catch_all<syntax<u>, f>::type
f::type::apply<e>::type
```

## Example

```cpp
using boost::mpl::int_;
using namespace mpllibs::metamonad::name;

catch_all<
  syntax<may_fail2<may_fail1<int_<13>>>>,
  lambda_c<e, int_<11>>
>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



