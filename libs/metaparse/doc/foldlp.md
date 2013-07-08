# foldlp

## Synopsis

```cpp
template <class P, class StateP, class ForwardOp>
struct foldlp
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

The same as `[foldl](foldl.html)`, but before folding it applies a parser,
`StateP` on the input. If it fails, `foldlp` fails. If it succeeds, `foldlp`
works as `foldl` taking the result of `StateP` as the initial state.

## Header

```cpp
#include <mpllibs/metaparse/foldlp.hpp>
```

## Expression semantics

For any `p` parser, `pt` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position

```cpp
boost::mpl::apply<foldlp<p, pt, f>, s, pos>
```

is equivalent to

```cpp
apply<pt, s, pos>
```

when the above expression returns a parsing error. It is

```cpp
boost::mpl::apply<
  foldl<p, get_result<apply<pt, s, pos>>::type, f>,
  get_remaining<apply<pt, s, pos>>::type,
  get_position<apply<pt, s, pos>>::type
>
```

otherwise.

## Example

```cpp
typedef boost::mpl::list<> empty_list;
typedef boost::mpl::push_back<boost::mpl::_2, boost::mpl::_1> push_back;

template <class P>
struct any : foldlp<P, mpllibs::metaparse::return_<empty_list>, push_back> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


