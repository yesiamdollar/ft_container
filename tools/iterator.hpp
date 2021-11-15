#ifndef iterator_hpp

#define iterator_hpp
#include "iterator_traits.hpp"
#include <cstddef>
namespace ft{


	template <class T>
	class VectorIterator : public ft::iterator<std::random_access_iterator_tag, T>{
		public:
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

			VectorIterator(): _current(0){};
			VectorIterator(pointer ptr): _current(ptr){};
			VectorIterator(const VectorIterator & src) { operator=(src); };

			VectorIterator& operator=(const VectorIterator& rhs) {_current = rhs.base(); return *this;}
			VectorIterator& operator++() {++_current ; return (*this); }
			VectorIterator operator++(int) {VectorIterator tmp(_current); ++_current ; return (tmp);}
			VectorIterator& operator--() {--_current ; return (*this);}
			VectorIterator operator--(int) {VectorIterator tmp(_current); --_current ; return (tmp);}

			bool operator==(const VectorIterator& rhs) { return (_current == rhs.base()); }
			bool operator!=(const VectorIterator& rhs) { return (_current != rhs.base()); }

			VectorIterator operator+(difference_type max) { VectorIterator cpy(_current + max); return (cpy); }
			friend VectorIterator operator+(difference_type max, VectorIterator const& it) { VectorIterator cpy(it.base() + max); return (cpy); }
			
			VectorIterator operator-(difference_type max) { VectorIterator cpy(_current - max); return (cpy); }
			difference_type	operator-(const VectorIterator& rhs) { return (_current - rhs.base()); }

			bool	operator<(const VectorIterator& rhs) { return (this->base() < rhs.base()); }
			bool	operator<=(const VectorIterator& rhs) { return (this->base() <= rhs.base()); }
			bool	operator>(const VectorIterator& rhs) { return (this->base() > rhs.base()); }
			bool	operator>=(const VectorIterator& rhs) { return (this->base() >= rhs.base()); }

			VectorIterator& operator+=(difference_type max) { _current += max; return (*this); }
			VectorIterator& operator-=(difference_type max) { _current -= max; return (*this); }

			reference	operator*() { return (*(this->base())); }
			pointer		operator->(){ return (this->base()); }
			
			operator    VectorIterator<const value_type>() const
			{
				return VectorIterator<const value_type>(_current);
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