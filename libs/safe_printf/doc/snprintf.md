# snprintf

## Synopsis

```cpp
template <class FormatString, class T1, ..., class Tn>
int snprintf(char *dst, size_t size, T1 a1, ..., Tn an);
```

## Description

Wrapper of the `snprintf` function of the C library. It takes the format string
as a compile-time string, which is an `mpllibs::metaparse::string`.
It type-checks the arguments based on the format string. When type-checking
fails, this function emits a compilation error. When type-checking succeeds,
this function calls the `snprintf` function of the C library. This thin wrapper
is likely to be inlined in which case it has no runtime overhead compared to
using `snprintf` without type-checking.

## Header

```cpp
#include <mpllibs/safe_printf/snprintf.hpp>
```

## Expression semantics

For any `s` `mpllibs::metaparse::string`, `buf` `char` pointer and
`a1` ... `an` runtime objects:

```cpp
mpllibs::safe_printf::snprintf<s>(buf, a1, ..., an)
```

When the number and types of `a1` ... `an` are correct according to `s`, the
format string, it is equivalent to

```cpp
std::snprintf(buf, boost::mpl::c_str<s>::type::value, a1, ..., an)
```

otherwise it is a compilation error.

## Example

```cpp
char s[32];
mpllibs::safe_printf::snprintf<MPLLIBS_STRING("%d %d\n")>(s, 32, 11, 13);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)




