#include <iostream>
#include <map>
#include "containers/map.hpp"
template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
            return false;
    return true;
}

int main ()
{
	std::map<std::string, std::string, std::greater<std::string> > m1, m2;
	ft::map<std::string, std::string, std::greater<std::string> > ft_m1, ft_m2;

	// ft_m1.insert(ft::make_pair("a", "a"));
	// ft_m1.insert(ft::make_pair("b", "a"));
	// ft_m1.insert(ft::make_pair("c", "a"));

	// ft::map<int, int>::rbtree a; 

	// a.insert(ft::make_pair(1, 1));
	// a.insert(ft::make_pair(2, 1));
	// a.insert(ft::make_pair(3, 1));

	// a.printTree();
	// m1["γ"] = "gamma";
	// m1["β"] = "beta";
	// m1["α"] = "alpha";
	// m1["γ"] = "gamma";

	// m2["ε"] = "eplsilon";
	// m2["δ"] = "delta";
	// m2["ε"] = "epsilon";

	ft_m1["1"] = "3";
	ft_m1["b"] = "5";
	ft_m1["0"] = "6";
	ft_m1["2"];
	ft_m1["3"];
	// ft_m1["γ"] = "gamma";

	// ft_m2["ε"] = "eplsilon";
	// ft_m2["δ"] = "delta";
	// ft_m2["ε"] = "epsilon";

	return 0;
}