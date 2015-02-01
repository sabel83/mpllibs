# mpllibs::metaparse versioning

This section describes how the library is prepared for supporting multiple
(not backward compatible) changes.

## Template classes

The elements of the library are defined in the `mpllibs::metaparse::v2`
namespace. For example the `one_char` class is
`mpllibs::metaparse::v2::one_char` and is available after including the
`<mpllibs/metaparse/v2/one_char.hpp>` header file.

At the same time the library provides the `<mpllibs/metaparse/one_char.hpp>`
header file which includes `<mpllibs/metaparse/v2/one_char.hpp>` and contains
the following:

```cpp
namespace mpllibs
{
  namespace metaparse
  {
    using v2::one_char;
  }
}
```

This makes it possible to use `one_char` as `mpllibs::metaparse::one_char`.

Future versions of the library may provide other namespaces (eg. `v3`). The
header files in `<mpllibs/metaparse/...>` provide the latest version of the
library. To always get version `v2`, one should use header files in
`<mpllibs/metaparse/v2/...>`.

The library does not use inline namespaces to work on compilers that do not
support them.

## Macros

Macros defined by the library are prefixed with `MPLLIBS_V2_`. For example
`MPLLIBS_V2_STRING`. It is defined in the
`<mpllibs/metaparse/v2/string.hpp>` header file. The library provides the
`<mpllibs/metaparse/srting.hpp>` header file as well, which includes the
definition of this macro and provides the following definition:

```cpp
#define MPLLIBS_STRING MPLLIBS_V2_STRING
```

This makes it possible to use the macro as `MPLLIBS_STRING`. Future versions of
the library may define other versions of this macro (eg. `MPLLIBS_V3_STRING`).
`MPLLIBS_STRING` will refer to the latest version.

This versioning does not affect macros that may be overridden by the code using
the library. (eg. `MPLLIBS_LIMIT_STRING_SIZE`)

## Migration from `v1`

The callback functions of [`foldl`](foldl.html), [`foldl1`](foldl1.html),
[`foldlp`](foldlp.html), [`foldr`](foldr.html), [`foldr1`](foldr1.html),
[`foldrp`](foldrp.html) expect their arguments in reverse order in `v2` compared
to `v1`. To help migration, Metaparse provides the [`v1::swap`](swap.html)
metafunction class.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)
<br />
