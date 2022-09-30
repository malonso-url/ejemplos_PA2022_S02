#include "pch.h"
#include "ListaCartas.h"

void ListaCartas::Add(Carta* item) {

	NodeCarta* newNode = new NodeCarta();
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

int ListaCartas::Count() {
	return count;
}

Carta* ListaCartas::GetItem(int index) {
	int counter = 0;
	NodeCarta* temp = header;

	while ((temp) && counter <= index) {
		if (counter == index) {
			return temp->data;
		}
		temp = temp->next;
		counter++;
	}
	return nullptr;
}
