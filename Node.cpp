#include <iostream>

#include "Node.h"

//������� ������ ����� ����
Node* create_node(int value, Node* next, Node* prev) {
	Node* head = new Node;
	head->value = value;
	head->next = next;
	head->prev = prev;
	return head;
}

//������� ������� ������ ������� � value = value
Node* find(Node* head, int value) {
	for (Node* it = head; it->next != nullptr; it = it->next) {
		if (it->value == value) {
			return it;
		}
	}

	return nullptr;
}

//������� ��������� ����� ���� �� ��������� value � ����� ������ head
void push_back(Node*& head, int value) {
	if (!head) {
		head = create_node(value);
		return;
	}

	Node* last = create_node(value);
	Node* it;
	for (it = head; it->next != nullptr; it = it->next);
	it->next = last;
	last->prev = it;
}

//�������� ������ head
void print(Node* head) {
	for (Node* tmp = head; tmp != nullptr; tmp = tmp->next) {
		std::cout << tmp->value << ' ';
	}
}

//������� �� ������ ������� head
void remove(Node*& head, Node* target) {
	Node* prev;
	Node* prev1 = target->prev;
	for (prev = head; prev->next != target; prev = prev->next);
	Node* next = target->next;

	delete target;
	prev->next = next;
	prev->prev = prev1;
}

//�������� ������� �� ��������� target
void insert(Node*& head, Node* target, int value) {
	Node* cur = create_node(value);
	Node* next = target->next;
	Node* prev = target->prev;
	target->next = cur;
	cur->next = next;
	cur->prev = prev;
}

//����������� ������
void free_nodes(Node*& head) {
	Node* cur = head;

	while (cur != nullptr) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
}

//������� � ������ ������
void push_front(Node*& head, int value) {
	Node* cur = create_node(value);
	cur->next = head;
	head = cur;
}


//��
//������������� ������
void reverse(Node*& head) {
	Node* new_head = nullptr;
	for (Node* pos = head; pos;) {
		Node* save_next = pos->next;
		pos->next = new_head;
		new_head = pos;
		pos = save_next;
	}
	head = new_head;
}

//������� ������������� �������
Node* merge(Node* first, Node* second) {
	// 1 3 5 8 - ������ ������
	// 4 10 12 - ������ ������
	//������� ������ ������� 1 3 4 5 8 10 12
	
	Node* ans = new Node;
	Node* it = ans;

	while(first || second) {
		
		if (first && (!second || first->value <= second->value)) {
			it->value = first->value;
			first = first->next;
		}
		else {
			it->value = second->value;
			second = second->next;
		}
		
		it->next = (first || second ? new Node : nullptr);
		it = it->next;
	}
	return ans;
}