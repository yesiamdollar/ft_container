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
	VCTR<int> ft_new2;
	std::cout << std::endl;
	// ft_new2.reserve(1);
	VCTR<int>::iterator ft_it2(ft_new2.begin());
	
	// ft_new2.push_back(50);
	// ft_it2 = ft_new2.begin();
	// ft_it2++;
	// std::cout << *ft_it2 << std::endl;

	ft_new2.insert(ft_it2, 900);
	ft_it2++;
	std::cout << std::endl;
	ft_it2 = ft_new2.begin();
	// ft_new2.insert(ft_it2, 100);
	// ft_it2 = ft_new2.begin();
	// ft_new2.insert(ft_it2, 10);
	// ft_it2 = ft_new2.begin();
	// ft_new2.insert(ft_it2, 20);
	// ft_it2 = ft_new2.end();
	std::cout << *(ft_new2.insert(ft_it2, 800))<< std::endl;
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity : " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :" << ft_new2.size() << std::endl << std::endl;

	// print_vector(ft_new2.begin(), ft_new2.end());
	return 0;
}
