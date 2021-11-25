#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>
#include "containers/vector.hpp"
#include <unistd.h>
#include <stdio.h>

#define VCTR ft::Vector

void print_vector(VCTR<int>::iterator ft_it_b, VCTR<int>::iterator ft_it_e)
{
	std::cout << "ft  :: ";
	for(; ft_it_b != ft_it_e ; ++ft_it_b)
	 {
		std:: cout << *ft_it_b << " ";
	 }
	std::cout << std::endl;
}

int main(){
	VCTR<int> ft_new(5, 100);

	VCTR<int>::iterator bb;
	VCTR<int>::const_iterator b2;
	b2 == bb;
	return 0;
}
