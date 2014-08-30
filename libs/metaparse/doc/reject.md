# reject

## Synopsis

```cpp
template <class Msg, class Pos>
struct reject;
```

This is a [template metaprogramming value](metaprogramming_value.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`Msg`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
  <tr>
    <td>`Pos`</td>
    <td>[source position](source_position.html)</td>
  </tr>
</table>

## Description

Values representing a failed parser application. It behaves as a [lazy template
metafunction](lazy_metafunction.html): when it is evaluated as a metafunction,
it returns itself with its arguments evaluated. See expression semantics for
further details.

> Note that for backward compatibility when `Msg::type` is not defined,
> `reject<....>::type` does not evaluate `Msg`. For example
> `reject<int, start>::type` is `reject<int, start::type>`. Using types that are
> not template metaprogramming values as `Msg` is deprecated and will not work
> in future versions of the library.

## Expressions semantics

For any `m` template metaprogramming value and `p` source position the following
are equivalent:

```cpp
reject<m, p>::type

reject<m::type, p::type>
```

## Header

```cpp
#include <mpllibs/metaparse/reject.hpp>
```

## Operations

* [`get_position`](get_position.html)
* [`get_message`](get_message.html)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

