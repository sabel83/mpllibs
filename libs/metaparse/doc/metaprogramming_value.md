# Template metaprogramming value

A _template metaprogramming value_ is a
[nullary template metafunction](nullary_metafunction.html) returning itself.
For example:

```cpp
struct void_
{
  using type = void_;
};
```

This template metaprogramming value is called `void_`. It is a nullary
metafunction returning itself as its result. Because of this, it can be treated
as a nullary metafunction and evaluated any number of times. For example 
`void_::type::type::type` is still `void_`.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

