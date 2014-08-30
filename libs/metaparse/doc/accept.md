# accept

## Synopsis

```cpp
template <class Result, class Remaining, class Pos>
struct accept;
```

This is a [template metaprogramming value](metaprogramming_value.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`Result`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
  <tr>
    <td>`Remaining`</td>
    <td>[string](string.html)</td>
  </tr>
  <tr>
    <td>`Pos`</td>
    <td>[source position](source_position.html)</td>
  </tr>
</table>

## Description

Values representing a successful parser application. It behaves as a [lazy
template metafunction](lazy_metafunction.html): when it is evaluated as a
metafunction, it returns itself with its arguments evaluated. See expression
semantics for further details.

> Note that for backward compatibility when `Result::type` is not defined,
> `accept<....>::type` does not evaluate `Result`. For example
> `accept<int, MPLLIBS_STRING("foo"), start>::type` is
> `accept<int, MPLLIBS_STRING("foo")::type, start::type>`. Using types that are
> not template metaprogramming values as `Result` is deprecated and will not
> work in future versions of the library.

## Expressions semantics

For any `r` template metaprogramming value, `s` compile-time string and `p`
source position the following are equivalent:

```cpp
accept<r, s, p>::type

accept<r::type, s::type, p::type>
```

## Header

```cpp
#include <mpllibs/metaparse/accept.hpp>
```

## Operations

* [`get_position`](get_position.html)
* [`get_remaining`](get_remaining.html)
* [`get_result`](get_result.html)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

