#include <iostream> 

using namespace std;

template <class T>
class Stack {
private:
	struct StackNode
	{
		T data;
		StackNode* next;
	};
	StackNode* top;
	int size;
	int current_size;
public:
	Stack() {
		top = NULL;
		size = 0;
	};

	// Stack(const Stack& src) {
	// 	top = src->top;
	// 	size = src->size;
	// 	if(size != -1) {
	// 		current_size = src->current_size;
	// 	}
	// };

	Stack(int new_size) {
		this->size = new_size;
		this->current_size = 0;
		this->top = NULL;
	}

	bool push(T element) {
		if(size > 0 && size == current_size) {
			cout << "Can't push the element - OVERFLOW" << endl;
			return false;
		} 

		StackNode* newnode = new StackNode;
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

		StackNode* temp = this->top;
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

int main() {
    Stack<int> intstack(4);
    intstack.push(4);
    intstack.push(3);
    intstack.push(2);
    intstack.push(1);
    intstack.push(0);
    
    while(!intstack.isEmpty()) {
    	cout << intstack.pop() << endl;
    }

    return 0;
}