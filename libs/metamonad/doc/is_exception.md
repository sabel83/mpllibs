# is_exception

## Synopsis

```cpp
template <class Data>
struct is_exception
{
  // unspecified
};
```

## Description

Metafunction checking if its argument is an [exception](exception.html) value.
It expects a nullary metafunction as argument.

## Header

```cpp
#include <mpllibs/metamonad/is_exception.hpp>
```

## Expression semantics

For any `d` class the following evaluates to `true`

```cpp
is_exception<exception<d>>
```

For any `c` class, that is not an instance of the `exception` template, the
following evaluates to `true`

```cpp
boost::mpl::not_<is_exception<c>::type>
```

## Example

```cpp
typedef is_exception<exception<int>::type> always_true;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



