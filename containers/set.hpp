#ifndef MAP_HPP

#define MAP_HPP


# include "../tools/map_iterator.hpp"
# include "../tools/reverse_iterator.hpp"
# include "../tools/algorithms.hpp"
# include "vector.hpp"
#include <vector>
namespace ft {
	template < class T,                                     // set::key_type | set::setped_type
           class Compare = std::less<T>,                     // set::key_compare
           class Alloc = std::allocator<T >    // set::allocator_type
           >
	class set {
		public:
			typedef	T																	key_type;
			typedef	T																	value_type;
			typedef	ft::pair<const key_type, value_type>								pair;
			typedef	Compare																key_compare;
			typedef	Compare																value_compare;
			typedef	Alloc																allocator_type;
			typedef	typename	allocator_type::reference								reference;
			typedef	typename	allocator_type::const_reference							const_reference;
			typedef	typename	allocator_type::pointer									pointer;
			typedef	typename	allocator_type::const_pointer							const_pointer;
			typedef	ft::RBTree<Key, Key, pair, Compare, Alloc>					rbtree;
			typedef	ft::Node<pair, Alloc>											nodee;
			typedef	ft::map_iterator<pair, rbtree, nodee>							iterator;
			typedef	ft::map_iterator<const pair, const rbtree, nodee>				const_iterator;
			typedef	ft::reverse_iterator<iterator>										reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef	typename	ft::iterator_traits<iterator>::difference_type			difference_type;
			typedef	size_t																size_type;
			
			set (const key_compare& comp = key_compare(),
        		const allocator_type& alloc = allocator_type()) : _comp(comp) , _alloc(alloc), _size(0) { /* empty */ }

			template <class InputIterator>
			set (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type()) : _comp(comp), _alloc(alloc), _size(0) { /* range */
					while (first != last) {
						this->insert(*first);
						first++;
					}
				}

			set	(const set& x) {
				operator=(x);
			}

			~set() {
				// _tree.~RBTree();
			}

			set& operator= (const set& other) {
				if (this != &other) {
					this->clear();
					// _alloc = other.get_allocator();
					_comp = other.key_comp();
					this->insert(other.begin(), other.end());

				}
				return *this;
			}
			/* iterators */

			iterator begin() {
				ft::Node<value_type, Alloc>* node = _tree.find_Min(_tree.getRoot());
				if (node == NULL) {
					return iterator(NULL, &_tree);
				}
				return iterator(node, &_tree);
			}

			const_iterator begin() const {
				ft::Node<value_type, Alloc>* node = _tree.find_Min(_tree.getRoot());
				if (node == NULL) {
					return const_iterator(NULL, &_tree);
				}
				return const_iterator(node, &_tree);
				// return const_iterator(_tree.find_Min(_tree.root) ? _tree.find_Min(_tree.root)->data : NULL , _tree);
			}

			iterator end() {
				return iterator(NULL , &_tree);
			}

			const_iterator end() const {
				return const_iterator(NULL, &_tree);
			}			

			reverse_iterator rbegin() {
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const {
				return const_reverse_iterator(end());
			}
			reverse_iterator rend() {
				return reverse_iterator(begin());
			}
			const_reverse_iterator rend() const {
				return const_reverse_iterator(begin());
			}
			/* end of iterators */

			/* Capacity */

			bool 	empty() {
				return _size == 0;
			}

			size_type size() const {
				return _size;
			}

			size_type max_size() const {
				return	_alloc.max_size();
			}

			/* end of Capacity */

			/* Element access */ 
			// 
			// value_type& operator[] (const key_type& k) {
			// 	value_type val = ft::make_pair(k, value_type());
			// 	// this->insert(val);
			// 	return (this->insert(val).first)->second;
			// }

			/* end of Element access */

			/* Modifiers */

			pair<iterator,bool> insert (const value_type& val) {
				ft::Node<value_type, Alloc> *node = _tree.find(val);
				bool	notFound = false;
				if (!node) {
					notFound = true;
					_tree.insert(val);
					_size++;
				}
				return ft::make_pair(iterator(_tree.find(val), &_tree), notFound);
			}

			iterator insert (iterator position, const value_type& val) {
				(void) position;
				return insert(val).first;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				while (first != last){
					insert(*first);
					first++;
				}
			}

			void erase (iterator position) {
				_tree.remove(*position);
				_size--;
			}

			size_type erase (const key_type& k) {
				if (_tree.remove(ft::make_pair(k, value_type()))) {
					_size--;
					return 1;
				}
				return 0;
			}
			
			void	erase (iterator first, iterator last) {
				ft::vector<key_type> keys;

				for (; first != last; ++first)
					keys.push_back(first->first);
				for (size_type i = 0;i < keys.size();++i)
					this->erase(keys[i]);
			}

			void	swap (set& x) {
				std::swap(_size, x._size);
				std::swap(_comp, x._comp);
				std::swap(_alloc, x._alloc);
				_tree.swap(x._tree);
			}

			void	clear () {
				_tree.clear();
				_size = 0;
			}
			/* end of Modifiers */

			/* Observers */

			key_compare key_comp() const {
				return _comp;
			}

			value_compare value_comp() const {
				return value_compare(_comp);
			}
			/* end  of Observers */

			/* Operations */

			iterator find (const key_type& k) {
				value_type	val = ft::make_pair(k, value_type());
				ft::Node<value_type, Alloc>	*node = _tree.find(val);
				return iterator(node ? node : NULL, &_tree);
			}

			const_iterator find (const key_type& k) const {
				value_type	val = ft::make_pair(k, value_type());
				ft::Node<T, Alloc>	*node = _tree.find(val);
				return const_iterator(node ? node->data : NULL, &_tree);
			}

			size_type	count (const key_type& k) {
				if (_tree.find(ft::make_pair(k, value_type())) != NULL)
					return 1;
				return 0;
			}
			
			iterator lower_bound (const key_type& k) {
				ft::Node<value_type, Alloc>* node = _tree.bound(k);
				return (iterator(node, &_tree));
			}

			const_iterator lower_bound (const key_type& k) const {
				ft::Node<value_type, Alloc> *node = _tree.bound(k);
				return (const_iterator(node, &_tree));
			}

			iterator upper_bound (const key_type& k) {
				ft::Node<value_type, Alloc> * node = _tree.bound( k);
				if (node->data->first == k)
					node = _tree.inOrderSuccessor((node));
				return (iterator(node, &_tree));
			}

			const_iterator upper_bound (const key_type& k) const {
				ft::Node<value_type, Alloc> * node = _tree.bound( k);
				if (node->data->first == k)
					node = _tree.inOrderSuccessor(node);
				return (const_iterator(node, &_tree));
			}

			pair<iterator, iterator>	equal_range (const key_type& k) {
				return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

			/* end of Operations */

			/* Allocator */

			allocator_type get_allocator() const {
				return _alloc;
			}

			rbtree				_tree;
			/*end of Alloctor*/
			private:
				key_compare			_comp;
				allocator_type		_alloc;
				size_type			_size;
	
	};

	template <class Key, class T, class Compare, class Alloc>
	void	swap (set<Key, Compare, Alloc>& x, set<Key, Compare, Alloc>& y)
	{
		x.swap(y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator == (const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
	{
		return ((lhs.size() == rhs.size()) && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator != (const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator > (const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator < (const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator >= (const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
	{
			return (!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Alloc>
	bool	operator <= (const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs)
	{
		return (!(lhs > rhs));
	}

};

#endif