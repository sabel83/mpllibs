# MPLLIBS_STRING

## Synopsis

```cpp
#define MPLLIBS_STRING(s) \
  // unspecified
```

## Description

Macro for defining [`string`](string.html) values. `s` is expected to be a
string literal. The macro requires C++11.

The maximal length of the string is limited. This limit is defined by the
`MPLLIBS_STRING_MAX_LENGTH` macro.

On platforms where `MPLLIBS_STRING` is not supported, the `string.hpp` header
defines the `MPLLIBS_CONFIG_NO_MPLLIBS_STRING` macro. Defining this macro
before including the header disables the `MPLLIBS_STRING` macro.

## Header

```cpp
#include <mpllibs/metaparse/string.hpp>
```

## Expression semantics

The semantics of this macro is demonstrated by an example. The following

```cpp
MPLLIBS_STRING("hello")
```

is equivalent to

```cpp
string<'h','e','l','l','o'>
```

## Example

```cpp
MPLLIBS_STRING("Hello World")
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



