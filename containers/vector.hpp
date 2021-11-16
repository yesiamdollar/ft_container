#ifndef VECTOR_HPP

# define VECTOR_HPP

#include <iostream>
#include <memory>
#include "../tools/iterator.hpp"
#include "../tools/iterator_traits.hpp"
#include "../tools/reverse_iterator.hpp"
#include "../tools/type_traits.hpp"
#include "../tools/algorithms.hpp"
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

			/*	Default */	
			Vector(const allocator_type& alloc = allocator_type() ): _size(0), _capacity(0), _alloc(alloc), _arr(0) {}
			
			/* Fill */
			Vector(size_type count, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type()){
				_size = count;
				_capacity = count;
				_alloc = alloc;
				_arr = _alloc.allocate(count);
				for (size_type z = 0; z < _size; z++)
					_alloc.construct(_arr + z, val);
			}

			/* Range */
			template <class InputIt>
			Vector( InputIt first, InputIt last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type = InputIt()) : _alloc(alloc){
					difference_type n = std::distance(first, last);
					_arr = _alloc.allocate(n);
					_capacity = n;
					_size = 0;
					for (InputIt it = first; it != last; it++){
						_alloc.construct(_arr + _size, *it );
						_size++;
					}
			}

			/* Copy */
			Vector( const Vector& other ){
				*this = other;
			}

			Vector&	operator=(const Vector& other){
				if (this != &other){
					this->_capacity = other.capacity();
					this->_size = other.size();
					this->_alloc = other.get_allocator();
					this->_arr = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(_arr + i, other[i]);
				}
				return *this;
			}

			~Vector(){
			for (size_type i = 0; i < _size; i++)
            	_alloc.destroy(_arr + i);
			if (_capacity)
				_alloc.deallocate(_arr, _capacity);
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
				if (pos >= _size)
					throw (std::out_of_range("Vector::at: _pos is >= _size"));
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
				return const_reverse_iterator(end());
			}

			reverse_iterator	rend(){
				return reverse_iterator(begin());
			}
			const_reverse_iterator	rend() const{
				return const_reverse_iterator(begin());
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
				if (new_cap <= this->_capacity)
					return ;
                value_type *new_arr = _alloc.allocate(new_cap);
				_capacity = new_cap;
                for (size_type i = 0; i < _size ; i++)
					_alloc.construct(new_arr + i, _arr[i]);
                std::swap(new_arr, _arr);
                for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&new_arr[i]);
                _alloc.deallocate(new_arr, _capacity);
			}
			void        resize (size_type n, value_type val = value_type()) {
                if (n < this->_size)
					for (size_type i = n; i < _size; i++) 
						_alloc.destroy(_arr + i);
                else if (this->_size < n)
					insert(end(), n - this->_size, val);
				_size = n;
            }
			size_type	capacity() const {
				return _capacity;
			}
			/* end Capacity */

			/* Modifiers */
			iterator	insert(iterator pos, const value_type& value){ /* single element */
				difference_type	dis = std::distance(begin(), pos);
				if (!_capacity)
					reserve(1);
				else if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				for (difference_type i = _size - 1; i > dis; i--)
					_alloc.construct(_arr + i + 1, _arr[i]);
				_alloc.construct(_arr + dis, value);
				_size++;
				return iterator(_arr + dis);
			}
			
			void	insert(iterator pos, size_type n, const value_type& value){ /* fill */
				if (!n)
					return ;
				if (n == 1){
					insert(pos, value);
					return ;
				}
				difference_type dis = std::distance(begin(), pos);
				if (!_capacity)
					reserve(1);
				else if (_size + n > _capacity){
					if (n > _size)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
				}
				for (difference_type i = _size - 1; i >= dis; i--)
					_alloc.construct(_arr + i + n, _arr[i]);
				// for (size_type i = 0; i < n; i++)
				// 	_alloc.construct( _arr + dis + i, value);
			}

			template<class InputIt>
			void	insert(iterator pos, InputIt first, InputIt last,
				typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type = InputIt()){ /* range */
				difference_type dis = std::distance(begin(), pos);
				size_type n = std::distance(first, last);
				if (!_capacity)
					reserve(1);
				else if (_size + n > _capacity){
					if (n > _size)
						reserve(_size + n);
					else
						reserve(_capacity * 2);
				}
				// for (difference_type i = _size - 1; i >= dis; i--)
				// 	_alloc.construct(_arr + i + n, _arr[i]);
				// for (size_type i = 0; i < n; i++, _size++)
				// 	_alloc.construct(_arr + dis + i, *first);
			}

			
			void	assign( size_type n, const value_type& val  ){/* fill */
				if (_capacity < n)
					reserve(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_arr + i);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_arr + i, val);
				_size = n;
			}

			template<class InputIt>
			void	assign( InputIt first, InputIt last,
				typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt>::type = InputIt()){ /* range */
				size_type n = std::distance(first, last);
				if (_capacity < n)
					reserve(n);
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_arr + i);
				for (size_type i = 0; i < n; i++)
					_alloc.construct(_arr + i, *first++);
				_size = n;
			}

			void	push_back(const value_type& val){
				if (!_capacity)
					reserve(1);
				else if (_size >= _capacity)
					reserve(_capacity * 2);
				_alloc.construct(_arr + _size, val);
				_size++;
			}

			void	pop_back(){
				if (!_size)
					return ;
				_alloc.destroy(_arr + _size);
				--_size;
			}

			iterator	erase(iterator pos){ /* single */
				size_type dis = std::distance(begin(), pos);
				_alloc.destroy(_arr + dis);
				for (size_type i = dis; i < _size - 1; i++)
					_arr[i] = _arr[i + 1];
				_size--;
				return (iterator(_arr + dis));
			};

			iterator	erase(iterator first, iterator last){ /* range */
				difference_type dis = std::distance(begin(), first);
				size_type n = std::distance(first, last);
				for (size_type i = dis; i < n; i++)
					_alloc.destroy(_arr + i);
				_size -= n;
				for (size_type i = dis; i < _size; i++)
					_arr[i] = _arr[n++];
				return (iterator(_arr + dis));
			}

			void	swap(Vector& other){
				std::swap(this->_size, other._size);
				std::swap(this->_capacity, other._capacity);
				std::swap(this->_arr, other._arr);
				std::swap(this->_alloc, other._alloc);
			}

			void	clear(){
				for (size_type i = 0; i < _size ; i++)
					_alloc.destroy(_arr + i);
				_size = 0;
			}
			/* end Modifiers */
	};

	template<class T, class Alloc>
	bool	operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin())
				&& (lhs.size() == rhs.size()));
	}
	template<class T, class Alloc>
	bool	operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (!(operator==(lhs, rhs)));
	}

	template<class T, class Alloc>
	bool	operator< (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template<class T, class Alloc>
	bool	operator<=(const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return(!(rhs < lhs));
	}

	template<class T, class Alloc>
	bool	operator> (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (ft::operator<(rhs, lhs));
	}
	template<class T, class Alloc>
	bool	operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs){
		return (!ft::operator<(lhs, rhs));
	}
}


#endif