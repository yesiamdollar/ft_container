#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>
#include "vector/vector.hpp"
#include <unistd.h>


int main(){
	// std::vector<int> v1(4, 42);
	ft::Vector<int> v(4, 42);

	v[2] = 5;

	ft::Vector<int>::reverse_iterator it = v.rbegin();
	for (; it != v.rend(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}
