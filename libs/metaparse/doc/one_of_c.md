# one_of_c

## Synopsis

```cpp
template <long P1, long P2, /* ... */ long Pn>
struct one_of_c;
```

This is a [parser](parser.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`P1` .. `Pn`</td>
    <td>character values</td>
  </tr>
</table>

## Description

It accepts inputs beginning with any of the `P1`, ..., `Pn` characters. The
result of parsing is the first character of the input.

The maximum number of characters that can be provided is defined by the
`MPLLIBS_LIMIT_ONE_OF_SIZE` macro. Its default value is `20`.

## Header

```cpp
#include <mpllibs/metaparse/one_of_c.hpp>
```

## Expression semantics

For any `c1`, ..., `cn` characters

```cpp
one_of_c<c1, ..., cn>
```

is equivalent to

```cpp
one_of<lit_c<c1>, /* ... */, lit_c<cn>>
```

## Example

```cpp
#include <mpllibs/metaparse/one_of_c.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/is_error.hpp>

using namespace mpllibs::metaparse;

using whitespace = one_of_c<' ', '\n', '\r', '\t', '\v'>;

static_assert(
  get_result<whitespace::apply<MPLLIBS_STRING(" "), start>>::type::value == ' ',
  "the result of parsing should be the first character of the input"
);

static_assert(
  is_error<whitespace::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "it should return an error when the input does not begin with a whitespace"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

