#include <iostream>
// #include <time.h>
#include <sys/time.h>
#if NS
#define NAMESPACE "FT  : "
#include "containers/vector.hpp"
#include "containers/stack.hpp"
// #include "map/map.hpp"
#define VCTR ft::Vector
#define STACK ft::Stack
#else
#define NAMESPACE "STD : "
#define VCTR std::vector
#define STACK std::stack
#include <vector>
#include <stack>
#include <map>
namespace ft = std;
#endif

	// helper functions 
bool mypredicate (int i, int j)
	{return (i==j);}

bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }


void print_vector(VCTR<int>::iterator ft_it_b, VCTR<int>::iterator ft_it_e)
{
	std::cout << "ft  :: ";
	for(; ft_it_b != ft_it_e ; ++ft_it_b)
	 {
		std:: cout << *ft_it_b << " ";
	 }
	std::cout << std::endl;
}

// long	get_timestamp(void)
// {
// 	struct timeval	creation;
// 	long			timestamp;

// 	gettimeofday(&creation, NULL);
// 	timestamp = (creation.tv_sec * 1000.0 + creation.tv_usec / 1000.0);
// 	return (timestamp);
// }

int main(void)
{
	
	clock_t start = clock();
    	std::cout << "	======================>\033[1;31m init and iterators tests \033[0m<============================ " << std::endl;
	// Creating vects of diffrent types

	VCTR<int> ft_vect_int; // call default constructor 
	VCTR<int> vect_1(1e6, 5); // call fill constructor
	VCTR<char> ft_vect_char(1e6, 'a');
	VCTR<float> ft_vect_float;VCTR<int>::iterator ft_it;
	VCTR<char>::iterator ft_it_char(ft_vect_char.begin());
	VCTR<int>::const_iterator ft_itc(vect_1.end());

	(void)ft_it_char;
	// std_it = ft_itc;
	ft_itc = ft_it;

	// *ft_itc = 8;
	// *std_itc = 8;

	std::cout << (ft_itc == ft_it) << std::endl;
	std::cout << (ft_itc != ft_it) << std::endl << std::endl;

	for(int i = 0; i < 10; ++i)
		ft_vect_int.push_back(i);
	VCTR<int> ft_vect_int1(ft_vect_int.begin(), ft_vect_int.end()); // call range constructor 

	ft_it = ft_vect_int1.begin();
	for(ft_it = ft_vect_int1.begin(); ft_it != ft_vect_int1.end(); ++ft_it)
		std::cout << *ft_it << std::endl;


	std::cout << "	======================>\033[1;31m member functions tests \033[0m<============================ " << std::endl;

	std::cout << ft_vect_int.max_size() << std::endl;

	VCTR<int> ft_vect_int2; 
	for(int i = 0; i < 100; i += 20)
		ft_vect_int2.push_back(i);
	std::cout << "Capacity: " << ft_vect_int2.capacity() << std::endl;
	
	print_vector(ft_vect_int2.begin(), ft_vect_int2.end());

	ft_vect_int2.reserve(50);

	std::cout << "Capacity: " << ft_vect_int2.capacity() << std::endl;
	
	print_vector(ft_vect_int2.begin(), ft_vect_int2.end());
	try
	{
	// ft_vect_int2.reserve(4611686018427387999);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "Capacity:  " << ft_vect_int2.capacity() << std::endl;

	ft_vect_int1[8] = 19;
	std::cout << ft_vect_int1[8] << std::endl;
	
	ft_vect_int1[0] = 100;
	std::cout << ft_vect_int1.back() << std::endl;

	VCTR<int> ft_new(25, 0);
	
	std::cout << "vect 2 Capacity : " << ft_vect_int2.capacity() << std::endl;

	ft_new.assign(ft_vect_int2.begin(), ft_vect_int2.end());

	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;

	print_vector(ft_new.begin(), ft_new.end());

	ft_new.assign(10, 0);

	print_vector(ft_new.begin(), ft_new.end());
	
	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;
	
	ft_new.assign(20, 1);
	
	print_vector(ft_new.begin(), ft_new.end());
	
	std::cout << "Capacity:  : " << ft_new.capacity() << std::endl;
	std::cout << "Size: " << ft_new.size() << std::endl;

	VCTR<int> ft_new1(10, 0);

	// ft_new1.reserve(100);
	for (int i = 0; i < 2; ++i)
		ft_new1.push_back(i);
	print_vector(ft_new1.begin(), ft_new1.end());
	std::cout << "Capacity:  : " << ft_new1.capacity() << std::endl;
	std::cout << "Size: " << ft_new1.size() << std::endl;

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
	ft_new2.insert(ft_it2, 100);
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 10);
	ft_it2 = ft_new2.begin();
	ft_new2.insert(ft_it2, 20);
	// ft_it2--;
	ft_it2 = ft_new2.end();
	// std_it2++;
	// ft_it2++;
	std::cout << *(ft_new2.insert(ft_it2, 800))<< std::endl;
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity : " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :" << ft_new2.size() << std::endl << std::endl;

	print_vector(ft_new2.begin(), ft_new2.end());
	ft_it2 = ft_new2.begin();
	// ft_it2--;

	ft_new2.insert(ft_it2, 1, 55);
		print_vector(ft_new2.begin(), ft_new2.end());
	ft_it2 = ft_new2.begin();
	ft_it2++;
	ft_new2.insert(ft_it2, 190);
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout << "ft capacity :  " << ft_new2.capacity() << std::endl;
	std::cout << "ft size :      " << ft_new2.size() << std::endl << std::endl;
	

	VCTR<int> ft_new3(1, 0);
	ft_new3.reserve(10);
	ft_new3.push_back(10);
	ft_new3.push_back(20);
	ft_new3.push_back(30);
	ft_new3.push_back(40);
	ft_new3.insert(ft_new3.begin(), ft_new2.begin(), ft_new2.end());

	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl << std::endl;

	std::cout << *(ft_new3.erase(ft_new3.end()  - 3)) << std::endl;
	std::cout << *(ft_new3.erase(ft_new3.begin() + 3, ft_new3.end())) << std::endl;

	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl << std::endl;

	std::cout << "iter " << ft_new3.end() - ft_new3.begin() << std::endl;

	VCTR<int> ft_new4(20, 0);
	ft_new4 = ft_new3;
	std::cout << "print new4" << std::endl << std::endl;
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;

	ft_new3.push_back(3333);
	ft_new3.push_back(20);
	ft_new3.push_back(30);
	ft_new3.push_back(3333);
	ft_new3.swap(ft_new4);
	std::cout << std::endl;
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;
	std::cout << "print new3" << std::endl << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft capacity : " << ft_new3.capacity() << std::endl;
	std::cout << "ft size :" << ft_new3.size() << std::endl;

	ft_new4.clear();
	print_vector(ft_new4.begin(), ft_new4.end());
	std::cout << "ft capacity : " << ft_new4.capacity() << std::endl;
	std::cout << "ft size :" << ft_new4.size() << std::endl;
	
	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	print_vector(ft_new2.begin(), ft_new2.end());
	ft::swap(ft_new3, ft_new2);
	std::cout << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	print_vector(ft_new2.begin(), ft_new2.end());
	std::cout <<  "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;
	ft_new3.resize(12, 10);
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout <<  "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;
	ft_new3.resize(13, 6);
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft size :" << ft_new3.size() << "\nft capacity : " << ft_new3.capacity() << std::endl;

std::cout << "	======================>\033[1;31m Non-member functions tests \033[0m<============================ " << std::endl << std::endl;
	VCTR<int> foo (3,200);
	VCTR<int> bar (3,300);

	if (foo == bar)
		std::cout << "equal\n";
	if (foo != bar)
		std::cout << "not equal \n";
	if (foo < bar)
		std::cout << "foo is less than bar" << std::endl;
	if (foo <= bar)
		std::cout << "foo is less than or equal bar" << std::endl;
	if (bar > foo)
		std::cout << "bar is greater than foo" << std::endl;
	if (foo >= bar)
		std::cout << "foo is greater than or equal bar" << std::endl;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	VCTR<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;                                 // myvector: 20 40 60 81 100

	// using predicate comparison:
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n"<< std::endl;
  char foo1[]="Apple";
  char bar1[]="apartment";

  std::cout << std::boolalpha;

  std::cout << "Comparing foo1 and bar1 lexicographically (foo1<bar1):\n";

  std::cout << "Using default comparison (operator<): ";
  std::cout << ft::lexicographical_compare(foo1,foo1+5,bar1,bar1+9);
  std::cout << '\n';

  std::cout << "Using mycomp as comparison object: ";
  std::cout << ft::lexicographical_compare(foo1,foo1+5,bar1,bar1+9,mycomp);
  std::cout << std::endl;

std::cout << "	======================>\033[1;31m iteartors && rev_iterators arithmetic operations tests \033[0m<============================ " << std::endl << std::endl;
	print_vector(ft_new3.begin(), ft_new3.end());
	std::cout << "ft::size  :" <<ft_new3.size() << " ft::capacity  :" << ft_new3.capacity() << std::endl<< std::endl;

	VCTR<int>::iterator ft_it3(ft_new3.begin());
	VCTR<int>::const_iterator ft_it30(ft_new3.begin());
	if (ft_it30 == ft_it3)
		std::cout << "equal \n";

	std::cout << *(4 + ft_it3) << std::endl;
	std::cout << *ft_it3++ << std::endl;
	std::cout << *(ft_it3 + 2) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	std::cout << *(ft_it3 += 1) << std::endl;	
	std::cout << *ft_it3 << std::endl;

	
	std::cout << std::endl;
	ft_it3 = ft_new3.end();
	--ft_it3;
	ft_it3--;
	std::cout << *ft_it3-- << std::endl;
	std::cout << *(ft_it3 - 6) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	std::cout << *(ft_it3 -= 9) << std::endl;	
	std::cout << *ft_it3 << std::endl;
	ft_it3 = ft_new3.begin();
	std::cout << (ft_new3.end() - ft_it3) << std::endl;
	
	std::cout << std::endl;
	std::cout << (ft_it3 < ft_new3.end()) << std::endl;
	std::cout << (ft_it3 > ft_new3.end()) << std::endl;
	std::cout << (ft_it3 <= ft_new3.end()) << std::endl;
	std::cout << (ft_it3 >= ft_new3.end()) << std::endl;
	std::cout << *(ft_it3.base()) << std::endl;
	std::cout << ft_it3[4] << std::endl;


	std::cout << std::endl;
	VCTR<int>::reverse_iterator ft_rit3(ft_new3.end() - 1);
	VCTR<int>::const_reverse_iterator ft_crit13(ft_new3.rend());
	if (ft_crit13 == ft_new3.rend())
		std::cout << "equal \n";
	std::cout << *ft_rit3 << std::endl;
	ft_rit3 = ft_new3.rbegin();
	std::cout << *ft_rit3 << std::endl;	
	std::cout << *(ft_rit3 + 8) << std::endl;
	++ft_rit3;
	ft_rit3++;
	std::cout << *ft_rit3 << std::endl;
	ft_rit3 += 5;
	std::cout << *ft_rit3 << std::endl;
	std::cout << *(ft_rit3 - 1) << std::endl;	
	std::cout << *ft_rit3-- << std::endl;
	std::cout << *--ft_rit3 << std::endl;
	std::cout << *ft_rit3 << std::endl;
	std::cout << *(ft_rit3 -= 5) << std::endl;

	std::cout << std::endl;

	ft_rit3 = ft_new3.rend();
	std::cout << ft_rit3[1] << std::endl;
	
	std::cout << *(ft_new3.rend() - 2) << std::endl;
	VCTR<int>::const_reverse_iterator ft_crit3(ft_new3.end() - 1);

	std::cout << *ft_crit3 << std::endl;

	// *ft_crit3 = 8; // compilation error 

	std::cout << std::endl;

	std::cout << (ft_rit3 < ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 <= ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 > ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 >= ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 != ft_new3.rend()) << std::endl;
	std::cout << (ft_rit3 == ft_new3.rend()) << std::endl;

	ft_rit3 = ft_new3.rbegin();
	std::cout << *(8 + ft_rit3) << std::endl;

	std::cout << ft_new3.rbegin() - ft_new3.rend() << std::endl;


	


// 	std::cout << "	======================>\033[1;31m STACK tests \033[0m<============================ " << std::endl << std::endl;

	STACK<int> st;
	STACK<int> st2(st);
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);

	for(size_t i = 0; i < st.size(); ++i)
	{
		std::cout << st.top() << std::endl;
	}

	std::cout << st2.empty() << std::endl;

	st.pop();
	st.pop();
	st.pop();
	
	st.push(200);
	st.push(300);
	st.push(400);

	for(size_t i = 0; i < st.size(); ++i)
		std::cout << st.top()<< std::endl;

	std::cout << std::endl;

	std::cout << (st2 == st) << std::endl;

	std::cout << (st2 != st) << std::endl;

	std::cout << (st2 > st) << std::endl;
	std::cout << (st2 >= st) << std::endl;
	std::cout << (st2 < st) << std::endl;
	std::cout << (st2 <= st) << std::endl;

	std::cout << (st > st2) << std::endl;
	std::cout << (st >= st2) << std::endl;
	std::cout << (st < st2) << std::endl;
	std::cout << (st <= st2) << std::endl;

