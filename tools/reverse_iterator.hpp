#ifndef reverse_iterator_hpp

# define reverse_iterator_hpp

# include "iterator_traits.hpp"
# include <memory>
namespace ft{
	template <class Iter>
	class reverse_iterator{
		public :
			typedef				Iter					iterator_type;
			typedef	typename	Iter::iterator_category	iterator_category; 
			typedef	typename	Iter::value_type		value_type;
			typedef	typename	Iter::difference_type	difference_type;
			typedef	typename	Iter::pointer			pointer;
			typedef	typename	Iter::reference			reference;

			reverse_iterator() : current(nullptr){}
			reverse_iterator(iterator_type	x) : current(x) {}
			template< class U > 
			reverse_iterator(const reverse_iterator<U>& rev_it) { operator=(rev_it); }
			template< class U > 
			reverse_iterator	&operator=(const reverse_iterator<U>& other) { current = other.base(); return *this; }

			iterator_type base() const { return current; }

			reference 			operator*() const {iterator_type tmp = current; return *--tmp;};
			pointer				operator->() const { return std::addressof(operator*()); };
			reference			operator[] (difference_type max) const { return base()[-max-1] ;}

			reverse_iterator& operator++() {--current; return *this; }
			reverse_iterator  operator++(int) { reverse_iterator tmp(current); --current; return tmp; };
			reverse_iterator& operator--() { ++current; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp(current); ++current; return tmp; }
			
			reverse_iterator	operator+(difference_type max) const { reverse_iterator tmp(current - max); return tmp; }
			reverse_iterator	operator-(difference_type max) const { reverse_iterator tmp(current + max); return tmp; }
			reverse_iterator	operator+=(difference_type max) { current - max; return *this; }
			reverse_iterator	operator-=(difference_type max) { current + max; return *this; }

			// operator    reverse_iterator<const value_type>() const
			// {
			// 	return reverse_iterator<const value_type>(current);
			// }

			friend	reverse_iterator	operator+(difference_type max, reverse_iterator const& iter) { reverse_iterator cpy(iter.base() + max); return (cpy); }
			friend	difference_type		operator-(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (rhs.base() - lhs.base()); }
			friend	bool				operator==(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() == rhs.base()); }
			friend	bool				operator!=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() != rhs.base()); }
			friend	bool				operator<(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() > rhs.base()); }
			friend	bool				operator<=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() >= rhs.base()); }
			friend	bool				operator>(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() < rhs.base()); }
			friend	bool				operator>=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() <= rhs.base()); }
		private:
			iterator_type	current;
	};
}

#endif