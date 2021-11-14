#ifndef reverse_iterator_hpp

# define reverse_iterator_hpp

# include "iterator_traits.hpp"
# include <memory>
namespace ft{
	template <class Iter>
	class reverse_iterator{
		public :
			typedef				Iter					iterator_type;
			typedef	typename	Iter::value_type		value_type;
			typedef	typename	Iter::difference_type	difference_type;
			typedef	typename	Iter::pointer			pointer;
			typedef	typename	Iter::reference			reference;
			typedef	typename	Iter::iterator_category	iterator_category; 

			reverse_iterator() : _current(nullptr){}
			reverse_iterator(iterator_type	x) : _current(x) {}
			template< class U > 
			reverse_iterator(const reverse_iterator<U>& rev_it) : _current(rev_it._current) { }
			template< class U >
			reverse_iterator	&operator=(const reverse_iterator<U>& other) { _current = other._current; return *this; }

			iterator_type base() const { return _current; }

			reference 			operator*() const {iterator_type tmp = _current; return *--tmp;};
			pointer				operator->() const { return std::addressof(operator*()); };
			reference			operator[] (difference_type max) const { return base()[-max-1] ;}

			reverse_iterator& operator++() {--_current; return *this; }
			reverse_iterator  operator++(int) { reverse_iterator tmp(_current); --_current; return tmp; };
			reverse_iterator& operator--() { ++_current; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp(_current); ++_current; return tmp; }
			
			reverse_iterator	operator+(difference_type max) const { reverse_iterator tmp(_current - max); return tmp; }
			reverse_iterator	operator-(difference_type max) const { reverse_iterator tmp(_current + max); return tmp; }
			reverse_iterator	operator+=(difference_type max) { _current - max; return *this; }
			reverse_iterator	operator-=(difference_type max) { _current + max; return *this; }

			operator    reverse_iterator<const iterator_type>() const
			{
				return reverse_iterator<const iterator_type>(_current);
			}

			friend	reverse_iterator	operator+(difference_type max, reverse_iterator const& iter) { reverse_iterator cpy(iter.base() + max); return (cpy); }
			friend	difference_type		operator-(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (rhs.base() - lhs.base()); }
			friend	bool				operator==(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() == rhs.base()); }
			friend	bool				operator!=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() != rhs.base()); }
			friend	bool				operator<(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() > rhs.base()); }
			friend	bool				operator<=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() >= rhs.base()); }
			friend	bool				operator>(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() < rhs.base()); }
			friend	bool				operator>=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() <= rhs.base()); }
		private:
			iterator_type	_current;
	};
}

#endif