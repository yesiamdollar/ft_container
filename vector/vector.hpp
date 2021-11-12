#ifndef VECTOR_HPP

# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "../tools/iterator.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/type_traits.hpp"
#include <algorithm>
#include <iterator>


namespace ft{
	template <typename T, class Alloc = std::allocator<T> >
	class Vector{
		public:
			typedef				T										value_type;
			typedef				Alloc									allocator_type;
			typedef	typename	allocator_type::reference				reference;
			typedef	typename	allocator_type::const_reference			const_reference;
			typedef	typename	allocator_type::pointer					pointer;
			typedef	typename	allocator_type::const_pointer			const_pointer;
			typedef				ft::VectorIterator< value_type >		iterator;
			typedef				ft::VectorIterator< const value_type>	const_iterator;
			typedef				ft::reverse_iterator< iterator >		reverse_iterator;
			typedef				ft::reverse_iterator< const_iterator >	const_reverse_iterator;
			typedef				std::ptrdiff_t							difference_type;
			typedef				size_t									size_type;
		private: 
			value_type											*_arr;
			size_type											_size;
			size_type											_capacity;
			allocator_type										_alloc;

		public:
			/* Member functions */
			Vector() : _size(0), _capacity(0), _alloc(allocator_type()), _arr(NULL){};
			Vector(const allocator_type& alloc ){
				_size = 0;
				_capacity = 0;
				_alloc = alloc;
				_arr = NULL;
			}
			Vector(size_type count, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()){
				_size = count;
				_capacity = count;
				_alloc = alloc;
				_arr = _alloc.allocate(count);
				for (size_type z = 0; z < _size; z++)
					_alloc.construct(_arr + z, val);
			}
			template <class InputIt>
			Vector( InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type = InputIt()){
					difference_type len = std::distance(first, last);
					_alloc = alloc;
					_arr = _alloc.allocate(len);
					_capacity = len;
					_size = 0;
					for (InputIt it = first; it != last; it++){
						_alloc.construct(_arr + _size, *it );
						_size++;
					}
			}
			Vector( const Vector& other ){
				operator=(other);
			}
			~Vector(){
				// for (size_type z = 0; z < _size; z++){
				// 	_alloc.destroy(_arr + z);
				// }
				// _alloc.deallocate(_arr, _capacity);
			}
			Vector&	operator=(const Vector& other){
				if (this != &other){
					this->_capacity = other.capacity();
					this->_size = other.size();
					this->_alloc = other.get_allocator();
					this->_arr = _alloc.allocate(_capacity);
					assign(other.begin(), other.end());
					// other._alloc.d
				}
				return *this;
			}
			void	assign( size_type count, const value_type& value ){
				_size = 0;
				for(; _size < count ; _size++)
					_alloc.construct(_arr + _size, value);
			}
			template <class InputIt>
			void	assign( InputIt first, InputIt last ){
				_size = 0;
				for(InputIt it = first; it != last; it++, _size++ )
					_alloc.construct(_arr + _size, *it);

			}

			allocator_type get_allocator() const{
				return _alloc;
			};

			/* end Member functions */

			/*  Element access */

			reference operator[]( size_type pos ){
				return (_arr[pos]);
			}
			const_reference operator[](size_type pos) const {
				return (_arr[pos]);
			}

			reference at( size_type pos ){
				return (_arr[pos]);
			}
			const_reference at( size_type pos ) const {
				return (_arr[pos]);
			}

			reference front(){
				return (_arr[0]);
			}
			const_reference front() const {
				return (_arr[0]);
			}

			reference back(){
				return (_arr[size() - 1]);
			}
			const_reference back() const {
				return (_arr[size() - 1]);
			}

			T* data() {
				if (_size > 0)
					return _arr;
				return nullptr;
			}

			const T* data() const {
				if (_size > 0)
					return _arr;
				return nullptr;
			}
			/* end  Element access */


			/* Iterators */
			iterator begin(){
				return iterator(_arr);
			}
			const_iterator begin() const{
				return const_iterator(_arr);
			}

			iterator end(){
				return iterator(_arr + size());
			}
			const_iterator end() const{
				return iterator(_arr + size());
			}

			reverse_iterator	rbegin(){
				return reverse_iterator(end());
			}
			const_reverse_iterator	rbegin() const{
				return reverse_iterator(end());
			}

			reverse_iterator	rend(){
				return reverse_iterator(begin());
			}
			const_reverse_iterator	rend() const{
				return reverse_iterator(iterator(_arr));
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
				return _capacity;
			}
			/* end Capacity */

			/* Modifiers */
			void	resize(size_type n, value_type val = value_type()){
				if (n < _size){
					for (int i = n; i < _size; i++){
						_alloc.destroy(&_arr[i]);
					}
					_size = n;
				}
				else if (n > _size && n <= _capacity){
					;
				}
				else {
					;
				}
			}

			iterator	insert(iterator pos, const reference value){ /* single element */
				if (_size == _capacity){
					value_type	tmp  = _arr;
					size_type	len = _capacity * 2;
					_arr = _alloc.allocate(len);
					iterator it = tmp.begin();
					for (; it != pos ; it++){
						_alloc.construct(_arr + i, *it);
					}
					_alloc.construct(_arr + i, *pos);
					
					for (size_type i = _size - 1; i <= 0; i--){
						_alloc.destroy(tmp + i);
					}
					_size++;
					_capacity *= 2;
					_alloc.deallocate(tmp);
				}
				return pos;
			}
			
			/* end Modifiers */
	};
}


#endif