// 	std::cout << "	======================>\033[1;31m MAP tests \033[0m<============================ " << std::endl << std::endl;


// 	ft::map<int, std::string> ft_map;

// 	for(int i = 0; i < 1e5; ++i)
// 		ft_map.insert(ft::make_pair<int, std::string>(i, "value"));
// 	ft::map<int, std::string>::iterator ft_iter(ft_map.begin());
// 	ft::map<int, std::string>::iterator ft_iter1(ft_map.end());
// 	std::cout << (ft_map.insert(ft_iter1, ft::make_pair<int, std::string>(50, "value")))->first << std::endl;

// 	ft::map<int, std::string> ft_map1(ft_iter, ft_iter1);

// 	ft::map<int, std::string> ft_map6;
// 	ft_map6.insert(ft_map.begin(), ft_map.end());
	
// 	ft_iter = ft_map1.begin();
// 	ft_iter1 = ft_map1.end();
// 	for(;ft_iter != ft_iter1; ++ft_iter)
// 		std::cout << ft_iter->first << " ";
// 	std::cout << std::endl;

// 	ft_iter = ft_map6.begin();
// 	ft_iter1 = ft_map6.end();
// 	for(;ft_iter != ft_iter1; ++ft_iter)
// 		std::cout << ft_iter->first << " ";
// 	std::cout << std::endl;

