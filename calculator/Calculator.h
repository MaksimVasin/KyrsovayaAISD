#pragma once
#include <iostream>
#include "LinkedList.h"

using namespace std;

class calculator
{
private:
	class Node
	{
	public:
		enum class operators { unknown, plus, minus, multiplication, division, power, cos, sin, tg, ctg, ln, log, sqrt, module, pi, e, number, open_bracket, close_bracket, unary_minus }; // operators + operands
		enum class priorityes { unknown_p = - 1, brackets = 0, plus_minus = 1, multiplication_divide = 2, power_p = 3, function = 4, number_p = 5 };
		Node(string data, operators oper, priorityes priorit, Node* next = nullptr, Node* prev = nullptr)
		{
			this->next = next;
			this->prev = prev;
			this->data = data;
			this->oper = oper;
			this->priorit = priorit;
		};
		string data;
		Node* next;
		Node* prev;
		operators oper; // operators or operands
		priorityes priorit; // priorityes
		size_t sizeSymb; // size symbol
	};
	bool correct; // correct reeding flag
	size_t sizeCalc; //count elements from the list (calculator)
	Node* head; 
	Node* tail;
public:
	//////////////////////////// old metods
	calculator();
	~calculator();
	bool isEmpty();
	void push_back(string symbol, Node::operators oper, Node::priorityes priorit);
	void push_front(string symbol, Node::operators oper, Node::priorityes priorit);
	void pop_back();
	void print_to_console();
	void clear();
	//////////////////////////// correct reeding
	void priorityes_operator_definition(string symbols, size_t pos);
	bool correct_reeding(); // 
	bool reeding(string Formula);
	//////////////////////////// infex to prefix + calculation
	void inf_to_pref();
	double calculations();
};