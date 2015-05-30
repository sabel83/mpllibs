```cpp
using exp_parser8 = build_parser< sequence< int_token, /* parse the first <number> */ transform< any<sequence<plus_token, int_token>>, /* parse the "+ <number>" elements */ /* lambda expression summarising the "+ <number>" elements using fold */ boost::mpl::lambda< /* The folding expression we have just created */ boost::mpl::fold< boost::mpl::_1, /* the argument of the lambda expression, the result */ /* of the any<...> parser */ boost::mpl::int_<0>, boost::mpl::quote2<sum_items> > >::type > > >;

```
