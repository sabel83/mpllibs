# Nullary template metafunction

A _nullary template metafuncion_ is a [template metafunction](metafunction.html)
taking 0 arguments. It is a type with a nested type called `type`, which is the
return value of the nullary metafunction. For example:

```cpp
struct always13
{
  using type = std::integral_constant<int, 13>;
};
```

This metafunction is called `always13`. It is a nullary metafunction, because it
takes no arguments. It always returns `std::integral_constant<int, 13>`.

To call this metafunction, one has to access its `::type`. For example:

```cpp
always13::type
```

The above example calls the metafunction to get
`std::integral_constant<int, 13>`.

<p class="copyright">
Copyright Abel Sinkovics (abel at elte dot hu) 2014.
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE_1_0.txt or copy at
[http://www.boost.org/LICENSE_1_0.txt](http://www.boost.org/LICENSE_1_0.txt)
</p>

[[up]](reference.html)