// 	ft::map<int, std::string> ft_map3(ft_map1);
// 	ft_iter = ft_map3.begin();
// 	ft_iter1 = ft_map3.end();
// 	for(;ft_iter != ft_iter1; ++ft_iter)
// 		std::cout << ft_iter->first << " ";
// 	std::cout << std::endl;
	
// 	ft_iter = ft_map.end();
// 	--ft_iter;
// 	ft::map<int, std::string>::const_iterator ft_citer(ft_iter);
// 	const ft::map<int, std::string>::iterator ft_citer1(ft_map.end());
// 	// ft_citer++;
// 	// ft_citer1--;
// 	// (void)ft_citer;
// 	(void)ft_citer1;
// 	std::cout << ft_citer->first << std::endl;
	
// 	std::cout << ft_map.empty() << std::endl;

// 	ft_iter = ft_map3.begin();
// 	ft_iter1 = ft_map3.end();

// 	std::cout << ft_iter->first << std::endl;
// 	ft_map3.erase(ft_iter);
// 	ft_iter = ft_map3.begin();
// 	std::cout << ft_iter->first << std::endl;

// 	// std::cout << ft_map.max_size() << std::endl;
	
// 	std::cout << (ft_map3.erase(1)) << std::endl;
// 	std::cout << (ft_map3.erase(2)) << std::endl;
// 	std::cout << ft_map.size() << std::endl;

