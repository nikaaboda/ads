#include <iostream>
#include "bst.h"

using namespace std;

int main() {
	bst tree;
	tree.insert(2);
	tree.insert(4);
	tree.insert(1);
	tree.insert(12);
	tree.insert(23);
	tree.insert(24);
	List list;
	tree.convert(list);
	list.print();
	return 0;
}