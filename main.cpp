#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>
#include "vector/vector.hpp"
#include <unistd.h>
#include <stdio.h>
typedef typename ft::Vector<int> vector;

int main(){
	vector vec(7, 100);
	for (int i = 0; i < vec.size(); i++)
		vec[i] = vec[i] + i;
	std::cout << vec.size() << ' ' << vec.capacity() << '\n';
	for (int i =0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
	std::cout << std::addressof(vec[0]) << '\n';
	vec.erase(vec.begin() + 3, vec.end());
	std::cout << std::addressof(vec[0]) << '\n';

	std::cout << vec.size() << ' ' << vec.capacity() << '\n';
	for (int i =0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
	std::cout << vec[6] << '\n';
	return 0;
}
