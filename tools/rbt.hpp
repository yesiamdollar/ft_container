#ifndef MRED_BLACK_TREE_HPP

# define MRED_BLACK_TREE_HPP

// ACHRAf102030!!

# include <iostream>
# include <memory>
# include "pair.hpp"
# define	MRED	1
# define	BLACK	0
namespace ft {
	template< class T, class Alloc>
	struct Node{
		typedef	T	value_type;
		Node() : data(NULL), left(NULL), right(NULL), color(BLACK) {};
		Node(value_type k) {
			data = _alloc.allocate(1);
			_alloc.construct(data, k);
			color = MRED;
		}



		Node	&operator=(Node const& src) {
			if (this != &src) {
				if (data) {
					_alloc.destroy(data);
					_alloc.deallocate(data, 1);
				}
				left = src.left;
				right = src.right;
				parent = src.parent;
				data = _alloc.allocate(1);
				_alloc.construct(data, *src.data);
			}
			return *this;
		}

		~Node() {
			if (data) {
				_alloc.destroy(data);
				_alloc.deallocate(data, 1);
			}
		}
		value_type*		data;
		Node*			parent;
		Node*			left;
		Node*			right;
		unsigned int	color;
		Alloc			_alloc;
	};

	template< class key, class val, typename T,
				class Compare, 
				class Alloc>
	class	RBTree{
		public:
			typedef	T																	value_type;
			typedef	Alloc																allocator_type;
			typename Alloc::template rebind<Node<value_type, Alloc> >::other			_node_alloc; 
			typedef	Compare																compare_operator;
			typedef ft::Node<value_type, Alloc>*										Nodeptr;
			Nodeptr				MyNULL;
		private:
			Nodeptr				root;
			allocator_type		_alloc;
			compare_operator	_comp;
			// node_allocator		_node_alloc;
			Nodeptr	RBTinsert(Nodeptr src, Nodeptr& ptr) {
				if (src == MyNULL) {
					return ptr;
				}
				// compare_operator	cmp;
				// if (ptr->data < src->data) {
				if (_comp(ptr->data->first, src->data->first)) {
					src->left = RBTinsert(src->left, ptr);
					src->left->parent = src;
				} else {
					src->right = RBTinsert(src->right, ptr);
					src->right->parent = src;
				}
				return src;
			}

