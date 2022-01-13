#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue {
private:
    int size;
    int front;
    int rear;
    Node** Q;  // [Node*]*: Pointer to [Pointer to Node]
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node* x);
    Node* dequeue();
};

Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node * [size];
}

Queue::~Queue() {
    delete[] Q;
}

bool Queue::isEmpty() {
    if (front == rear) {
        return true;
    }
    return false;
}

bool Queue::isFull() {
    if (rear == size - 1) {
        return true;
    }
    return false;
}

void Queue::enqueue(Node* x) {
    if (isFull()) {
        cout << "Queue Overflow" << endl;
    }
    else {
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue() {
    Node* x = nullptr;
    if (isEmpty()) {
        cout << "Queue Underflow" << endl;
    }
    else {
        front++;
        x = Q[front];
    }
    return x;
}

//binary tree

class Tree {
public:
    Node* root;
    Tree() {
        root = NULL;
    }

    void CreateTree();
    void Preorder(Node* p);
    void Postorder(Node* p);
    void Inorder(Node* p);
    void Levelorder(Node* p);
    int Height(Node* root);
};

void Tree::CreateTree()
{
    Node* p, * t;
    int x;
    Queue q(100);

    printf("Eneter root value ");
    scanf("%d", &x);
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        printf("eneter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(struct Node* p)
{
    if (p)
    {
        printf("%d ", p->data);
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}


void Tree::Inorder(struct Node* p)
{
    if (p)
    {
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Tree::Postorder(struct Node* p)
{
    if (p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Tree::Levelorder(struct Node* root)
{
    Queue q(100);

    printf("%d ", root->data);
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            printf("%d ", root->lchild->data);
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            printf("%d ", root->rchild->data);
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(struct Node* root)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = Height(root->lchild);
    y = Height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;

}


int main() {

    Tree t;

    t.CreateTree();
    cout << "Preorder ";
    t.Preorder(t.root);
    cout << endl;
    cout << "Inorder ";
    t.Inorder(t.root);
    cout << endl;

    return 0;
}