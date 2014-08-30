# alphanum

## Synopsis

```cpp
struct alphanum;
```

This is a [parser](parser.html).

## Description

It accepts one character in the range `a-z`, `A-Z` or `0-9`. The
result of the parser is the accepted character.

## Header

```cpp
#include <mpllibs/metaparse/alphanum.hpp>
```

## Expression semantics

The following are equivalent:

```cpp
alphanum

one_of<digit, letter>
```

## Example

```cpp
#include <mpllibs/metaparse/alphanum.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/is_error.hpp>
#include <mpllibs/metaparse/get_result.hpp>

using namespace mpllibs::metaparse;

static_assert(
  !is_error<alphanum::apply<MPLLIBS_STRING("0"), start>>::type::value,
  "alphanum should accept a digit"
);

static_assert(
  !is_error<alphanum::apply<MPLLIBS_STRING("x"), start>>::type::value,
  "alphanum should accept a character"
);

static_assert(
  get_result<alphanum::apply<MPLLIBS_STRING("x"), start>>::type::value == 'x',
  "the result of parsing should be the character value"
);

static_assert(
  is_error<alphanum::apply<MPLLIBS_STRING(","), start>>::type::value,
  "alphanum should reject a comma"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


