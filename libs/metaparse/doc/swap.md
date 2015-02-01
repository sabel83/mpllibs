# swap

## Synopsis

```cpp
namespace v1
{
  template <class F>
  struct swap
  {
    template <class A, class B>
    struct apply;
  };
}
```

This is a [template metafunction class](metafunction_class.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`F`</td>
    <td>
      [template metafunction class](metafunction_class.html) taking two
      arguments
    </td>
  </tr>
  <tr>
    <td>`A`</td>
    <td>a type, `F` accepts as its second argument</td>
  </tr>
  <tr>
    <td>`B`</td>
    <td>a type, `F` accepts as its first argument</td>
  </tr>
</table>

## Description

It wraps `F`, a template metafunction class and swaps its arguments. It is
available in the `v1` namespace only, as it is intended to be used as a helper
utility during the migration to `v2`.

## Return value

It calls `F` with `B` and `A` and forwards its return value.

## Header

```cpp
#include <mpllibs/metaparse/v1/swap.hpp>
```

## Expression semantics

For any `F` template metafunction class expecting two arguments, and `A`, `B`
classes the following expressions are equivalent:

```cpp
swap<F>::apply<A, B>::type
F::apply<B, A>::type
```

## Example

```cpp
#include <mpllibs/metaparse/v1/swap.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

struct returns_first
{
  typedef returns_first type;

  template <class A, class>
  struct apply
  {
    typedef A type;
  };
};

static_assert(
  is_same<
    double,
    v1::swap<returns_first>::apply<int, double>::type
  >::type::value,
  "swap swaps the arguments"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2015.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

