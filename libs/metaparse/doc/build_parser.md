# build_parser

## Synopsis

```cpp
template <class P>
struct build_parser
{
  template <class S>
  struct apply
  {
    // unspecified
  };
};
```

## Description

This function can generate the external interface of a parser. It takes a
parser as argument and builds a metafunction class that accepts an input
string and returns the result of parsing. It generates a compilation error
when parsing fails.

## Header

```cpp
#include <mpllibs/metaparse/build_parser.hpp>
```

## Expression semantics

For any `p` parser and `s` compile-time string

```cpp
boost::mpl::apply<build_parser<p>, s>
```

is equivalent to

```cpp
mpllibs::metaparse::get_result<boost::mpl::apply<p, s> >
```

## Example

```cpp
struct main_of_dsl_parser :
  // ...
{};

typedef build_parser<main_of_dsl_parser> dsl_parser;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


