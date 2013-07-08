# foldr

## Synopsis

```cpp
template <class P, class State, class BackwardOp>
struct foldr
{
  template <class S, class Pos>
  struct apply
  {
    // unspecified
  };
};
```

## Description

Parser combinator taking a parser as argument. It applies the parser on the
input string repeatedly as long as the parser accepts the input. The result of
parsing is equivalent to `boost::reverse_fold<Sequence, State, BackwardOp>`,
where `Sequence` is the sequence of the results of the applications of `P`.

When the parser rejects the input for the first time, `foldr` still accepts
the input and the result of parsing is `State`.

## Header

```cpp
#include <mpllibs/metaparse/foldr.hpp>
```

## Expression semantics

For any `p` parser, `t` class, `f` metafunction class taking two arguments,
`s` compile-time string and `pos` source position

```cpp
boost::mpl::apply<foldr<p, t, f>, s, pos>
```

is equivalent to

```cpp
boost::mpl::apply<mpllibs::metaparse::return_<t>, s, pos>
```

when `boost::mpl::apply<p, s, pos>` returns an error. It is

```cpp
boost::mpl::apply<
  f,
  mpllibs::metaparse::get_result<boost::mpl::apply<p, s, pos>>::type,
  boost::mpl::apply_wrap2<
    foldr<p, t, f>,
    mpllibs::metaparse::get_remaining<boost::mpl::apply<p, s, pos>>,
    mpllibs::metaparse::get_position<boost::mpl::apply<p, s, pos>>
  >::type
>
```

otherwise.

## Example

```cpp
typedef boost::mpl::list<> empty_list;
typedef boost::mpl::push_front<boost::mpl::_2, boost::mpl::_1> push_front;

template <class P>
struct any : foldr<P, empty_list, push_front> {};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)


