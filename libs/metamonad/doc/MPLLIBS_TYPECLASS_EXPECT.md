# MPLLIBS_TYPECLASS_EXPECT

## Synopsis

```cpp
#define MPLLIBS_TYPECLASS_EXPECT(name) \
  // unspecified
```

## Description

Macro for defining a typedef for throwing a compile-time exception. The purpose
of the macro is improving readability of typeclass expectation descriptions. The
expection thrown is [`invalid_typeclass`](invalid_typeclass.html).

## Header

```cpp
#include <mpllibs/metamonad/typeclass.hpp>
```

## Expression semantics

The following

```cpp
MPLLIBS_TYPECLASS_EXPECT(some_fun);
```

is equivalent to

```cpp
typedef mpllibs::metamonad::exception<invalid_typeclass> some_fun;
```

## Example

```cpp
template <class Tag>
struct example_typeclass
{
  MPLLIBS_TYPECLASS_EXPECT(some_fun);
  MPLLIBS_TYPECLASS_EXPECT(some_other_fun);
};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



