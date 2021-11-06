#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>



int main(){
	std::vector<int> v(3, 2);

	std::cout << std::hex << &v << std::endl;
	v.reserve(10);
	std::cout << v.capacity() << std::endl;
	std::cout << std::hex << &v << std::endl;
	v.push_back(33);
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << &it << '\n';
	return 0;
}
