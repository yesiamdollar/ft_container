#include "vector.hpp"

// #include <vector>

// #include <iterator>

class test{
	public:
		test(){
			std::cout << "test created" << std::endl;
			_c = 0;
		}
		// test(int c){
		// 	std::cout << "test created " << c << std::endl;
		// }
		~test(){

			std::cout << "test destroyed \n";
		}
		int _c;
};

int main(){
	ft::vector<int> fill(3);

	ft::vector<int>::iterator it = fill.begin();
	// std::vector<test> sys(3);
	
	// std::vector<test>::iterator i = sys.begin();
	// std::cout << fill[0] << '\n';
	// for(i = sys.begin(); i != sys.end(); i++)
	// 	std::cout << *i << '\n';
	// std::cout << fill.capacity() << '\n';
	return (0);
}