# eval_syntax

## Synopsis

```cpp
template <class E>
struct eval_syntax
{
  // unspecified
};
```

## Description

Metafunction for evaluating an angle-bracket expression wrapped by
[`syntax`](syntax.html).

## Header

```cpp
#include <mpllibs/metamonad/eval_syntax.hpp>
```

## Expression semantics

For any `t` type

```cpp
eval_syntax<syntax<t>>::type
```

is equivalent with

```cpp
t::type
```

## Example

```cpp
eval_syntax<syntax<boost::mpl::plus<int_<1>, int_<2>>>>>::type
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



