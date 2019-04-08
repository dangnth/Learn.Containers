#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* pNext;
};

class ListLinked {
public:
	ListLinked();
	~ListLinked();
	//
	void push(int newdata);
	void printf();
	bool isPanlidore();
	bool isPanlidoreUtl(Node **left, Node* right);

private:
	Node* m_nHead;
};

bool ListLinked::isPanlidoreUtl(Node **left, Node* right) {
	//left can thay doi nen ** va & con right de quy lui
	if (right == nullptr) {
		return true;
	}
	bool checking1 = isPanlidoreUtl(left, right->pNext);
	if (checking1 == false) return false;
	//
	bool checking2 = ((*left)->data == right->data);
	(*left) = (*left)->pNext;
	return checking2;
}

bool ListLinked::isPanlidore() {
	return ListLinked::isPanlidoreUtl(&this->m_nHead, (this->m_nHead));
}

ListLinked::ListLinked() {
	this->m_nHead = new Node;
	m_nHead = NULL;
}

ListLinked::~ListLinked() {
	Node *curNode = this->m_nHead;
	Node *nextNode = this->m_nHead;
	while (curNode != NULL) {
		delete curNode;
		nextNode = nextNode->pNext;
		curNode = nextNode;
	}
	this->m_nHead = NULL;
}

void ListLinked::push(int newdata) {
	Node* newNode;
	newNode = new Node;
	newNode->data = newdata;
	newNode->pNext = nullptr;
	//
	if (this->m_nHead == nullptr) {
		this->m_nHead = newNode;
	}
	else {
		Node* curNode = new Node;
		curNode = this->m_nHead;
		while (curNode->pNext != nullptr) {
			curNode = curNode->pNext;
		}
		curNode->pNext = newNode;
	}
}

void ListLinked::printf() {
	Node* curNode = new Node;
	curNode = this->m_nHead;
	while (curNode != nullptr) {
		cout << curNode->data << endl;
		curNode = curNode->pNext;
	}
}



void main() {
	ListLinked list;
	int a[] = { 1,2,3,3,2,1 };
	int b[] = { 1,2,3,2,1 };
	int c[] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 6; i++) {
		list.push(c[i]);
	}
	list.printf();
	cout << list.isPanlidore() << endl;
	system("pause");
}