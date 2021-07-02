#include <iostream>
using namespace std;
class Node {
public:
	int data;	Node* left;	Node* right;
	Node(int data = 0, Node* left = nullptr, Node* right = nullptr) :data{ data }, left{ left }, right{ right }{	cout << "constructor Node " << this << endl;	}
	~Node() { cout << "distructor Node " << this << endl; }
};
class BinaryTree {
	Node* head;	int size;
public:
	BinaryTree() :head{ nullptr }, size{ 0 } { cout << "constructor BinaryTree " << this << endl; }
	~BinaryTree() { cout << "distructor BineryTree " << this << endl; }
	int getSize() { return size; }
	void setHead(Node* ptr) { head = ptr; }
	Node* getHead() { return head; }
	Node* createNode(int data) {	//создаем первый обьект
		Node* newNode = new Node(data);
		return newNode;
	}
	Node*addNode(Node*headPtr, int data){ //добавление элемента
		if (headPtr == nullptr) return createNode(data);
		else if (data < headPtr->data) {
			headPtr->left = addNode(headPtr->left, data);
		}
		else if (data > headPtr->data) {
			headPtr->right = addNode(headPtr->right, data);
		}
		return headPtr;
	}
};
int main()
{
	BinaryTree bt;
	Node* ptr;
	ptr=bt.addNode(bt.getHead(), 5);
	bt.setHead(ptr);
	ptr = bt.addNode(bt.getHead(), 10);
	bt.setHead(ptr);
	ptr = bt.addNode(bt.getHead(), 15);
	bt.setHead(ptr);

	return 0;
}
