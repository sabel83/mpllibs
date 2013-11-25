# case_

## Synopsis

```cpp
template <class Exp, class C1, ..., class Cn>
struct case_
{
  // unspecified
};
```

## Description

It implements the `case` construct of functional programming languages. The
classes `C1` ... `Cn` have to be instances one of the following templates:

```cpp
template <class Pattern, class Body>
struct matches;

template <class Pattern, class Body>
struct matches_c;
```

The arguments of both `matches` have to be syntaxes. When `case_` is evaluated,
the angyl-bracket expression `Exp` is evaluated and matched against the
`Pattern` patterns in order. When it matches one of them, the `Body` belonging
to it is returned. When the expression doesn't match any of the patterns, an
[`exception`](exception.html) is returned with a
[`no_case_matched`](no_case_matched.html) value. When the result of `Exp`
matches multiple patterns, the first one is used. The open variables of a
`Pattern` can be used in the `Body` belonging to it.

The maximum number of `matches` elements is limited by the value of
`MPLLIBS_LIMIT_CASE_SIZE` macro.

## Header

```cpp
#include <mpllibs/metamonad/case_.hpp>
```

## Expression semantics

For any `m, n > 0`, `e`, `p1`, ..., `pn`, `b1`, ..., `bn`, `q1`, ..., `qm`,
`c1`, ..., `cm` angly-bracket expressions, assuming that `e` matches all of
`q1`, ..., `qm` and does not match any of `p1`, ..., `pn`, the following are
equivalent:

```cpp
matches_c<p1, b1>
matches<syntax<p1>, syntax<b1>>
```

```cpp
case_<
  e,
  matches<p1, b1>,
  // ...
  matches<pn, bn>
>::type
exception<...>
```

```cpp
case_<
  e,
  matches<q1, c1>,
  // ...
  matches<qm, cm>
>::type
match_let<q1, e, c1>::type
```

```cpp
case_<
  e,
  matches<p1, b1>,
  // ...
  matches<pn, bn>,
  matches<q1, c1>,
  // ...
  matches<qm, cm>
>::type
match_let<q1, e, c1>::type
```

## Example

```cpp
using namespace mpllibs::metamonad::name;

template <class A>
struct maybe_something :
  boost::mpl::if_<
    typename boost::is_same<A, int>::type,
    just<double>,
    nothing
  >
{};

typedef
  eval_syntax<
    case_< maybe_something<int>::type,
      matches_c<just<var<x>>, returns<x>>,
      matches_c<nothing,      nothing>,
      matches_c<_,            nothing>
    >
  >::type
  this_is_double;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



