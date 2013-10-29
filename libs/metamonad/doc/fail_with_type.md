# fail_with_type

## Synopsis

```cpp
template <class T>
void fail_with_type();
```

## Description

Template function for enforcing the compiler to display a type. Calling this
template function emits a compilation error and the error message contains the
`T` type. It is useful for debugging template metaprograms.

## Header

```cpp
#include <mpllibs/metamonad/fail_with_type.hpp>
```

## Expression semantics

For any `t` type the following

```cpp
fail_with_type<t>();
```

emits a compilation error and the error message contains the type `t`.

## Example

```cpp
MPLLIBS_METAFUNCTION(some_metafunction, (t))
((
  // do something here...
));

int main()
{
  using mpllibs::metamonad::box;

  fail_with_type< some_metafunction<box<int>>::type >();
}
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



