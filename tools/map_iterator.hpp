#ifndef MAP_ITERATOR

# define MAP_ITERATOR

#include "type_traits.hpp"
#include "iterator_traits.hpp"
#include "rbt.hpp"

namespace ft{

	template<class T, class Tr, class N>
	class map_iterator{
		public:
			typedef typename	ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename	ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename	ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename	ft::iterator<std::bidirectional_iterator_tag, T>::reference				reference;
			typedef typename	ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef				Tr*																		TreePtr;
			typedef				N*																		Nodeptr;
			typedef				size_t																	size_type;
			Nodeptr		_current;
		private:
			TreePtr		_tree;
		public:
			map_iterator() : _current(NULL), _tree(NULL) {}
			map_iterator(const Nodeptr ptr, const TreePtr tree = NULL) : _current(ptr), _tree(tree) {}
			map_iterator(map_iterator const& it) : _current(it._current), _tree(it._tree) {}

			map_iterator& operator=(const map_iterator& it) {
				_current = it._current;
				_tree = it._tree;
				return *this;
			}

			operator map_iterator<const T, const Tr,  N>() const {
				return (map_iterator<const T, const Tr,  N>(_current, _tree));
			}

			// bool	operator==(const map_iterator& it) const { return  _current == it._current; }
			// bool	operator!=(const map_iterator& it) const { return  _current != it._current; }

			value_type&	operator*() const { return *(_current->data); }
			pointer		operator->() const { return _current->data; }
			
			Nodeptr		base() const { return _current; }
			
			map_iterator&	operator++() {
				if (_current == NULL) {
					_current = _tree->find_Min(_tree->getRoot());
				} else {
					_current = _tree->inOrderSuccessor(_current);
				}
				
				return *this;
			}

			map_iterator	operator++(int) {
				map_iterator cpy = *this;
				++(*this);
				return cpy;
			}

			map_iterator	operator--() {
				if (_current == NULL) {
					_current = _tree->find_Max(_tree->getRoot());
				} else {
					_current = _tree->inOrderPredecessor(_current);
				}
				return *this;
			}

			map_iterator operator--(int)
			{
				map_iterator cpy = *this;
				--(*this);
				return cpy;
			}

			friend	bool	operator==(const map_iterator& lhs, const map_iterator& rhs){
				return lhs._current == rhs._current;
			}

			friend	bool	operator!=(const map_iterator& lhs, const map_iterator& rhs){
				return !(lhs._current == rhs._current);
			}
	};
};

#endif