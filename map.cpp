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

bool fncomp(char lhs, char rhs) { return lhs < rhs; }


struct classcomp
{
    bool operator()(const char &lhs, const char &rhs) const
    {
        return lhs < rhs;
    }
};

#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

int main ()
{
    std::map<int, std::string> m;
    ft::map<int, std::string> my_m;

    for (int i = 0; i < 5; ++i)
    {
        m.insert(std::make_pair(13, "HELLO"));
        my_m.insert(ft::make_pair(13, "HELLO"));
    }

    ft::map<int, std::string>::iterator my_it = my_m.begin();
    std::map<int, std::string>::iterator it = m.begin();
    /*---------------------------------------------- */
    EQUAL(it->second.length() == my_it->second.length());
	return 0;
}