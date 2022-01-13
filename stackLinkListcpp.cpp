#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
};

class Stack {
private:
	Node* top;
public:
	Stack() {
		top = NULL;
	}

	void Push(int x);
	int pop();
	void Display();
};

void Stack::Push(int x) {
	Node* t = new Node;
	if (t == NULL) {
		cout << "Stack is full";
	}
	else {
		t->data = x;
		t->next = top;
		top = t;
	}
}
int Stack::pop() {
	int x = -1;
	if (top == NULL) {
		cout << "Stack is empty";
	}
	else {
		x = top->data;
		Node* t = top;
		top = top->next;
		delete t;
	}
	return x;
}

void Stack::Display() {
	Node* p = top;
	while (p != NULL) {
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}

int main()
{
 
	Stack stk;

	stk.Push(10);
	stk.Push(20);
	stk.Push(30);

	stk.Display();

	cout << stk.pop();

	return 0;
}