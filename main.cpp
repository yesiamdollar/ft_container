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
	ft::Vector<int>  vec(7, 100);
	ft::Vector<int>::reverse_iterator it = vec.rbegin() + 2;
	return 0;
}
