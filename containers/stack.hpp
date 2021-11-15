#ifndef stack_hpp
#define stack_hpp

#include "vector.hpp"

namespace ft{

	template <class T, class Container = ft::Vector<T> >
	class Stack{
		public:
			typedef				Container					container_type;
			typedef				T							value_type;
			typedef	typename	Container::size_type		size_type;
			typedef	typename	Container::reference		reference;
			typedef	typename	Container::const_reference	const_reference;

			Stack ( const container_type& ctnr = container_type()) : _c(ctnr) {}
			Stack ( const Stack&	other ) { operator=(other); }

			Stack& operator= ( const Stack& other ) {
				if (this != &other){
					_c = other._c; 
				}
				return *this;
			}

			bool	empty() const {
				return (_c.empty());
			}

			size_type	size() const {
				return (_c.size());
			}

			value_type& top() {
				return (_c.back());
			}
			const value_type& top() const {
				return (_c.back());
			}

			void	push(const value_type& val){
				_c.push_back(val);
			}

			void	pop(){
				_c.pop_back();
			}

			template <class U, class Ct>
			friend	bool	operator== (const Stack< U, Ct>& lhs, const Stack< U, Ct>& rhs){
				return (lhs._c == rhs._c); 
			}

			template <class U, class Ct>
			friend	bool	operator!= (const Stack< U, Ct>& lhs, const Stack< U, Ct>& rhs){
				return (lhs._c != rhs._c); 
			}

			template <class U, class Ct>
			friend	bool	operator< (const Stack< U, Ct>& lhs, const Stack< U, Ct>& rhs){
				return (lhs._c < rhs._c); 
			}

			template <class U, class Ct>
			friend	bool	operator<= (const Stack< U, Ct>& lhs, const Stack< U, Ct>& rhs){
				return (lhs._c <= rhs._c); 
			}

			template <class U, class Ct>
			friend	bool	operator> (const Stack< U, Ct>& lhs, const Stack< U, Ct>& rhs){
				return (lhs._c > rhs._c); 
			}

			template <class U, class Ct>
			friend	bool	operator>= (const Stack< U, Ct>& lhs, const Stack< U, Ct>& rhs){
				return (lhs._c >= rhs._c); 
			}
			protected:
				container_type	_c;
	};

}

#endif