#ifndef VECTOR_HPP

# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "../tools/iterator.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/reverse_iterator.hpp"


namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		private:
			typedef				T											value_type;
			typedef				Alloc										allocator_type;
			typedef	typename	allocator_type::reference					reference;
			typedef	typename	allocator_type::const_reference				const_reference;
			typedef	typename	allocator_type::pointer						pointer;
			typedef	typename	allocator_type::const_pointer				const_pointer;
			typedef				ft::iterator< value_type >					iterator;
			typedef				ft::iterator< const value_type>				const_iterator;
			typedef				ft::reverse_iterator< value_type >			reverse_iterator;
			typedef				ft::reverse_iterator< const value_type >	const_reverse_iterator;
			typedef				std::ptrdiff_t								difference_type;
			typedef				size_t										size_type;

			value_type											*arr;
			size_type											size;
			size_type											capacity;

			value_type*		allocateNfill(size_type n, const value_type& val,
					const allocator_type& alloc){
				value_type*	tmp = alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					tmp = val;
				return tmp;
			};
		public:
			vector(const allocator_type& alloc = allocator_type()){
				size = 0;
				capacity = 0;
				arr = NULL;
			}
			vector(size_type count, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()){
				size = count;
				capacity = count;
				arr = allocateNfill(count, val, alloc);
			}

			vector(  ){

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