			void rotateLeft(Nodeptr x) {
				Nodeptr y = x->right;
				x->right = y->left;
				if (y->left != MyNULL) {
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr) {
					this->root = y;
				} else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			void	rotateRight(Nodeptr x) {			
				Nodeptr y = x->left;
				x->left = y->right;
				if (y->right != MyNULL) {
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == nullptr) {
					this->root = y;
				} else if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			void	insetFixRBT(Nodeptr	p) {
				Nodeptr	ptr = p, parent, grandparent, uncle = MyNULL;

				while ((ptr != root) && (ptr->color == MRED) && (ptr->parent->color == MRED)) {
					parent = ptr->parent;
					grandparent = parent->parent;
					if (parent == grandparent->left) {
						uncle = grandparent->right;
						if (uncle != MyNULL && uncle->color == MRED) {
							/*
								Uncle is MRED, so we do colorflip (parent and uncle with grandparent)
								pushing darkness from the grandparent ... 
							*/
							grandparent->color = MRED;
							parent->color = BLACK;
							uncle->color = BLACK;
							ptr = grandparent;
						} else {
							if (ptr == parent->right) {
								rotateLeft(parent);
								ptr = parent;
								parent = ptr->parent;
								// left rotate
								// printTree();
							}
							// right rotate
							rotateRight(grandparent);
							std::swap(parent->color, grandparent->color);
							ptr = parent;
							;
						}
					} else {
						uncle = grandparent->left;
						if (uncle != MyNULL && uncle->color == MRED) {
							grandparent->color = MRED;
							parent->color = BLACK;
							uncle->color = BLACK;
							ptr = grandparent;
						} else {
							if (ptr == parent->left) {
								rotateRight(parent);
								ptr = parent;
								parent = ptr->parent;
								// right rotate
								// printTree();
							}
							// left rotate
							rotateLeft(grandparent);
							std::swap(parent->color, grandparent->color);
							ptr = parent;
						}
					}
				}
				root->color = BLACK;

			}

			void printTreeHelper(Nodeptr src, int space)
			{
				int i;
				if(src != MyNULL)
				{
					space = space + 10;
					printTreeHelper(src->right, space);
					std::cout << '\n';
					for ( i = 10; i < space; i++)
					{
						std::cout << ' ';
					}
					std::string colors[2] = { "B", "R"};
					std::cout << src->data->first << "(" << colors[src->color] << ")" << " [" << src->data->second << "]";
					std::cout << '\n';
					printTreeHelper(src->left, space);
				}
			}

			void rbTransplant(Nodeptr u, Nodeptr v) {
				if (u->parent == NULL) {
					root = v;
				} else if (u == u->parent->left) {
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			

			void swapColors(Nodeptr x, Nodeptr y) {
				unsigned int	color;
				color = x->color;
				x->color = y->color;
				y->color = color;
			}

			void swapValues(Nodeptr x, Nodeptr y) {
				value_type*	tmp;
				tmp = x->data;
				x->data = y->data;
				y->data = tmp;
			}

			void	deleteFix(Nodeptr x){
				Nodeptr s;
				while (x != root && x->color == BLACK) {
				if (x == x->parent->left) {
					s = x->parent->right;
					if (s->color == MRED) {
					s->color = BLACK;
					x->parent->color = MRED;
					rotateLeft(x->parent);
					s = x->parent->right;
					}

					if (s->left->color == BLACK && s->right->color == BLACK) {
					s->color = MRED;
					x = x->parent;
					} else {
					if (s->right->color == BLACK) {
						s->left->color = BLACK;
						s->color = MRED;
						rotateRight(s);
						s = x->parent->right;
					}

					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->right->color = BLACK;
					rotateLeft(x->parent);
					x = root;
					}
				} else {
					s = x->parent->left;
					if (s->color == MRED) {
					s->color = BLACK;
					x->parent->color = MRED;
					rotateRight(x->parent);
					s = x->parent->left;
					}

					if (s->right->color == BLACK && s->right->color == BLACK) {
					s->color = MRED;
					x = x->parent;
					} else {
					if (s->left->color == BLACK) {
						s->right->color = BLACK;
						s->color = MRED;
						rotateLeft(s);
						s = x->parent->left;
					}

					s->color = x->parent->color;
					x->parent->color = BLACK;
					s->left->color = BLACK;
					rotateRight(x->parent);
					x = root;
					}
				}
				}
				x->color = BLACK;
			}

			void	deleteHelper(Nodeptr z) {
				Nodeptr x,y;
				unsigned int org_color = z->color;
				// if (z == root){
				// 	std::cout << "Deleting root \n";
				// }
				y = z;
				int y_original_color = y->color;
				if (z->left == MyNULL) {
					x = z->right;
					rbTransplant(z, z->right);
				} else if (z->right == MyNULL) {
					x = z->left;
					rbTransplant(z, z->left);
				} else {
					y = minimum(z->right);
					y_original_color = y->color;
					x = y->right;
				if (y->parent == z) {
					x->parent = y;
				} else {
					rbTransplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}

				rbTransplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
				}
				// delete z;
				if (y_original_color == BLACK) {
					deleteFix(x);
				}
			}

			

			Nodeptr searcher(Nodeptr src, value_type data) const {
				if (src == MyNULL || src->data->first == data.first)
					return src;
				// if (src->data->first < data.first)
				if (_comp(src->data->first, data.first))
						return searcher(src->right, data);
				return searcher(src->left, data);
			}
			
			void	cleared(Nodeptr src) {
				if (src == MyNULL) {
					return ;
				}
				clear(src->left);
				clear(src->right);
				_alloc.deallocate(src->data, 1);
				_node_alloc.deallocate(src, 1);
			}
		public:
			RBTree() {
				MyNULL = _node_alloc.allocate(1);
				MyNULL->color = BLACK;
				MyNULL->right = NULL;
				MyNULL->left = NULL;
				value_type	tmp = ft::make_pair<const key, val>(key(), val());
				MyNULL->data = &tmp;
				root = MyNULL;
			}

			void insert(value_type data) {
				// std::cout << data.first << std::endl;
				Nodeptr		ptr = _node_alloc.allocate(1);
				_node_alloc.construct(ptr, data);
				ptr->left = ptr->right = MyNULL;
				ptr->parent = NULL;
				root = RBTinsert(root, ptr);
				insetFixRBT(ptr);
			}

			Nodeptr getRoot() const {
				if (root == MyNULL)
					return NULL;
				return root;
			}


			Nodeptr	search(value_type data) const {
				return searcher(root, data);
			}

			Nodeptr	find(value_type data) const {
				Nodeptr tmp = searcher(root, data);
				if (tmp == MyNULL) {
					return NULL;
				}
				return tmp;
			}

			size_t	remove(value_type data) {
				Nodeptr	del = search(data);

				if (del == MyNULL) {
					return 0;
				}
				deleteHelper(del);
				return 1;
			}

			void printTree() {
				printTreeHelper(root, 0);
			}

			Nodeptr minimum(Nodeptr src) const {
				Nodeptr	tmp = src;
				while (tmp->left != MyNULL) {
					tmp = tmp->left;
				}
				return tmp;
			}

			Nodeptr maximum(Nodeptr src) const {
				Nodeptr	tmp = src;
				while (tmp->right != MyNULL) {
					tmp = tmp->right;
				}
				return tmp;
			}

			Nodeptr	find_Min(Nodeptr src) const{
				if (src == NULL)
					return NULL;
				Nodeptr tmp = minimum(src);
				if (tmp == MyNULL)
					return NULL;
				return tmp;
			}

			Nodeptr	find_Max(Nodeptr src) const {
				if (src == NULL)
					return NULL;
				Nodeptr tmp = maximum(src);
				if (tmp == MyNULL)
					return NULL;
				return tmp;
			}

			Nodeptr	inOrderPredecessor(Nodeptr src) const {
				Nodeptr tmp = (src);

				if (tmp == NULL)
					return NULL;

				if (tmp->left != MyNULL)
					return maximum(tmp->left);
				
				Nodeptr parent = tmp->parent;
				while (parent != NULL && tmp == parent->left) {
					tmp = parent;
					parent = tmp->parent;
				}
				return parent;
			}

			Nodeptr inOrderSuccessor(Nodeptr src) const { // done

				Nodeptr tmp = src;

				if (tmp == NULL)
					return NULL;

				if (tmp->right != MyNULL)
					return minimum(tmp->right);
				
				Nodeptr	parent = tmp->parent;
				while (parent != NULL && tmp == parent->right){
					tmp = parent;
					parent = tmp->parent;
				}
				return parent;
			}

			void	swap (RBTree &src ) {
				std::swap(root, src.root);
				std::swap(_alloc, src._alloc);
				std::swap(_comp, src._comp);
				std::swap(_node_alloc, src._node_alloc);
				std::swap(MyNULL, src.MyNULL);
			}

			void	clear () {
				cleared(root);
				root = MyNULL;
			}

			Nodeptr	bound(const key& k) const {
				// std::cout << "before :: [" << MyNULL->data->first << "]" << std::endl;
				Nodeptr src = root;
				Nodeptr tmp = src;
				// std::cout << "after :: [" << MyNULL->data->first << "]" << std::endl;
				while (src != MyNULL && src != MyNULL) {
					if (_comp(k, src->data->first)){
						tmp = src;
						src = src->left;
					} else if (_comp(src->data->first, k)) {
						src = src->right;
					} else {
						return src;
					}
				}
				return tmp;
			}



			// Nodeptr				root;
			/* Nodeptr				root;
			allocator_type		_alloc;
			compare_operator	_comp; */
	};
};
#endif
