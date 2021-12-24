#ifndef MAP_ITERATOR

# define MAP_ITERATOR

#include "type_traits.hpp"
#include "rbt.hpp"
namespace ft{

	template<class T, class node = ft::RBTree<T> >
	class map_iterator{
		public:
			typedef	node*								nodePtr;
			typedef	T									value_type;
			typedef	ptrdiff_t							difference_type;
			typedef	T*									pointer;
			typedef	T&									reference;
			typedef	std::bidirectional_iterator_tag		iterator_category;
		
		private:
			nodePtr	_current;

		public:
			map_iterator() : _ptr(NULL) {}
			map_iterator(map_iterator const& it) : _current(it._current) {}

			map_iterator(nodePtr p) : _current(p) {}

			map_iterator& operator=(const map_iterator& it) {
				_current = it._current;
				return *this;
			}

			bool	operator==(const map_iterator& it) const { return  _current == it._current; }
			bool	operator!=(const map_iterator& it) const { return  _current != it._current; }

			value_type&	operator*() const { return *_current; }
			pointer		operator->() const { return _current; }
			
			nodePtr		base() const {return _current; }
			
			map_iterator&	operator++() {
				// if (_current->)
				;
			}

	};

};

#endif