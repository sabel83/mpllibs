# unpaired

## Synopsis

```cpp
namespace error
{
  template <int Line, int Col, class Msg = boost::mpl::na>
  struct unpaired;
}
```

This is a [parsing error message](parsing_error_message.html).

## Arguments

<table cellpadding='0' cellspacing='0'>
  <tr>
    <td>`Line`</td>
    <td>`int` value</td>
  </tr>
  <tr>
    <td>`Col`</td>
    <td>`int` value</td>
  </tr>
  <tr>
    <td>`Msg`</td>
    <td>[template metaprogramming value](metaprogramming_value.html)</td>
  </tr>
</table>

## Description

Template class representing the error that the closing element of an
"_opening element_ ... _closing element_" structure is missing. (eg. a closing
paren is missing). `Line` and `Col` point to the beginning of the _opening
element_ (eg. the opening paren). `Msg` is the error message the parser trying
to parse the _closing element_ failed with.

It supports currying: `unpaired<Line, Col>` is a [template metafunction class](
metafunction_class.html) taking one argument: the `Msg` element and returning
the corresponding `unpaired` value.

## Header

```cpp
#include <mpllibs/metaparse/error/unpaired.hpp>
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2011.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

