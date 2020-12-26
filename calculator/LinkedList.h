#pragma once

class LinkedList
{
public:
	LinkedList(double data); // creating a list WITH data
	LinkedList(); // creating a list WITHOUT data
	~LinkedList();

	void push_back(double data);				 // 1 // add lust element
	void push_front(double data);//				 // 2 // add front element
	void pop_back();							 // 3 // del lust element
	void pop_front();//							 // 4 // del front element
	void insert(double data, size_t pos);// 	  // 5 // add by index 
	double at(size_t pos);//						 // 6 // getting by index
	void remove(size_t pos);//					 // 7 // del by index
	size_t get_size();//							 // 8 // getting size List
	void print_to_console();//					 // 9 // print to console
	void clear();//								 // 10// clear list
	void set(double data, size_t pos);//			 // 11// swap data
	bool isEmpty();								 // 12// checking if the list is empty
	void reverse();//								 // 13// reverse

	double return_pop_back();
	double return_back();//

	//void menu(LinkedList List); //function menu

private:
	struct Node // Node List
	{
		Node(double data = 0, Node* prev = nullptr, Node* next = nullptr)
		{
			this->next = next;
			this->prev = prev;
			this->data = data;
		};
		double data;
		Node* next; // next element
		Node* prev; // previous element
	};
	size_t sizeList;
	Node* head;
	Node* tail;
};