// 	ft_iter1 = ft_map.end();
// 	--ft_iter1;

// 	std::cout << ft_map.size() << std::endl;
// 	ft_map.erase(ft_map.begin(), ft_map.end());
// 	std::cout << ft_map.size() << std::endl;

// 	ft_iter = ft_map.begin();
// 	ft_iter1 = ft_map.end();
// 	// ft_iter = ft_map2.end();
// 	// for(;ft_iter != ft_iter1; ++ft_iter)
// 	// 	std::cout << ft_iter->first << " ";
// 	// std::cout << std::endl;

// 	ft::map<char,std::string> mymap;
// 	mymap['a']="an element";
// 	mymap['b']="another element";
// 	mymap['c']=mymap['b'];

// 	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
// 	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
// 	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
// 	std::cout << "mymap['d'] is " << mymap['d'] << '\n';

// 	std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	
// 	ft::map<char,int> foo12,bar12;

// 	foo12['x']=100;
// 	foo12['y']=200;

// 	bar12['a']=11;
// 	bar12['b']=22;
// 	bar12['c']=33;

// 	foo12.swap(bar12);

// 	std::cout << "foo12 contains:\n";
// 	for (ft::map<char,int>::iterator it=foo12.begin(); it!=foo12.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

// 	std::cout << "bar12 contains:\n";
// 	for (ft::map<char,int>::iterator it=bar12.begin(); it!=bar12.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';
	
