#include "rbt.hpp"
#include <iostream>

int main(){
	ft::RBTree<int> t;
	for (int c = 1; c <= 9; c++){
		t.insert(c);
	}
	t.printTree();

}
