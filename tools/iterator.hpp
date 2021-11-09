#ifndef iterator_hpp

#define iterator_hpp
#include "iterator_traits.hpp"
#include <cstddef>
namespace ft{

	template <
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T& 
		> struct iterator {
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;
			typedef Category  iterator_category;
			iterator(pointer ptr): _current(ptr){};
			iterator(const iterator & src) : _current(NULL){ operator=(src); };

			iterator& operator=(const iterator& rhs) {_current = rhs.base(); return *this;}
			iterator& operator++() {++_current ; return (*this); }
			iterator operator++(int) {iterator tmp(_current); ++_current ; return (tmp);}
			iterator& operator--() {--_current ; return (*this);}
			iterator operator--(int) {iterator tmp(_current); --_current ; return (tmp);}

			bool operator==(const iterator& rhs) { return (_current == rhs.base()); }
			bool operator!=(const iterator& rhs) { return (_current != rhs.base()); }

			iterator operator+(difference_type max) { iterator cpy(_current + max); return (cpy); }
			friend iterator& operator+(difference_type max, iterator const& it) { iterator cpy(it->base() + max); return (cpy); }
			
			iterator operator-(difference_type max) { iterator cpy(_current - max); return (cpy); }
			difference_type	operator-(const iterator& rhs) { return (_current - rhs.base()); }

			bool	operator<(const iterator& rhs) { return (this->base() < rhs.base()); }
			bool	operator<=(const iterator& rhs) { return (this->base() <= rhs.base()); }
			bool	operator>(const iterator& rhs) { return (this->base() > rhs.base()); }
			bool	operator>=(const iterator& rhs) { return (this->base() >= rhs.base()); }

			iterator& operator+=(difference_type max) { _current += max; return (*this); }
			iterator& operator-=(difference_type max) { _current -= max; return (*this); }

			reference	operator*() { return (*(this->base())); }
			pointer		operator->(){ return (this->base()); }
			
			operator    iterator<Category, const value_type>() const
			{
				return iterator<Category,const value_type>(_current);
			}

			pointer base() const { return (_current); }

			reference operator[](size_t ind) { return *(_current + ind); }
		private:
			pointer _current;
	};
	
}
#endif
// it + n -> iterator;
// n + it -> iterator;
// it - it2 -> diff_type