// 	  ft::map<char,int> mymap5;

//   mymap5['x']=100;
//   mymap5['y']=200;
//   mymap5['z']=300;

//   std::cout << "mymap5 contains:\n";
//   for (ft::map<char,int>::iterator it=mymap5.begin(); it!=mymap5.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   mymap5.clear();
//   mymap5['a']=1101;
//   mymap5['b']=2202;

//   std::cout << "mymap5 contains:\n";
//   for (ft::map<char,int>::iterator it=mymap5.begin(); it!=mymap5.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

// 	std::cout << mymap5.size() << std::endl;


//  ft::map<char,int> mymap10;

// //   ft::map<char,int>::key_compare mycomp = mymap10.key_comp();

//   mymap10['a']=100;
//   mymap10['b']=200;
//   mymap10['c']=300;

//   std::cout << "mymap10 contains:\n";

// ft::map<char, int>::reverse_iterator rev_iter(mymap10.rbegin());
// (void)rev_iter;
//   char highest = (--mymap10.end())->first;     // key value of last element
// 	// (void)highest;
//   ft::map<char,int>::iterator it = mymap10.begin();
//   do {
//     std::cout << it->first << " => " << it->second << '\n';
//   } while ( mycomp((*it++).first, highest) );

// {
//   ft::map<char,int> mymap;

//   mymap['x']=1001;
//   mymap['y']=2002;
//   mymap['z']=3003;

//   std::cout << "mymap contains:\n";

// 	ft::map<char,int>::iterator iter(mymap.end());
// 	iter--;
//   ft::pair<char,int> highest = *iter;          // last element

//   ft::map<char,int>::iterator it = mymap.begin();
//   do {
//     std::cout << it->first << " => " << it->second << '\n';
//   } while ( mymap.value_comp()((*it++), highest) );

// }	

// 	ft::map<char,int> mymap99;
// 	ft::map<char,int>::iterator it99;

// 	mymap99['a']=50;
// 	mymap99['b']=100;
// 	mymap99['c']=150;
// 	mymap99['d']=200;

// 	it99 = mymap99.find('b');
// 	if (it99 != mymap99.end())
// 	mymap99.erase (it99);

// 	// print content:
// 	std::cout << "elements in mymap99:" << '\n';
// 	std::cout << "a => " << mymap99.find('a')->second << '\n';
// 	std::cout << "c => " << mymap99.find('c')->second << '\n';
// 	std::cout << "d => " << mymap99.find('d')->second << '\n';

