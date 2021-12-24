#ifndef RED_BLACK_TREE_HPP

# define RED_BLACK_TREE_HPP

// ACHRAf102030!!

# include <iostream>
# include <memory>
# include "pair.hpp"
# define	RED	1
# define	BLACK	0
namespace ft {
	template<class T, class Alloc>
	struct Node{
		typedef	T	value_type;
		Node() : data(NULL), left(NULL), right(NULL), color(BLACK) {};
		Node(value_type k) : color(RED) {
			data = _alloc.allocate(1);
			_alloc.construct(data, k);
		};



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
		value_type*				data;
		Node*			parent;
		Node*			left;
		Node*			right;
		unsigned int	color;
		Alloc			_alloc;
	};

	template< class key,
				class val,
				class Compare = std::less<key>,
				class Alloc = std::allocator< ft::pair< key, val> >
				>
	class	RBTree{
		public:
			typedef	ft::pair<key, val>													value_type;
			typedef	Alloc																allocator_type;
			typename Alloc::template rebind<Node<value_type, Alloc> >::other			node_allocator; 
			typedef	Compare																compare_operator;
			typedef ft::Node<value_type, Alloc>*										Nodeptr;
		private:
			Nodeptr				MyNULL;
			Nodeptr				root;
			allocator_type		_alloc;
			compare_operator	_comp;
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

			void	rotateLeft(Nodeptr x) {
			
				Nodeptr y = x->right;
				x->right = y->left;
				/*
				* if (y) has a left subtree, assign (x) as
				* the parent of left subtree of (y)
				*/
				if (y->left != MyNULL) {
					y->left->parent = x;
				}
				/*
				* if the (x) parent is null make (y) the root
				* else if (x) is the left child of the parent,
				* make (y) as the left child of the parent
				* else assign (y) as the right child of parent 
				*/
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->root = y;
				} else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				
				/*
				* then make (y) as th parent of (x)
				*/
				y->left = x;
				x->parent = y;
			}

