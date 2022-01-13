#include<iostream>
#include<cstdio>

using namespace std;

class Node {
public:
	char data;
	Node* next;

	Node(char val) {
		data = val;
		next = NULL;
	}
};

void createHead(Node*& first, char val) {
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
		if (temp->next != NULL) {
			cout << temp->data << " -> ";
		}
		else {
			cout << temp->data;
		}
		temp = temp->next;
	}
	cout << endl;
}

void sSort(Node* first) {
	Node* temp = first;
	while (temp != NULL) {
		Node* min = temp;
		Node* r = temp->next;

		while (r) {
			if (min->data > r->data)
				min = r;
			r = r->next;
		}
		char x = temp->data;
		temp->data = min->data;
		min->data = x;
		temp = temp->next;
	}
}

void Duplicate(Node* first) {
	Node* current = first;

	while (current->next != NULL) {
		if (current->data == current->next->data) {
			current->next = current->next->next;
		}
		else {
			current = current->next;
		}
	}
	return;
}

int main() {

	Node* n = NULL;

	char num;
	cin >> num;
	if (num) {
		do {
			createHead(n, num);
		} while (cin >> num);
		createHead(n, num);

		sSort(n);
		Duplicate(n);
		Display(n);

	}
	return 0;
}