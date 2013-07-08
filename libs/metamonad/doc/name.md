# name

## Synopsis

```cpp
struct a;
struct z;
```

## Description

In let expressions, lambda expressions, etc custom classes can be used as names.
The classes declared in this header are intended to be used as such names.
Declaring custom classes all over one's code can be avoided by using these
classes as names.

The classes are in the `mpllibs::metamonad::name` namespace and this namespace
does not contain anything else. These classes can be made reachable in any
custom namespace by `using namespace mpllibs::metamonad::name` to make
referencing these names shorter, even in header files.

The header contains `using namespace mpllibs::metamonad::name` in
`mpllibs::metamonad`, thus the names are available in that namespace as well.

The classes can be used at any location where [variables](var.html) are
expected.

## Header

```cpp
#include <mpllibs/metamonad/name.hpp>
```

## Example

```cpp
namespace my_metaprograms
{
  using namespace mpllibs::metamonad::name;

  typedef metamonad::lambda_c<x, y, boost::mpl::plus<x, y>>::type add;
}
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



