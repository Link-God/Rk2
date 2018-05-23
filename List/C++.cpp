#include <sstream>
#include<iostream>
#include <utility>

using namespace std;

struct node_t 
{
	int value;
	node_t * next;
};

bool read(char & op, int & value) {
	string line;
	getline(cin, line);
	istringstream stream(line);

	if (stream >> op) {
		if (op == '+' && stream >> value) {
			return true;
		}
		else if (op == '-' || op == '/' || op == '=' || op == 'q') {
			return true;
		}
	}
	return false;
}
void add_to_end(node_t * & head , int value)
{
	node_t * node = new node_t;
	node->value = value;
	node->next = nullptr;

	if (head == nullptr) {
		head = node;
	}
	else {
		node_t * last = head; 
		while (last->next) {
			last = last->next;
		}
		last->next = node;
	}
}
void delete_first(node_t * & head)
{
	node_t *time = head; // указатель 
	head = head->next;
	delete time; // т.к указатель , то при удалении удалиться и сам "элемент"
}
void print(node_t * head) {
	node_t *p;
	p = head;
	while (p) {
		cout << "+---+" << "    ";
		p = p->next;
	}
	p = head;
	cout << endl;

	while (p) {
		cout << "| " << p->value << " |";
		p = p->next;
		if (p) {
			cout << "--->";
		}
	}
	p = head;
	cout << endl;

	while (p) {
		cout << "+---+" << "    ";
		p = p->next;
	}
	cout << endl;
}
void reverse(node_t * &head)
{
	node_t*new_head = nullptr;
	
	for (node_t*node = head; node; )
	{
		node_t * node_next = node->next;
		node->next = new_head;
		new_head = node;
		node = node_next;
	}
	head = new_head;
}
