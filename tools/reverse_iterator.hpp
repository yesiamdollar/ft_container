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

			reverse_iterator() : _current(0){}
			reverse_iterator(iterator_type	x) : _current(x) {}
			template< class U > 
			reverse_iterator(const reverse_iterator<U>& rev_it) : _current(rev_it.base()) { }
			template< class U >
			reverse_iterator	&operator=(const reverse_iterator<U>& other) { _current = other.base(); return *this; }

			iterator_type base() const { return _current; }

			reference 			operator*() const {iterator_type tmp = _current; return *--tmp;};
			pointer				operator->() const { return std::addressof(operator*()); };
			reference			operator[] (difference_type n) const { return base()[-n-1] ;}

			reverse_iterator& operator++() {--_current; return *this; }
			reverse_iterator  operator++(int) { reverse_iterator tmp(_current); --_current; return tmp; };
			reverse_iterator& operator--() { ++_current; return *this; }
			reverse_iterator operator--(int) { reverse_iterator tmp(_current); ++_current; return tmp; }
			
			reverse_iterator	operator+(difference_type n) const { return reverse_iterator(base() - n); }
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(base() + n); }
			reverse_iterator	operator+=(difference_type n) { _current -= n; return *this; }
			reverse_iterator	operator-=(difference_type n) { _current += n; return *this; }

			operator    reverse_iterator<const iterator_type>() const
			{
				return reverse_iterator<const iterator_type>(_current);
			}

			friend	reverse_iterator	operator+(difference_type n, reverse_iterator const& iter) { return reverse_iterator<Iter>(iter.base() - n); }
			friend	difference_type		operator-(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (rhs.base() - lhs.base()); }
			// friend	bool				operator==(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() == rhs.base()); }
			// friend	bool				operator!=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() != rhs.base()); }
			// friend	bool				operator<(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() > rhs.base()); }
			// friend	bool				operator<=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() >= rhs.base()); }
			// friend	bool				operator>(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() < rhs.base()); }
			// friend	bool				operator>=(reverse_iterator const& lhs, reverse_iterator const& rhs) { return (lhs.base() <= rhs.base()); }
		private:
			iterator_type	_current;
	};

		template< class Iterator1, class Iterator2 >
	bool operator==( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs ){
						return (lhs.base() == rhs.base());
	}
		
	template< class Iterator1, class Iterator2 >
	bool operator!=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs ){
						return (lhs.base() != rhs.base());

					}
		
	template< class Iterator1, class Iterator2 >
	bool operator<( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs ){
						return (lhs.base() < rhs.base());

					}
		
	template< class Iterator1, class Iterator2 >
	bool operator<=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs ){
						return (lhs.base() <= rhs.base());

					}
		
	template< class Iterator1, class Iterator2 >
	bool operator>( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs ){
						return (lhs.base() > rhs.base());

					}
		
	template< class Iterator1, class Iterator2 >
	bool operator>=( const ft::reverse_iterator<Iterator1>& lhs,
					const ft::reverse_iterator<Iterator2>& rhs ){
						return (lhs.base() >= rhs.base());

					}
}

#endif