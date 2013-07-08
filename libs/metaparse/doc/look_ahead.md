# look_ahead

## Synopsis

```cpp
template <class P>
struct look_ahead
{
  // unspecified
};
```

## Description

Parses the input using parser `P`. When the parser returns an error,
`look_ahead` returns the error. When the parser returns a result, `look_ahead`
returns the result without consuming anything from the input string.

## Header

```cpp
#include <mpllibs/metaparse/look_ahead.hpp>
```

## Expression semantics

For any `p` parser, `s` compile-time string and `pos` source position

```cpp
boost::mpl::apply<look_ahead<p>, s, pos>
```

is equivalent to

```cpp
boost::mpl::apply<
  mpllibs::metaparse::return_<
    mpllibs::metaparse::get_result<boost::mpl::apply<p, s, pos>>::type
  >,
  s,
  pos
>
```

when `boost::mpl::apply<p, s, pos>` succeeds. It is

```cpp
boost::mpl::apply<p, s, pos>
```

otherwise.

## Example

```cpp
typedef look_ahead<mpllibs::metaparse::digit> starts_with_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