			void	rotateRight(Nodeptr x) {			
				Nodeptr y = x->left;
				x->left = y->right;
				/*
				* if (y) has a right subtree, assign (x) as
				* the parent of right subtree of (y)
				*/
				if (y->right != MyNULL) {
					y->right->parent = x;
				}
				
				/*
				* if the (x) parent is null make (y) the root
				* else if (x) is the right child of the parent,
				* make (y) as the right child of the parent
				* else assign (y) as the left child of parent 
				*/
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->root = y;
				} else if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}

				/*
				* then make (y) as th parent of (x)
				*/
				y->right = x;
				x->parent = y;
			}

			void	insetFixRBT(Nodeptr	p) {
				Nodeptr	ptr = p, parent, grandparent, uncle = NULL;

				while ((ptr != root) && (ptr->color == RED) && (ptr->parent->color == RED)) {
					parent = ptr->parent;
					grandparent = parent->parent;
					if (parent == grandparent->left) {
						uncle = grandparent->right;
						if (uncle != MyNULL && uncle->color == RED) {
							/*
								Uncle is RED, so we do colorflip (parent and uncle with grandparent)
								pushing darkness from the grandparent ... 
							*/
							grandparent->color = RED;
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
						if (uncle != MyNULL && uncle->color == RED) {
							grandparent->color = RED;
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
					std::cout << src->data->first << "(" << colors[src->color] << ")";
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
				Nodeptr sibling;
				// if (x == NULL)
				// {
				// 	std::cout << "NULL ya habibi\n";
				// 	exit(0);
				// }
				while (x != root && x->color == BLACK) {
					if (x == x->parent->left) {
						sibling =  x->parent->right;
						if (sibling->color == RED){
							sibling->color = BLACK;
							x->parent->color = BLACK;
							rotateLeft(x->parent);
							sibling = x->parent->right;
						}

						if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
							sibling->color = RED;
							x = x->parent;
						} else {
							if (sibling->right->color == BLACK) {
								sibling->left->color = BLACK;
								sibling->color = RED;
								rotateRight(sibling);
								sibling = x->parent->right;
							}
							sibling->color = x->parent->color;
							x->parent->color = BLACK;
							sibling->right->color = 0;
							rotateLeft(x->parent);
							x = root;
						}
					} else {
						sibling =  x->parent->left;
						if (sibling->color == RED) {
							sibling->color = BLACK;
							x->parent->color = RED;
							rotateRight(x->parent);
							sibling = x->parent->left;
						}

						if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
							sibling->color = RED;
							x = x->parent;
						} else {
							if (sibling->left->color == BLACK) {
								sibling->right->color = BLACK;
								sibling->color = RED;
								rotateLeft(sibling);
								sibling = x->parent->left;
							}
							sibling->color = x->parent->color;
							x->parent->color = BLACK;
							sibling->left->color = BLACK;
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
				if (z == root){
					std::cout << "Deleting root \n";
				}
				y = z;
				if (z->left == MyNULL) {
					x = z->right;
					rbTransplant(z, z->right);
				} else if (z->right == MyNULL) {
					x = z->left;
					rbTransplant(z, z->left);
				} else {
					y = maximum(z->left);
					org_color = y->color;
					x = y->left;
					if (y->parent == z) {
						x->parent = y;
					} else {
						rbTransplant(y, y->left);
						y->left = z->left;
						y->left->parent = y;
					}
					rbTransplant(z, y);
					y->right = z->right;
					y->right->parent = y;
					y->color = z->color;
				}
				node_allocator.destroy(z);
				node_allocator.deallocate(z, 1);
				if (org_color == BLACK){
					deleteFix(x);
				}
			}

			

			Nodeptr searcher(Nodeptr src, value_type data) {
				if (src == MyNULL || src->data->first == data.first)
					return src;
				if (src->data->first < data.first)
						return searcher(src->right, data);
				return searcher(src->left, data);
			}
			
		public:
			RBTree() {
				MyNULL = node_allocator.allocate(1);
				MyNULL->color = BLACK;
				MyNULL->right = NULL;
				MyNULL->left = NULL;
				MyNULL->data = NULL;
				root = MyNULL;
			}

			void insert(value_type data) {
				Nodeptr		ptr = node_allocator.allocate(1);
				node_allocator.construct(ptr, data);
				ptr->left = ptr->right = MyNULL;
				ptr->parent = NULL;
				root = RBTinsert(root, ptr);
				insetFixRBT(ptr);
			}

			Nodeptr& getRoot() {
				return root;
			}


			Nodeptr	search(value_type data) {
				return searcher(root, data);
			}

			void	remove(value_type data) {
				Nodeptr	del = search(data);

				if (del == MyNULL) {
					std::cout << "Node Not Found !!\n";
					return ;
				}
				deleteHelper(del);
			}

			void printTree() {
				printTreeHelper(root, 0);
			}

			Nodeptr minimum(Nodeptr src) {
				while (src->left != MyNULL) {
					src = src->left;
				}
				return src;
			}

			Nodeptr maximum(Nodeptr src) {
				while (src->right != MyNULL) {
					src = src->right;
				}
				return src;
			}

			Nodeptr	inOrderPredecessor(Nodeptr src) {
				Nodeptr tmp = src;

				if (tmp->left != MyNULL)
					return minimum(tmp->left);
				
				Nodeptr parent = tmp->parent;
				while (parent != NULL && tmp == parent->right) {
					tmp = parent;
					parent = tmp->parent;
				}
				return tmp;
			}

			Nodeptr inOrderSuccessor(Nodeptr src) { // done
				Nodeptr tmp = src;
				if (tmp->right != MyNULL)
					return minimum(tmp->right);
				Nodeptr	parent = tmp->parent;
				while (parent != NULL && tmp == parent->right){
					tmp = parent;
					parent = tmp->parent;
				}
				return tmp;
			}
	};
};
#endif
