# Template metafunction class

A _template metafunction class_ is a type with a public nested [template
metafunction](metafunction.html) called `apply`. Since it is a type, it can be
passed to template metafunctions as arguments and metafunctions can return it as
their result. This makes it possible to implement _higher-order template
metafunctions_, which are template metafunctions taking template metafunctions
as arguments or returning template metafunctions as their result.

For example this is the identitiy template metafunction class:

```cpp
struct identity
{
  template <class T>
  struct apply
  {
    using type = T;
  };
  using type = identity;
};
```

This metafunction class is called `identity`. It takes one argument, `T`. The
result of calling this metafunction class is its argument, `T`. Note that the
`identity` metafunction class is also a [template metaprogramming
value](metaprogramming_value.html), so it can be an argument or the result of a
template metafunction.

To call this metafunction, one has to call the nested template metafunction.
For example:

```cpp
identity::apply<std::integral_constant<int, 13>>::type
```

The above example calls the metafunction class `identity` with
`std::integral_constant<int, 13>` as its argument.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

