#include "pch.h"
#include "List.h"

void List::Add(int item) {
	
	Node* newNode = new Node();;
	newNode->data = item;

	if (Count() == 0) { //The list is empty
		header = newNode;
		tail = newNode;
	}
	else { //There are elements
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

int List::Count() {
	return count;
}

int List::GetItem(int index) {
	int counter = 0;
	struct Node* temp = header;

	while ((temp) && counter <= index) {
		if (counter == index) {
			return temp->data;
		}
		temp = temp->next;
		counter++;
	}
	return -1;
}