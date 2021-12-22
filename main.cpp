#include <iostream>
#include <vector>
// #include "tools/iterator_traits.hpp"
// #include "tools/iterator.hpp"
#include <typeinfo>
#include <iterator>
#include "containers/vector.hpp"
#include <unistd.h>
#include <stdio.h>

#define VCTR ft::vector

void print_vector(VCTR<int>::iterator ft_it_b, VCTR<int>::iterator ft_it_e)
{
	std::cout << "ft  :: ";
	for(; ft_it_b != ft_it_e ; ++ft_it_b)
	 {
		std:: cout << *ft_it_b << " ";
	 }
	std::cout << std::endl;
}
int NBTOFAIL = 99999;
struct S
{
	static int k;
	int *f;
	S() {
		f = new int();
		std::cout << "DEFAULT\n";
		k++;
	}

	S(S const& s) {


		f = new int();
		if(k > NBTOFAIL)
			throw "lol";
		std::cout << "COPY\n";
		k++;
	}
	~S()
	{
		delete f;
		std::cout << "DESTRUCT\n";

	}
};
int S::k = 0;
int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	{try
	{
		NBTOFAIL = 3;
		/* code */
		VCTR<S> p(600, S());
	}
	catch(...)
	{
		std::cerr << "e.what()" << '\n';
	}}
		system("leaks exec");
	
	// VCTR<int> p((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());
	// print_vector(p.begin(), p.end());
	// std::cout << p.size() << " " << p.capacity() <<std::endl;
	return 0;
}
