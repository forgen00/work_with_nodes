#include <iostream>

#include "Node.h"


int main() {
	srand(time(0));
	Node* head = nullptr;
	Node* head2 = nullptr;

	for (int i = 0; i <= 10; ++i) {
		push_back(head, i);
	}
	for (int i = 0; i <= 20; i += 2) {
		push_back(head2, i);
	}
	print(head); 
	std::cout << std::endl;
	print(head2);
	std::cout << std::endl;

	Node* new_head = merge(head, head2);
	print(new_head); 
	std::cout << std::endl;
	reverse(new_head);
	print(new_head);

	return 0;
}