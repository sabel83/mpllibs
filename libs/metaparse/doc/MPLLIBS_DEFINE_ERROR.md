# MPLLIBS_DEFINE_ERROR

## Synopsis

```cpp
#define MPLLIBS_DEFINE_ERROR(name, msg) \
  // unspecified
```

## Description

Macro for defining a class which can be used as error messages returned by
parsers. `name` is the name of the class representing the error message and
`msg` is a string literal containing the description of the error.

## Header

```cpp
#include <mpllibs/metaparse/define_error.hpp>
```

## Expression semantics

For any `n` name and `m` string literal, given the following is defined:

```cpp
MPLLIBS_DEFINE_ERROR(n, m);
```

the following pairs of expressions are equivalent:

```cpp
n::get_value()
std::string(m)
```

```cpp
n::type
n
```

## Example

```cpp
MPLLIBS_DEFINE_ERROR(space_expected, "Space character expected");
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



