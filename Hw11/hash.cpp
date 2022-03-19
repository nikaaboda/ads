#include <iostream>

using namespace std;

class Node {
public:
	int key;
	int value;
	Node(int key, int value){
		this->key = key;
		this->value = value;
	};
}

class HashTable {
private:
	Node **arr;
	int maxSize;
	int currentSize;
public:
	HashTable() {
		maxSize = 150;
		currentSize = 0;
		arr = new Node*[maxSize];
	};
	hashCode(int key) {
		return key % 37;
	};
	void insertNode(int key, int value) {
		int i = 0;
		while(i < maxSize) {
			int j = (hashCode(key) + i) % maxSize;
			if(arr[j] == NULL) {
				arr[j] = key;
				return j;
			} else {
				i++;
			}
		}
		cout << "Hashtable overflow" << endl;
	};
	int get(int key) {
		int i = 0;
		while()
	};
	bool isEmpty();
}


int main() {
	return 0;
}