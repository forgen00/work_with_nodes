#ifndef _NODE_H
#define _NODE_H

struct Node {
	int value;
	Node* next;
	Node* prev;
};

Node* create_node(int value, Node* next = nullptr, Node* prev = nullptr);			//������� ������ ����� ����
Node* find(Node* head, int value);							//������� ������� ������� � value = value
void push_back(Node*& head, int value);						//������� ��������� ����� ���� �� ��������� value
															//� ����� ������ head
void push_front(Node*& head, int value);					//������� � ������ ������
void print(Node* head);										//�������� ������ head

void remove(Node*& head, Node* target);						//������� �� ������ ������� head
void insert(Node*& head, Node* target, int value);						//�������� ������� �� ��������� target

void free_nodes(Node*& head);								//����������� ������

void reverse(Node*& head);									//������������� ������
Node* merge(Node* &first, Node* &second);						//������� ������������� �������


#endif