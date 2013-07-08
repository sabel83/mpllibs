# var

## Synopsis

```cpp
template <class T>
struct var
{
  // unspecified
};
```

## Description

Wrapper for variables in expressions. The class parameter, `T` is the identity
of the variable.

## Header

```cpp
#include <mpllibs/metamonad/var.hpp>
```

## Example

```cpp
struct my_var_id;

typedef var<my_var_id> my_var;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



