#ifndef stack_hpp
#define stack_hpp

#include "vector.hpp"
#include <deque>
namespace ft{

	template <class T, class Container = deque<T> >
	class stack{
		public:
			typedef	typename	Container::value_type		value_type;
			typedef	typename	Container::size_type		size_type;
			typedef	typename	Container::reference		reference;
			typedef	typename	Container::const_reference	const_reference;

		private:
	};

}

#endif