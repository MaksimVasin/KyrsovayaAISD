#include <iostream>
#include "LinkedList.h"
#include  <stdexcept>

LinkedList::LinkedList(double data) // creating a list WITH data
{
	head = new Node;
	head->data = data;
	tail = head;
	sizeList++;
}
LinkedList::LinkedList() // creating a list WITHOUT data
{
	tail = NULL;
	head = NULL;
	sizeList = 0;
}
LinkedList::~LinkedList()
{
	clear();
}

double LinkedList::at(size_t pos)
{
	if (isEmpty()) throw std::out_of_range("The list is empty");
	if (pos + 1 > sizeList) throw std::out_of_range("Index is greater than list size");
	else
	{
		Node* current = head;
		for (size_t position = 0; position < pos; position++) // go to the desired list position
		{
			current = current->next;
		}
		return current->data;
	}
}

void LinkedList::clear() // deleting all list items
{
	if (isEmpty()); //throw std::out_of_range("The list is empty");
	else
	{
		while (sizeList != 0)
		{
			pop_back();
		}
	}
}

size_t LinkedList::get_size()
{
	return sizeList;
}

void LinkedList::insert(double data, size_t pos)
{
	if (sizeList == 0) throw std::out_of_range("The list is empty");
	if (pos + 1 > sizeList) throw std::out_of_range("Index is greater than list size");
	else
	{
		Node* current = head;
		if (pos == 0)
		{
			push_front(data);
		}
		else
		{
			for (size_t position = 0; position < pos; position++)
			{
				current = current->next;
			}
			Node* InsertElem = new Node;
			InsertElem->prev = current->prev;
			InsertElem->next = current;
			current->prev->next = InsertElem;
			current->prev = InsertElem;
			InsertElem->data = data;
			sizeList++;
		}
	}
};

bool LinkedList::isEmpty()
{
	if (sizeList == 0) return true;
	else return false;
}

void LinkedList::pop_back()
{
	if (sizeList == 0) throw std::out_of_range("The list is empty");
	else if (sizeList == 1)
	{
		delete tail;
		sizeList--;
	}
	else // if SizeList != 0,1
	{
		Node* current = tail;
		current->prev->next = NULL;
		tail = current->prev;
		delete current;
		sizeList--;
	}
}

double LinkedList::return_pop_back()
{
	if (sizeList == 0) throw std::out_of_range("The list is empty");
	else if (sizeList == 1)
	{
		sizeList--;
		return tail->data; //////////////NEW
		delete tail;
	}
	else // if SizeList != 0,1
	{
		sizeList--;
		Node* current = tail;
		current->prev->next = NULL;
		tail = current->prev;
		return current->data; //////////////NEW
		delete current;
	}
}

double LinkedList::return_back()
{
	return tail->data; //////////////NEW
}

void LinkedList::pop_front()
{
	if (isEmpty()) throw std::out_of_range("The list is empty");
	else if (sizeList == 1)
	{
		delete head;
		sizeList--;
	}
	else // if SizeList != 0,1
	{
		Node* current = head;
		head = current->next;
		current->next->prev = NULL;
		delete current;
		sizeList--;
	}
}

void LinkedList::print_to_console()
{
	if (isEmpty())
	{
		std::cout << "\n\"The list is empty\"\n";
	}
	else
	{
		Node* current = head;
		std::cout << " | ";
		for (size_t position = 0; position < sizeList; position++)
		{
			std::cout << current->data << " | ";
			current = current->next;
		}
		std::cout << "\n\nSizeList: " << sizeList << "\n";
	}
}

void LinkedList::push_back(double data)
{
	if (isEmpty()) // if the list is empty
	{
		head = new Node;
		head->data = data;
		tail = head;
	}
	else
	{
		tail->next = new Node;
		tail->next->prev = tail;
		tail = tail->next;
		tail->data = data;
	}
	sizeList++;
}

void LinkedList::push_front(double data)
{
	if (isEmpty()) // if the list is empty
	{
		head = new Node;
		head->data = data;
		tail = head;
	}
	else
	{
		head->prev = new Node;
		head->prev->next = head;
		head = head->prev;
		head->data = data;
	}
	sizeList++;
}

void LinkedList::remove(size_t pos)
{
	if (sizeList == 0) throw std::out_of_range("The list is empty");
	if (pos + 1 > sizeList) throw std::out_of_range("Index is greater than list size");
	else
	{
		if (pos == 0) // if this is the first element
		{
			pop_front();
		}
		else if (pos == sizeList - 1) // if this is the last element
		{
			pop_back();
		}
		else
		{
			Node* current = head;
			for (size_t position = 0; position < pos; position++) // go to the desired list position
			{
				current = current->next;
			}
			current->prev->next = current->next; // replacement of pointer (next)
			current->next->prev = current->prev; // replacement of pointer (prev)
			delete current;
			sizeList--;
		}
	}
}

void LinkedList::reverse()
{
	double buffer; // auxiliary variable to swap
	Node* current2 = tail;
	Node* current = head;
	if (sizeList == 0) throw std::out_of_range("The list is empty");
	else if (sizeList == 1);
	else
	{
		for (size_t position = 0; position < sizeList / 2; position++)
		{
			if (current->data != current2->data)
			{
				buffer = current2->data;		// swap
				current2->data = current->data; //
				current->data = buffer;         //
			}
			current = current->next; // "current" moves from the head to the center
			current2 = current2->prev; // "current2" moves from the tail to the center
		}
	}
}

void LinkedList::set(double data, size_t pos) // replacing an element by index with the passed element
{
	if (sizeList == 0) throw std::out_of_range("The list is empty");
	if (pos + 1 > sizeList) throw std::out_of_range("Index is greater than list size");
	else
	{
		Node* current = head;
		for (size_t position = 0; position < pos; position++) // go to the desired list position
		{
			current = current->next;
		}
		current->data = data;
	}
}