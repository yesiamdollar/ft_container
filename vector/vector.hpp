#ifndef VECTOR_HPP

# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "inc/iterator.hpp"

namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		private:
			typedef				T								value_type;
			typedef				Alloc							allocator_type;
			typedef	typename	allocator_type::reference		reference;
			typedef	typename	allocator_type::const_reference	const_reference;
			typedef	typename	allocator_type::pointer			pointer;
			typedef	typename	allocator_type::const_pointer	const_pointer;
			typedef	typename	ft::iterator<vector<T>>			iterator;
			value_type											*arr;
			typedef				size_t							size_type;
			size_type											size;
			size_type											capacity;

			value_type*		allocateNfill(size_type n, const value_type& val,
					const allocator_type& alloc){
				value_type*	arr2 = alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					arr2 = val;
				return arr2;
			};
		public:
			vector(const allocator_type& alloc = allocator_type()){
				size = 0;
				capacity = 0;
				arr = NULL;
			}
			vector(size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()){
				size = n;
				capacity = n;
				arr = allocateNfill(n, val, alloc);
			}

			iterator begin(){
				return iterator(arr);
			}

			iterator end(){
				return iterator(arr + size);
			}
	};
}


#endif