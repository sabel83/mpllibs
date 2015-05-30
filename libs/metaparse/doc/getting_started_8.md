```cpp
template <class Sum, class Item> struct sum_items : boost::mpl::plus< Sum, typename boost::mpl::at_c<Item, 1>::type > {};

```
