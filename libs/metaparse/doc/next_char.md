# next_char

## Synopsis

```cpp
template <class SourcePosition, class Ch>
struct next_char
{
  // unspecified
};
```

## Description

Returns a new source position, pointing to the next character of the same line.

## Header

```cpp
#include <mpllibs/metaparse/next_char.hpp>
```

## Expression semantics

For any `s` source position and `c` wrapped character the following are
equivalent

```cpp
mpllibs::metaparse::get_col<next_char<s, c> >

boost::mpl::plus<mpllibs::metaparse::get_col<s>::type, boost::mpl::int_<1> >
```

```cpp
mpllibs::metaparse::get_line<next_char<s, c> >

mpllibs::metaparse::get_line<s>
```

```cpp
mpllibs::metaparse::get_prev_char<next_char<s, c> >::type

c
```

## Example

```cpp
typedef
  mpllibs::metaparse::get_col<
    next_char<mpllibs::metaparse::start, boost::mpl::char_<'x'> >
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



