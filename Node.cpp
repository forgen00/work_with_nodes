#include <iostream>

#include "Node.h"

//Функция создаёт новый узел
Node* create_node(int value, Node* next, Node* prev) {
	Node* head = new Node;
	head->value = value;
	head->next = next;
	head->prev = prev;
	return head;
}

//Функция находит первый элемент с value = value
Node* find(Node* head, int value) {
	for (Node* it = head; it->next != nullptr; it = it->next) {
		if (it->value == value) {
			return it;
		}
	}

	return nullptr;
}

//Функция добавляет новый узел со значением value в конец списка head
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

//Печатает список head
void print(Node* head) {
	for (Node* tmp = head; tmp != nullptr; tmp = tmp->next) {
		std::cout << tmp->value << ' ';
	}
}

//Удалить из списка элемент head
void remove(Node*& head, Node* target) {
	Node* prev;
	Node* prev1 = target->prev;
	for (prev = head; prev->next != target; prev = prev->next);
	Node* next = target->next;

	delete target;
	prev->next = next;
	prev->prev = prev1;
}

//Вставить элемент за элементом target
void insert(Node*& head, Node* target, int value) {
	Node* cur = create_node(value);
	Node* next = target->next;
	Node* prev = target->prev;
	target->next = cur;
	cur->next = next;
	cur->prev = prev;
}

//Освобождает память
void free_nodes(Node*& head) {
	Node* cur = head;

	while (cur != nullptr) {
		Node* next = cur->next;
		delete cur;
		cur = next;
	}
}

//Вставка в начало списка
void push_front(Node*& head, int value) {
	Node* cur = create_node(value);
	cur->next = head;
	head = cur;
}


//ДЗ
//Разворачивает список
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

//Слияние сортированных списков
Node* merge(Node* &first, Node* &second) {
	// 1 3 5 8 - первый список
	// 4 10 12 - второй список
	//функция должна вернуть 1 3 4 5 8 10 12
	
	Node* new_head = new Node;
	Node* it = new_head;
	Node* ptr1 = first;
	Node* ptr2 = second;

	while(ptr1 || ptr2) {
		
		if (ptr1 && ptr1->value <= ptr2->value) {
			std::cout << "ptr1 " << ptr1->value << '\n';
			it->value = ptr1->value;
			//push_back(new_head, ptr1->value);
			ptr1 = ptr1->next;
			it = it->next;
		}
		else if(ptr2) {
			std::cout << "ptr1 " << ptr2->value << '\n';
			it->value = ptr2->value;
			//push_back(new_head, ptr2->value);
			ptr2 = ptr2->next;
			it = it->next;
		}
		
		if (ptr1 || ptr2) {
			it = new Node;
		}
		else {
			it = nullptr;
		}
	}
	return new_head;
}