// {
//   ft::map<char,int> mymap;
//   char c;

//   mymap ['a']=101;
//   mymap ['c']=202;
//   mymap ['f']=303;

//   for (c='a'; c<'h'; c++)
//   {
//     std::cout << c;
//     if (mymap.count(c)>0)
//       std::cout << " is an element of mymap.\n";
//     else 
//       std::cout << " is not an element of mymap.\n";
//   }
// }
// {
//   int psize;
//   ft::map<char,int> mymap;
//   ft::pair<const char,int>* p;

//   // allocate an array of 5 elements using mymap's allocator:
//   p=mymap.get_allocator().allocate(5);

//   // assign some values to array
//   psize = sizeof(ft::map<char,int>::value_type)*5;

//   std::cout << "The allocated array has a size of " << psize << " bytes.\n";

//   mymap.get_allocator().deallocate(p,5);

// }

// {
// 	ft::map<int, std::string> ft_map;
// 	for(int i = 3; i < 10; ++i)
// 		ft_map.insert(ft::make_pair<int, std::string>(i, "value"));
// 	// ft::map<int, std::string>::iterator ft_iter(ft_map.begin());
// 	// ft::map<int, std::string>::iterator ft_iter1(ft_map.end());
// 	// ft_iter = ft_map.lower_bound(1);
// 	// std::cout << ft_iter->first << std::endl;
// 	// ft_iter = ft_map.lower_bound(7);
// 	// std::cout << ft_iter->first << std::endl;
// 	// ft_iter = ft_map.lower_bound(12);
// 	// if (ft_iter == ft_map.end())
// 	// 	std::cout << "True \n";
// 	// ft_iter--;
// 	// (void)ft_iter1;
// 	// std::cout << ft_iter->first << std::endl;
// 	// const ft::map<int, std::string> const_map(ft_map);
// 	// std::cout << (ft_map.lower_bound(100))->first << std::endl;
// 	// std::cout << (const_map.lower_bound(7))->first << std::endl;
// }

// // {
// // 	ft::map<int, std::string> ft_map;
// // 	for(int i = 3; i < 10; ++i)
// // 		ft_map.insert(ft::make_pair<int, std::string>(i, "value"));
// // 	ft::map<int, std::string>::iterator ft_iter(ft_map.begin());
// // 	ft::map<int, std::string>::iterator ft_iter1(ft_map.end());
// // 	ft_iter = ft_map.upper_bound(1);
// // 	std::cout << ft_iter->first << std::endl;
// // 	ft_iter = ft_map.upper_bound(7);
// // 	std::cout << ft_iter->first << std::endl;
// // 	ft_iter = ft_map.upper_bound(9);
// // 	if (ft_iter == ft_map.end())
// // 		std::cout << "True \n";
// // 	ft_iter--;
// // 	(void)ft_iter1;
// // 	std::cout << ft_iter->first << std::endl;
// // 	const ft::map<int, std::string> const_map(ft_map);
// // 	std::cout << (const_map.lower_bound(1))->first << std::endl;
// // 	std::cout << (const_map.lower_bound(7))->first << std::endl;
// // }

// // {
// //   ft::map<char,int> mymap;
// //   ft::map<char,int>::iterator itlow,itup;

// //   mymap['a']=20;
// //   mymap['b']=40;
// //   mymap['c']=60;
// //   mymap['d']=80;
// //   mymap['e']=100;

// //   itlow=mymap.lower_bound ('b');  // itlow points to b
// //   itup=mymap.upper_bound ('d');   // itup points to e (not d!)

// //   mymap.erase(itlow,itup);        // erases [itlow,itup)

// //   // print content:
// //   for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
// //     std::cout << it->first << " => " << it->second << '\n';

// // }

// // {
// //   ft::map<char,int> mymap;

// //   mymap['a']=10;
// //   mymap['b']=20;
// //   mymap['c']=30;

// //   ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
// //   ret = mymap.equal_range('b');

// //   std::cout << "lower bound points to: ";
// //   std::cout << ret.first->first << " => " << ret.first->second << '\n';

