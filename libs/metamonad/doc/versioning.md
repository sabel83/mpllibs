# mpllibs::metamonad versioning

This section describes how the library is prepared for supporting multiple
(not backward compatible) changes.

## Template classes

The elements of the library are defined in the `mpllibs::metamonad::v1`
namespace. For example the `let` template class is
`mpllibs::metamonad::v1::let` and is available after including the
`<mpllibs/metamonad/v1/let.hpp>` header file.

At the same time the library provides the `<mpllibs/metamonad/let.hpp>` header
file which includes `<mpllibs/metamonad/v1/let.hpp>` and contains the following:

```cpp
namespace mpllibs
{
  namespace metamonad
  {
    using v1::let;
  }
}
```

This makes it possible to use `let` as `mpllibs::metamonad::let`.

Future versions of the library may provide other namespaces (eg. `v2`). The
header files in `<mpllibs/metamonad/...>` provide the latest version of the
library. To always get version `v1`, one should use header files in
`<mpllibs/metamonad/v1/...>`.

This impacts the specialisation of template classes like [`monad`](monad.html),
since one can not specialise this template class in the `mpllibs::metamonad`
namespace, only in the `mpllibs::metamonad::v1` namespace. The library does not
use inline namespaces to work on compilers that do not support them.

## Macros

Macros defined by the library are prefixed with `MPLLIBS_V1_`. For example
`MPLLIBS_V1_METAFUNCTION`. It is defined in the
`<mpllibs/metamonad/v1/metafunction.hpp>` header file. The library provides the
`<mpllibs/metamonad/metafunction.hpp>` header file as well, which includes the
definition of this macro and provides the following definition:

```cpp
#define MPLLIBS_METAFUNCTION MPLLIBS_V1_METAFUNCTION
```

This makes it possible to use the macro as `MPLLIBS_METAFUNCTION`. Future
versions of the library may define other versions of this macro (eg.
`MPLLIBS_V2_METAFUNCTION`). `MPLLIBS_METAFUNCTION` will refer to the latest
version.

This versioning does not affect macros that may be overridden by the code using
the library. (eg. `MPLLIBS_LIMIT_DO_SIZE`)

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](index.html)
<br />
