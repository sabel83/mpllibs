# concat_map

## Synopsis

```cpp
template <class List, class F>
struct concat_map
{
  // unspecified
};
```

## Description

`concat_map` is a metafunction applying the function `F` on all elements of the
sequence `List`. The result of applying `F` on an element is expected to be a
sequence. These sequences are concatened and that is the result of this
operation.

## Header

```cpp
#include <mpllibs/metamonad/concat_map.hpp>
```

## Expression semantics

For any `l` sequence of `n` elements and `f` metafunction taking one argument:

```cpp
concat_map<l, f>::type
```

is equivalent to

```cpp
concat<
  boost::mpl::apply<f, boost::mpl::at_c<l, 0>::type>::type,
  concat<
    boost::mpl::apply<f, boost::mpl::at_c<l, 1>::type>::type,
    // ...
      boost::mpl::apply<f, boost::mpl::at_c<l, n>::type>::type
    // ...
  >::type
>::type
```

## Example

```cpp
typedef
  concat_map<
    boost::mpl::list<boost::mpl::int_<1>, boost::mpl::int_<2> >,
    lambda_c<t, list<t, t> >
  >::type
  list_of_1_1_2_2;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2013.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



