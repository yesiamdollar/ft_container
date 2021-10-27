#include <iostream>
#include <vector>
#include "tools/iterator_traits.hpp"
#include <typeinfo>



int main(){
	
	std::vector<int> vec(5);
	if (typeid(ft::iterator_traits< std::vector<int>::iterator >::iterator_category) == typeid(std::random_access_iterator_tag))
		std::cout << "okay\n";
	// std::vector<int>::iterator::
	return 0;
}
