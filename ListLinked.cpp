#include <iostream>

using namespace std;

struct node {
	int value;
	node *next;
};

class linked_list {
private:
	node *head;
	node *tail;
public:
	linked_list() {
		head = nullptr;
		tail = nullptr;
	}

	void create(int value) {
		struct node *temp;
		temp = new struct node;
		temp->value = value;
		temp->next = nullptr;
		head = temp;
		tail = head;
	}

	//
	void insert(int value) {
		//duy tri tang dan
		if (value < head->value) {
			insert_beginning(value);
		}
		else if ((head->next == nullptr) || (value > tail->value)) {
			insert_end(value);
		}
		else {
			insert_middle(value);
		}
	}

	void insert_beginning(int value) {
		if (head->next == nullptr) {
			tail = head;
		}
		node *temp;
		temp = new node;
		temp->value = value;
		temp->next = head;
		head = temp;
	}

	void insert_end(int value) {
		node *temp;
		temp = new node;
		temp->value = value;
		temp->next = nullptr;
		if (head->next == nullptr) {
			head->next = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
		}
		tail = temp;
	}


	void insert_middle(int value) {
		node *temp;
		temp = new node;
		temp->value = value;

		node *current = head;
		node *prev = current;

		while (current->value < temp->value) {
			prev = current;
			current = current->next;
		}
		prev->next = temp;
		temp->next = current;
	}

	void delete_node(int value) {
		if (head == nullptr) {
			cout << "List is empty\n";
			return;
		}

		if (head->value == value) {
			if (head->next == nullptr) {
				delete(head);
				head = tail = nullptr;
			}
			node *temp = head;
			head = head->next;
			delete(temp);
		}
		else {
			node *current = head;
			node *prev = current;

			while ((current->value != value) && (current->next != nullptr)) {
				prev = current;
				current = current->next;
			}

			if ((current->value != value) && (current->next == nullptr)) {
				cout << "Key not found\n";
			}
			else if ((current->value == value) && (current->next == nullptr)) {
				tail = prev;
				prev->next = nullptr;
				delete(current);
			}
			else {
				prev->next = current->next;
				delete(current);
			}

		}
	}

	void search_node(int value) {
		if (head->value == value || tail->value == value) {
			cout << "Node found\n";
			return;
		}
		node *current = head;
		while ((current->value != value) && (current->next != nullptr)) {
			current = current->next;
		}

		if (current->value == value) {
			cout << "Node found\n";
		}
		else {
			cout << "Node not found\n";
		}
	}

	void print_nodes(void) {
		node *current = head;
		while (current != nullptr) {
			cout << current->value << '\n';
			current = current->next;
		}
	}
};


int main(void) {
	linked_list list;

	list.create(0);

	for (int i = 1; i < 20; ++i) {
		list.insert(i);
	}

	list.search_node(5);
	list.search_node(0);
	list.search_node(-1);

	list.delete_node(19);
	list.delete_node(0);

	list.print_nodes();
	system("pause");
	return 0;
}