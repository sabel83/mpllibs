# Boxed value

A _boxed value_ is a type representing a constant value. It has a public static
`const` or `constexpr` member called `value`. The class represents that value as
a type, so it can be manipulated by [template metafunction](metafunction.html)s.
It has to be a [template metaprogramming value](metaprogramming_value.html).

For example the following `struct` represents the `true` value of type `bool`:

```cpp
struct true_type
{
  static constexpr bool value = true;
  using type = true_type;
};
```

The `value` member is the wrapped value. `true_type::type` is an alias of
`true_type` which makes it a template metaprogramming value.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

