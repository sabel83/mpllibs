# concat

## Synopsis

```cpp
template <class A, class B>
struct concat
{
  // unspecified
};
```

## Description

Concatenates two sequences.

## Header

```cpp
#include <mpllibs/metamonad/concat.hpp>
```

## Expression semantics

For any `a` and `b` sequences:

```cpp
concat<a, b>::type
```

is equivalent to

```cpp
boost::mpl::insert_range<a, boost::mpl::end<a>::type, b>::type
```

## Example

```cpp
typedef
  concat<
    boost::mpl::list<boost::mpl::int_<1>, boost::mpl::int_<2> >,
    boost::mpl::list<boost::mpl::int_<3>, boost::mpl::int_<4> >
  >
  list_of_1_2_3_4;
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2013.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



