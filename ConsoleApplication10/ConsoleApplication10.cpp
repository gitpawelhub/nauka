// ConsoleApplication10.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};
struct node * head = NULL;
struct node * tail = NULL;
struct node * cursor = NULL;

void insert(int new_data);
void display(node * ptr);
void delete_data(int n, node * ptr);
void reset(int n, node * ptr);
void next();
void prev();
void makenull(node * ptr);

int main()
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	display(head);
	delete_data(1, head);
	display(head);
	delete_data(3, head);
	display(head);
	reset(1, head);
	next();
	prev();
	makenull(head);
	return 0;
}

void insert(int new_data)
{
	if (head == NULL)
	{
		struct node * new_node = new node;
		head = new_node;
		new_node->data = new_data;
		new_node->next = NULL;
		new_node->prev = NULL;
		tail = new_node;
	}
	else
	{
		struct node * new_node = new node;
		new_node->prev = tail;
		new_node->next = NULL;
		new_node->data = new_data;
		tail->next = new_node;
		tail = new_node;
	}
}
void display(node * ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->data << "\t";
		ptr = ptr->next;
	}
	std::cout << "\nHead = " << head->data << " Tail = " << tail->data << std::endl;
}
void delete_data(int n, node * ptr)
{
	for (int i = 0; i < n-1; i++)//przejscie do ntego rekordu
	{
		ptr = ptr->next;
	}

	if (head == ptr) //usuniecie rekordu
	{
		head = ptr->next;
		(ptr->next)->prev = NULL;
	}	
	else if (tail == ptr)
	{
		tail = ptr->prev;
		(ptr->prev)->next = NULL;
	}
	else
	{
		(ptr->prev)->next = ptr->next;
		(ptr->next)->prev = ptr->prev;
	}
	delete ptr;
}
void reset(int n, node * ptr)
{
	for (int i = 0; i < n - 1; i++)//przejscie do ntego rekordu
	{
		ptr = ptr->next;
	}
	cursor = ptr;
}
void next()
{
	std::cout << cursor->data;
	cursor = cursor->next;
}
void prev()
{
	std::cout << cursor ->data;
	cursor = cursor->prev;
}
void makenull(node * ptr)
{
	while (tail != ptr)
	{
		ptr = ptr->next;
		delete ptr->prev;
	}
	delete ptr;
	head = NULL;
	tail = NULL;
	cursor = NULL;
}