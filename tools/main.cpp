#include "rbt.hpp"
#include <iostream>

int main(){
	ft::RBTree<int, int> t;
	for (int c = 0; c <= 9; c++){
		ft::pair<int, int> a(c, c);
		t.insert(a);
	}
	t.printTree();
	ft::pair<int, int> b(3,4);
	t.remove(b);
	t.printTree();
}
