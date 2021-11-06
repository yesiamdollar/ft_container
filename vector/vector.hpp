#ifndef VECTOR_HPP

# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "../tools/iterator.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/type_traits.hpp"
#include <algorithm>


namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class vector{
		public:
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
		private: 
			value_type											*_arr;
			size_type											_size;
			size_type											_capacity;
			allocator_type										_alloc;

		public:
			/* Member functions */
			vector(const allocator_type& alloc = allocator_type()){
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_arr = NULL;
			}
			vector(size_type count, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()){
				_size = count;
				_capacity = count;
				_alloc = alloc;
				_arr = _alloc.allocate(count);
				for (size_type z = 0; z < _size; z++)
					_arr[z] = val;
			}
			template <InputIt>
			vector( InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if< !ft::is_integral<InputIt>, InputIt >::value = InputIt()){
					difference_type len = std::distance(first, last);
					_arr = alloc.allocate(len);
					_alloc = alloc;
					_capacity = len;
					_size = 0;
					for (InputIt it = first, int z = 0; it != last; it++, z++){
						_alloc.construct(_arr + z, *it );
						_size++;
					}
			}
			vector( const vector& other ){
				operator=(other);
			}
			vector&	operator=(const vector& other){
				if (this != &other){
					this._capacity = other.capacity();
					this._size = other.size();
					this._alloc = other.get_allocator();
					_arr = _alloc.allocate(_capacity);
					assign(other.begin(), other.end());
					other._alloc.d
				}
				return *this;
			}
			void	assign( size_type count, const value_type& value ){
				_size = 0;
				for(int z = 0; z < count ; z++, _size++)
					arr[z] = value;
			}
			template <InputIt>
			void	assign( InputIt first, InputIt last ){
				// difference_type len = std::distance(first, last)
				_size = 0;
				for(InputIt it = first; it != last; it++, _size++ )
					_alloc.construct(_arr + _size, *it);

			}

			allocator_type get_allocator() const{
				return _alloc;
			};

			/* end Member functions */

			/* Iterators */
			iterator begin(){
				return iterator(arr);
			}
			iterator end(){
				return iterator(arr + size);
			}	
			/* end Iterators */
			
			
			/* Capacity */
			bool	empty() const {
				return (begin() == end());
			}
			size_type	size() const {
				return _size;
			}
			size_type	max_size() const{
				return _alloc.max_size();
			}
			void	reserve( size_type new_cap ){
				(void)new_cap;
			}
			size_type	capacity() const {
				return _capaity;
			}
			/* end Capacity */
	};
}


#endif