# Parsing error message

A _parsing error message_ is a [template metaprogramming
value](metaprogramming_value.html) with a `static std::string get_value()`
member function. This function returns the pretty-printed version of the error
the class represents. For example:

```cpp
struct example_error
{
  using type = example_error;

  static std::string get_value()
  {
    return "This is a formatted example error."
  }
};
```

Failing [parser](parser.html)s return parsing error messages as error messages.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

