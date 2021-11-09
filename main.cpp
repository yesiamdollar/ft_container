#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>
#include "vector/vector.hpp"



int main(){
	// std::vector<char> v1(4, 'a');
	ft::vector<char> v(4, 'a');

	// v1[3] = 'b';
	v[3] = 'b';
	ft::vector<char>::reverse_iterator it = v.rbegin();
	std::cout << *it << '\n';
}
