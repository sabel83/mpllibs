# build_parser

## Synopsis

```cpp
template <class P>
struct build_parser;
```

This is a [template metafunction](metafunction.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P`</td>
    <td>[parser](parser.html)</td>
  </tr>
</table>

## Description

It generates a simple interface for parser. It returns a metafunction class that
takes an input string, parses it with `P` and returns the result of parsing. It
generates a compilation error when parsing fails.

## Return value

It returns a [template metafunction class](metafunction_class.html):

```cpp
struct
{
  template <class S>
  struct apply;
};
```

Arguments:

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`S`</td>
    <td>[string](string.html)</td>
  </tr>
</table>

## Header

```cpp
#include <mpllibs/metaparse/build_parser.hpp>
```

## Expression semantics

For any `p` parser and `s` compile-time string

```cpp
build_parser<p>::type::apply<s>
```

is equivalent to

```cpp
get_result<p::apply<s>>
```

## Example

```cpp
#include <mpllibs/metaparse/build_parser.hpp>
#include <mpllibs/metaparse/int_.hpp>
#include <mpllibs/metaparse/string.hpp>

using namespace mpllibs::metaparse;

using string_to_int = build_parser<int_>::type;

static_assert(
  string_to_int::apply<MPLLIBS_STRING("1113")>::type::value == 1113,
  "string_to_int should be a metafunction turning a string into an int"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


