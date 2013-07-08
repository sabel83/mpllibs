# value_to_stream

## Synopsis

```cpp
template <class T>
struct value_to_stream
{
  typedef value_to_stream type;

  static std::ostream& run(std::ostream&);
};
```

## Description

Displays the value of `T` on the output stream. When `T` has `T::get_value()`,
the result of that function is used. When `T` has `T::value`, that object is
used. Otherwise the string `"???"` is displayed.

## Header

```cpp
#include <mpllibs/metamonad/value_to_stream.hpp>
```

## Example

```cpp
value_to_stream<mpl::int_<13> >::run(std::cout);
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)



