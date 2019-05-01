// ConsoleApplication10.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>

struct node
{
	int data;
	struct node * next;
};
struct node * head = NULL;
struct node * tail = NULL;

void insert(int new_data);
void display(node * ptr);
void delete_data(int n);

int main()
{
	insert(1);
	insert(4);
	display(head);
	return 0;
}

void insert(int new_data)
{
	struct node * new_node = new node;
	new_node->data = new_data;
	new_node->next = head;
	head = new_node;
}

void display(node * ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->data << " ";
		ptr = ptr->next;
	}
}

void delete_data(int n)
{
	for (int i = 0; i < n-1; i++)
	{

	}
}
