# foldrp

## Synopsis

```cpp
template <class P, class StateP, class BackwardOp>
struct foldrp
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

The same as [`foldr`](foldr.html), but before folding it applies a parser,
`StateP` on the input. If it fails, `foldrp` fails. If it succeeds, `foldrp`
works as `foldr` taking the result of `StateP` as the initial state.

## Header

```cpp
#include <mpllibs/metaparse/foldrp.hpp>
```

## Expression semantics

For any `p` parser, `pt` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position let `pos_` be the position
where the repeated application of `p` on `s` fails for the first time. Let
`s_` be the postfix of `s` starting at that position.

```cpp
boost::mpl::apply<foldrp<p, pt, f>, s, pos>
```

is equivalent to

```cpp
apply<pt, s_, pos_>
```

when the above expression returns a parsing error. It is

```cpp
boost::mpl::apply<
  mpllibs::metparase::return_<
    boost::mpl::apply<
      foldr<p, get_result<apply<pt, s_, pos_> >::type, f>,
      s,
      pos
    >
  >,
  get_remaining<apply<pt, s_, pos_> >::type,
  get_position<apply<pt, s_, pos_> >::type
>
```

otherwise.

## Example

```cpp
typedef boost::mpl::list<> empty_list;
typedef boost::mpl::push_front<boost::mpl::_2, boost::mpl::_1> push_front;

template <class P>
struct any : foldrp<P, mpllibs::metaparse::return_<empty_list>, push_front> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


