# one_char

## Synopsis

```cpp
struct one_char;
```

This is a [parser](parser.html).

## Description

`one_char` accepts one character. The result of parsing is the accepted
character. It fails for empty input.

## Header

```cpp
#include <mpllibs/metaparse/one_char.hpp>
```

## Expression semantics

For any `s` non-empty compile-time string and `pos` source position the
following are equivalent

```cpp
get_result<one_char::apply<s, pos>>

boost::mpl::front<s>
```

```cpp
get_remaining<one_char::apply<s, pos>>

boost::mpl::pop_front<s>
```

The value of `get_position<one_char::apply<s, pos>>` depends on the first
character of the sequence and the value of the one parsed before that (which is
stored in the source position). `one_char` updates the source position's `col`
and `line` values based on the new line characters. It detects Linux (`\n`),
Windows (`\r\n`) and Mac (`\r`) line endings.

`one_char::apply<MPLLIBS_STRING(""), pos>` returns an error for every `pos`
source position.

## Example

```cpp
#include <mpllibs/metaparse/one_char.hpp>
#include <mpllibs/metaparse/start.hpp>
#include <mpllibs/metaparse/string.hpp>
#include <mpllibs/metaparse/get_result.hpp>
#include <mpllibs/metaparse/get_remaining.hpp>
#include <mpllibs/metaparse/is_error.hpp>

#include <type_traits>

using namespace mpllibs::metaparse;

static_assert(
  get_result<one_char::apply<MPLLIBS_STRING("foo"), start>>::type::value == 'f',
  "the result of parsing should be the first character of the input"
);

static_assert(
  std::is_same<
    MPLLIBS_STRING("oo"),
    get_remaining<one_char::apply<MPLLIBS_STRING("foo"), start>>::type
  >::type::value,
  "one_char should consume the first character of the input"
);

static_assert(
  is_error<one_char::apply<MPLLIBS_STRING(""), start>>::type::value,
  "it should return an error for empty input"
);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

