#include <iostream>

using namespace std;

template <class T>
class Stack1 {
private:
	struct Stack1Node
	{
		T data;
		Stack1Node* next;
	};
	Stack1Node* top;
	int size;
	int current_size;
public:
	Stack1() {
		top = NULL;
		size = 0;
	};

	Stack1(int new_size) {
		this->size = new_size;
		this->current_size = 0;
		this->top = NULL;
	}

	bool push(T element) {
		if(size > 0 && size == current_size) {
			cout << "Can't push the element - OVERFLOW" << endl;
			return false;
		} 

		Stack1Node* newnode = new Stack1Node;
		newnode->next = top;
		newnode->data = element;
		this->top = newnode;
		if(current_size) {
			current_size++;
		} else {
			current_size = 1;
		}

		return true;
	}

	T pop() {
		if(current_size == 0) {
			cout << "Can't pop the element - UNDERFLOW" << endl;
		}

		Stack1Node* temp = this->top;
		this->top = temp->next;
		T data = temp->data;
		delete temp;
		this->current_size--;
		return data;
	}

	bool isEmpty() {
		return current_size == 0;	
	}

};

