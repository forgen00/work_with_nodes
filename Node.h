#ifndef _NODE_H
#define _NODE_H

struct Node {
	int value;
	Node* next;
	Node* prev;
};

Node* create_node(int value, Node* next = nullptr, Node* prev = nullptr);			//Функция создаёт новый узел
Node* find(Node* head, int value);							//Функция находит элемент с value = value
void push_back(Node*& head, int value);						//Функция добавляет новый узел со значением value
															//В конец списка head
void push_front(Node*& head, int value);					//Вставка в начало списка
void print(Node* head);										//Печатает список head

void remove(Node*& head, Node* target);						//Удалить из списка элемент head
void insert(Node*& head, Node* target, int value);						//Вставить элемент за элементом target

void free_nodes(Node*& head);								//Освобождает память

void reverse(Node*& head);									//Разворачивает список
Node* merge(Node* &first, Node* &second);						//Слияние сортированных списков


#endif