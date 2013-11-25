# mpllibs::metaparse versioning

This section describes how the library is prepared for supporting multiple
(not backward compatible) changes.

## Template classes

The elements of the library are defined in the `mpllibs::metaparse::v1`
namespace. For example the `one_char` class is
`mpllibs::metaparse::v1::one_char` and is available after including the
`<mpllibs/metaparse/v1/one_char.hpp>` header file.

At the same time the library provides the `<mpllibs/metaparse/one_char.hpp>`
header file which includes `<mpllibs/metaparse/v1/one_char.hpp>` and contains
the following:

```cpp
namespace mpllibs
{
  namespace metaparse
  {
    using v1::one_char;
  }
}
```

This makes it possible to use `one_char` as `mpllibs::metaparse::one_char`.

Future versions of the library may provide other namespaces (eg. `v2`). The
header files in `<mpllibs/metaparse/...>` provide the latest version of the
library. To always get version `v1`, one should use header files in
`<mpllibs/metaparse/v1/...>`.

The library does not use inline namespaces to work on compilers that do not
support them.

## Macros

Macros defined by the library are prefixed with `MPLLIBS_V1_`. For example
`MPLLIBS_V1_STRING`. It is defined in the
`<mpllibs/metaparse/v1/string.hpp>` header file. The library provides the
`<mpllibs/metaparse/srting.hpp>` header file as well, which includes the
definition of this macro and provides the following definition:

```cpp
#define MPLLIBS_STRING MPLLIBS_V1_STRING
```

This makes it possible to use the macro as `MPLLIBS_STRING`. Future versions of
the library may define other versions of this macro (eg. `MPLLIBS_V2_STRING`).
`MPLLIBS_STRING` will refer to the latest version.

This versioning does not affect macros that may be overridden by the code using
the library. (eg. `MPLLIBS_LIMIT_STRING_SIZE`)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)
<br />
