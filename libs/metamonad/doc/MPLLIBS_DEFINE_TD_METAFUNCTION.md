# MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION

## Synopsis

```cpp
#define MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION(name, arg_num) \
  // unspecified
```

## Description

Macro for defining an overloadable metafunction evaluating its arguments lazily.
When there is no overload for the given arguments, it [throws](exception.html)
an exception with [`overloading_error_tag`](overloading_error_tag.html) tag.

## Header

```cpp
#include <mpllibs/metamonad/td_metafunction.hpp>
```

## Expression semantics

The following

```cpp
MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION(name, 3)
```

is equivalent to

```cpp
template <class Tag1, class Tag2, class Tag3>
struct name_impl
{
  template <class, class, class>
  struct apply :
    mpllibs::metamonad::exception<
      \\ unspecified
    >
  {};
};

template <class T1, class T2, class T3>
struct name :
  name_impl<
    typename boost::mpl::tag<typename T1::type>::type,
    typename boost::mpl::tag<typename T2::type>::type,
    typename boost::mpl::tag<typename T3::type>::type
  >::template apply<
    typename T1::type,
    typename T2::type,
    typename T3::type
  >
{};
```

## Example

```cpp
MPLLIBS_DEFINE_TAG_DISPATCHING_METAFUNCTION(f, 3)
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



