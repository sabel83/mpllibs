# nth_of

## Synopsis

```cpp
template <
  class N,
  class P0,
  // ...
  class Pk
>
struct nth_of
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator applying a number of parsers in sequence. It accepts an input
when all parsers accept it. The result of parsing is the result of the `N`.
parser. `N` is a nullary metafunction.

The maximum number of parsers `nth_of` accepts can be specified with the
`MPLLIBS_SEQUENCE_MAX_ARGUMENT` macro. Its default value is `5`.

## Header

```cpp
#include <mpllibs/metaparse/nth_of.hpp>
```

## Expression semantics

For any `p0`, ..., `pn` parsers and `k` boxed integer value the following are
equivalent

```cpp
nth_of<k, p0, ..., pn>

mpllibs::metaparse::nth_of_c<k::type::value, p0, ..., pn>
```

## Example

```cpp
typedef
  nth_of<
    boost::mpl::int_<1>,
    mpllibs::metaparse::digit,
    mpllibs::metaparse::digit
  >
  second_digit;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


