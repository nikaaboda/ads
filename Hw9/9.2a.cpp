#include <iostream>

using namespace std;

class List {
private:
	struct Node {
		int data;
		Node* next;	
	};
	Node* head;
public:
	List() {
		this->head = NULL;
	}

	void push(int element) {
		Node* newel = new Node;
		newel->data = element;
		newel->next = this->head;
		this->head = newel;
	}

	void reverse() {
		Node* ahead = NULL;
		Node* prev = NULL;
		Node* cursor = head;
		while(cursor != NULL) {
            ahead = cursor->next;
            cursor->next = prev;
            prev = cursor;
            cursor = ahead;
		}
		prev = head;
	}

	void print()
    {
        Node *temp;
        for (temp = this->head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << " ";
        }
        cout<<endl;
    }
};

int main() {
	List intlist;
	intlist.push(1);
	intlist.push(2);
	intlist.push(3);
	intlist.push(4);	
	intlist.print();
	intlist.reverse();
	intlist.print();
	return 0;
}