// //   std::cout << "upper bound points to: ";
// //   std::cout << ret.second->first << " => " << ret.second->second << '\n';

// // }


// {
//    ft::map<char,int> foo,bar;
//   foo['a']=100;
//   foo['b']=200;
//   bar['a']=10;
//   bar['z']=1000;
  
//   // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

// }

// {
//   ft::map<char,int> foo,bar;

//   foo['x']=100;
//   foo['y']=200;

//   bar['a']=11;
//   bar['b']=22;
//   bar['c']=33;

//   swap(foo,bar);

//   std::cout << "foo contains:\n";
//   for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

//   std::cout << "bar contains:\n";
//   for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
//     std::cout << it->first << " => " << it->second << '\n';

// 	ft::map<char, int>::reverse_iterator rev_it(foo.rbegin());
// 	ft::map<char, int>::reverse_iterator rev_it1(foo.rend());

// 	const ft::map<char,int> foo1;

// 	ft::map<char, int>::const_reverse_iterator rev_itc(foo1.rbegin());
// 	// ft::map<char, int>::const_reverse_iterator rev_it1c(rev_itc);

// // if (rev_itc == foo.rbegin())
// // 	std::cout << "equal \n";
// // 	for(; rev_itc != foo.rend();rev_it1++)
// 		// std::cout << rev_itc->first << std::endl;
// 	(void)rev_itc;
// 	// (void)rev_it1c;
// 	for(; rev_it != rev_it1 ; ++rev_it)
// 		std::cout << rev_it->first << " ";
// 	std::cout << std::endl;

// }
// 		ft::map<int, std::string> m;
//             for (size_t i = 0; i < 1e6; ++i)
//             {
//                 m.insert(ft::make_pair(i, "value"));
//             }
// 	for (ft::map<int, std::string>::iterator it = m.begin(); it != m.end(); ++it)
//                 ;

// 	{ int myints[] = {12, 82, 37, 64, 15};
//             ft::map<int, int> m;
//             for (size_t i = 0; i < 5; ++i)
//                 m.insert(ft::make_pair(myints[i], i));
//             for (ft::map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
//                 std::cout << it->first;
// 	}

// 	{
// 		ft::map<int, std::string> ft_m1;
// 		ft::map<int, std::string> ft_m_range;
// 		for (size_t i = 0; i < 1e5; i++)
//                 ft_m1.insert(ft::make_pair(i, "string2"));
// 		ft_m_range.insert(ft_m1.begin(), ft_m1.end());
// 	}
// 	{
// 		int tmp;
// 	  	int myints[] = {12, 82, 37, 64, 15};
//             ft::map<int, int> m;
//             for (size_t i = 0; i < 5; ++i)
//                 m.insert(ft::make_pair(myints[i], i));
//             ft::map<int, int>::iterator it = m.begin(), eit = --m.end();
//             tmp = eit->first;
//             m.erase(eit);
//             for (; it != m.end(); ++it)
//             {
//                 std::cout << it->first << " ";
//             }
// 			std::cout << std::endl;
// 	}

// 	{
// 		ft::map<int, std::string> ft_m;
//         int arr[] = {20, 10, 100, 15, 60, 90, 65, 200, 150}; // size = 9
//         for (size_t i = 0; i < 9; ++i)
//         {
//             ft_m.insert(ft::make_pair(arr[i], "value"));
//         }
// 		std::cout << (ft_m.lower_bound(15)->first) << std::endl;
// 		std::cout << (ft_m.lower_bound(65)->first) << std::endl;
// 		std::cout << (ft_m.lower_bound(63)->first) << std::endl;
// 		std::cout << (ft_m.lower_bound(120)->first) << std::endl;
// 		std::cout << (ft_m.lower_bound(70)->first) << std::endl;
// 		std::cout << (ft_m.lower_bound(150)->first) << std::endl;

// 	}

// 	std::cout.precision(10);
// 	std::cout << NAMESPACE << std::fixed <<  float(clock() - start)/CLOCKS_PER_SEC  << std::endl;
	// system("leaks a.out");
}