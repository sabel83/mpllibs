# try_c

## Synopsis

```cpp
template <class Expr, class... Catches>
struct try_c
{
  // unspecified...
};
```

## Description

The same as [`try_`](try_.html), but the expression is an angle-bracket
expression and not a syntax.

## Header

```cpp
#include <mpllibs/metamonad/try_c.hpp>
```

## Expression semantics

For any `e` angle-bracket expression, `n > 0` and `c1`, ..., `ck` catch blocks

```cpp
try_c<e, c1, ..., cn>::type
```

is equivalent to

```cpp
try<syntax<e>, c1, ..., cn>::type
```

## Example

```cpp
using boost::mpl::int_;
using namespace mpllibs::metamonad::name;

struct error_tag_1;
struct error_tag_2;

struct unknown_error_detected;

try_c<
  may_fail2<may_fail1<int_<13>>>,
  catch_c<e, is_tag<error_tag_1, e>, int_<11>>,
  catch_c<e, is_tag<error_tag_2, e>, e>,
  catch_c<e, true_, unknown_error_detected>
>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



