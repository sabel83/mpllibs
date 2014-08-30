# Predicate

A _predicate_ (or unary predicate) is a [template metafunction
class](metafunction_class.html) taking one argument and returning a [boxed
value](boxed_value.html) of type `bool`.

For example the following predicate checks if its argument is the boxed `char`
value `x`:

```cpp
struct is_x
{
  template <class C>
  struct apply
  {
    static constexpr bool value = (C::value == 'x');
    using type = apply;
  };

  using type = is_x;
};
```

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

