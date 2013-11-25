# mpllibs::safe_printf versioning

This section describes how the library is prepared for supporting multiple
(not backward compatible) changes.

The elements of the library are defined in the `mpllibs::safe_printf::v1`
namespace. For example the `printf` template function is
`mpllibs::safe_printf::v1::printf` and is available after including the
`<mpllibs/safe_printf/v1/printf.hpp>` header file.

At the same time the library provides the `<mpllibs/safe_printf/printf.hpp>`
header file which includes `<mpllibs/safe_printf/v1/printf.hpp>` and contains
the following:

```cpp
namespace mpllibs
{
  namespace safe_printf
  {
    using v1::printf;
  }
}
```

This makes it possible to use `printf` as `mpllibs::safe_printf::printf`.

Future versions of the library may provide other namespaces (eg. `v2`). The
header files in `<mpllibs/safe_printf/...>` provide the latest version of the
library. To always get version `v1`, one should use header files in
`<mpllibs/safe_printf/v1/...>`.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)
<br />
