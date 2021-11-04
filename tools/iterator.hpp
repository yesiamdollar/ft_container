#ifndef iterator_hpp

#define iterator_hpp
#include "iterator_traits.hpp"
#include <cstddef>
namespace ft{

	template<
		class Category,
		class T,
		class Distance = std::ptrdiff_t,
		class Pointer = T*,
		class Reference = T&
	> struct iterator{
		typedef T         value_type;
    	typedef Distance  difference_type;
    	typedef Pointer   pointer;
    	typedef Reference reference;
    	typedef Category  iterator_category;
		iterator(pointer ptr): current(ptr){};
		iterator(const iterator & src) : current(NULL){ operator=(src); };

		iterator& operator=(const iterator& rhs) {current = rhs.base(); return *this;}
		iterator& operator++() {++current ; return (*this); }
		iterator& operator++(value_type) {iterator tmp(current); ++current ; return (tmp);}
		iterator& operator--() {--current ; return (*this);}
		iterator& operator--(value_type) {iterator tmp(current); --current ; return (tmp);}

		bool operator==(const iterator& rhs) const { return (current == rhs.base()); }
		bool operator!=(const iterator& rhs) const { return (current != rhs.base()); }

		iterator& operator+(difference_type max) { iterator cpy(current + max); return (cpy); }
		friend iterator& operator+(difference_type max, iterator const& it) { iterator cpy(current + max); return (cpy); }
		
		iterator& operator-(difference_type max) { iterator cpy(current - max); return (cpy); }
		difference_type	operator-(const iterator& rhs) { return (current - rhs.base()); }

		bool	operator<(const iterator& rhs) const { return (current < rhs.base()); }
		bool	operator<=(const iterator& rhs) const { return (current <= rhs.base()); }
		bool	operator>(const iterator& rhs) const { return (current > rhs.base()); }
		bool	operator>=(const iterator& rhs) const { return (current >= rhs.base()); }

		iterator& operator+=(difference_type max) { current + max; return (*this); }
		iterator& operator-=(difference_type max) { current - max; return (*this); }

		reference	operator*() { return (*current); }
		pointer		operator->(){ return (current); }
		
		operator    iterator<const value_type>() const
        {
            return iterator<const value_type>(current);
        }

		pointer base() { return (current); }

		reference operator[](size_t ind) { return *(current + ind); }
		protected:
			pointer current;
	};
	
}
#endif
// it + n -> iterator;
// n + it -> iterator;
// it - it2 -> diff_type