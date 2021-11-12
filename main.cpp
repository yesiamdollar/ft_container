#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>
#include "vector/vector.hpp"
#include <unistd.h>
#include <stdio.h>

int main(){
	#if 0
	ft::Vector<int> v(10, 30);
	v[8] = 33;//
	for (ft::Vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << v.size() << '\n';
	#else
	ft::Vector<int> v(10, 30);
	// for (ft::Vector<int>::iterator it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it << ' ';
	std::cout << "\n" << v.size() << ' ' << v.capacity() << "\n";
	ft::Vector<int>::iterator it = v.begin();
	std::cout << std::addressof(it);
	ft::Vector<int>::iterator it2 =  v.insert(v.begin() + 3, 32);
	std::cout << "\n";
	// std::cout << it2 - v.begin() << std::endl;
	// for (ft::Vector<int>::iterator it = v.begin(); it != v.end(); it++)
	// 	std::cout << *it << ' ';
	std::cout << "\n";
	ft::Vector<int>::iterator it3 = v.begin();
	std::cout << std::addressof(it3);
	std::cout << "\n";
	
	std::cout << "\n" << v.size() << ' ' << v.capacity() << "\nsys \n";
	#endif
}
