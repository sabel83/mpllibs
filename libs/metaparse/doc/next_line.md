# next_line

## Synopsis

```cpp
template <class SourcePosition, class Ch>
struct next_line
{
  // unspecified
};
```

## Description

Returns a new source position, pointing to the beginning of the next line.

## Header

```cpp
#include <mpllibs/metaparse/next_line.hpp>
```

## Expression semantics

For any `s` source position and `c` wrapped character the following are
equivalent

```cpp
mpllibs::metaparse::get_col<next_line<s, c>>::type

boost::mpl::int_<1>
```

```cpp
mpllibs::metaparse::get_line<next_line<s, c>>

boost::mpl::plus<mpllibs::metaparse::get_line<s>::type, boost::mpl::int_<1>>
```

```cpp
mpllibs::metaparse::get_prev_char<next_line<s, c>>::type

c
```

## Example

```cpp
typedef
  mpllibs::metaparse::get_line<
    next_line<mpllibs::metaparse::start, boost::mpl::char_<'b'>>
  >::type
  two;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



