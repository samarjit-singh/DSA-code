#include<iostream>
#include<cstdio>

using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}
};

void createAtHead(Node*& first, int val) {
	Node* n = new Node(val);
	n->next = first;
	first = n;
}

void createAtEnd(Node*& first, int val) {

	Node* n = new Node(val);

	if (first == NULL) {
		first = n;
		return;
	}

	Node* temp = first;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
}


void Display(Node* first) {
	if (first == NULL) {
		return;
	}
	Node* temp = first;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

void sortEvod(Node*& first) {
	Node* temp = first;
	Node* odd = NULL;
	Node* even = NULL;

	while (temp->next != NULL) {
		int val = temp->data;
		if (val % 2 != 0) {
			createAtEnd(odd, val);
		}
		else {
			createAtEnd(even, val);
		}
		temp = temp->next;
	}
	Display(even);
	Display(odd);

}

int main() {
	Node* n = NULL;

	int num;
	cin >> num;

	do {
		createAtEnd(n, num);
	} while (cin >> num);

	createAtEnd(n, num);

	sortEvod(n);
}