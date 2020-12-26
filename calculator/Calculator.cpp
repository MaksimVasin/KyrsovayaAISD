#include <iostream>
#include "Calculator.h"
#define _USE_MATH_DEFINES // M_PI M_E
#include <math.h> // constant + operators
////////////////////////////////////////////////////////////////////////////////////////////////////OLD METODS
calculator::calculator()
{
	correct = true;
	head = nullptr;
	tail = nullptr;
	sizeCalc = 0;
}
calculator::~calculator()
{
	clear();
}
bool calculator::isEmpty()
{
	if (sizeCalc == 0) return true;
	else return false;
}
void calculator::push_back(string symbol, Node::operators oper, Node::priorityes priorit)
{
	if (isEmpty()) // if the list is empty
	{
		head = new Node(symbol, oper, priorit);
		tail = head;
	}
	else
	{
		tail->next = new Node(symbol, oper, priorit);
		tail->next->prev = tail;
		tail = tail->next;
	}
	sizeCalc++;
};
void calculator::push_front(string symbol, Node::operators oper, Node::priorityes priorit)
{
	if (isEmpty())
	{
		head = new Node(symbol, oper, priorit);
	}
	else
	{
		head->prev = new Node(symbol, oper, priorit);
		head->prev->next = head;
		head = head->prev;
	}
	sizeCalc++;
};
void calculator::pop_back()
{
	if (sizeCalc == 0) throw std::out_of_range("The list is empty");
	else if (sizeCalc == 1)
	{
		delete tail;
		sizeCalc--;
	}
	else // if SizeList != 0,1
	{
		Node* current = tail;
		current->prev->next = NULL;
		tail = current->prev;
		delete current;
		sizeCalc--;
	}
}
void calculator::print_to_console()
{
	if (isEmpty())
	{
		std::cout << "\n\"The formula is empty\"\n";
	}
	else
	{
		Node* current = head;
		while (current != nullptr) // tail->next
		{
			{
				cout << current->data << " "; //<< " | ";
				current = current->next;
			}
		}
		//cout << "\n\nSizeCalc: " << sizeCalc << "\n";
	}
}
void calculator::clear()
{
	if (isEmpty())
		std::cout << "\n\"The calculator is empty\"\n";
	else
	{
		while (sizeCalc > 0) pop_back();
		correct = true;
		head = nullptr;
		tail = nullptr;
		sizeCalc = 0;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////CORRECT_REEDING
void calculator::priorityes_operator_definition(string symbols, size_t pos)
{
	if (symbols[pos] == '+')
	{
		tail->oper = Node::operators::plus;
		tail->priorit = Node::priorityes::plus_minus;
		tail->sizeSymb = 1;
	}
	else if ((symbols[pos] == '-') && (pos == 0)) // unary minus
	{
		tail->oper = Node::operators::unary_minus;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 1;
	}
	else if ((symbols[pos] == '-') && (symbols[pos - 1] == '(')) // unary minus // second "if" because pos !< 0
	{
		tail->oper = Node::operators::unary_minus;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 1;
	}
	else if (symbols[pos] == '-') // binary minus
	{
		tail->oper = Node::operators::minus;
		tail->priorit = Node::priorityes::plus_minus;
		tail->sizeSymb = 1;
	}
	else if (symbols[pos] == '*')
	{
		tail->oper = Node::operators::multiplication;
		tail->priorit = Node::priorityes::multiplication_divide;
		tail->sizeSymb = 1;
	}
	else if (symbols[pos] == '/')
	{
		tail->oper = Node::operators::division;
		tail->priorit = Node::priorityes::multiplication_divide;
		tail->sizeSymb = 1;
	}
	else if (symbols[pos] == '^')
	{
		tail->oper = Node::operators::power;
		tail->priorit = Node::priorityes::power_p;
		tail->sizeSymb = 1;
	}
	else if ((symbols[pos] == 'c') && (symbols[pos + 1] == 'o') && (symbols[pos + 2] == 's'))
	{
		tail->oper = Node::operators::cos;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 3;
	}
	else if ((symbols[pos] == 's') && (symbols[pos + 1] == 'i') && (symbols[pos + 2] == 'n'))
	{
		tail->oper = Node::operators::sin;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 3;
	}
	else if ((symbols[pos] == 't') && (symbols[pos + 1] == 'g'))
	{
		tail->oper = Node::operators::tg;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 2;
	}
	else if ((symbols[pos] == 'c') && (symbols[pos + 1] == 't') && (symbols[pos + 2] == 'g'))
	{
		tail->oper = Node::operators::ctg;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 3;
	}
	else if ((symbols[pos] == 'l') && (symbols[pos + 1] == 'n'))
	{
		tail->oper = Node::operators::ln;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 2;
	}
	else if ((symbols[pos] == 'l') && (symbols[pos + 1] == 'o') && (symbols[pos + 2] == 'g'))
	{
		tail->oper = Node::operators::log;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 3;
	}
	else if ((symbols[pos] == 's') && (symbols[pos + 1] == 'q') && (symbols[pos + 2] == 'r') && (symbols[pos + 3] == 't'))
	{
		tail->oper = Node::operators::sqrt;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 4;
	}
	else if ((symbols[pos] == 'a') && (symbols[pos + 1] == 'b') && (symbols[pos + 2] == 's'))
	{
		tail->oper = Node::operators::module;
		tail->priorit = Node::priorityes::function;
		tail->sizeSymb = 3;
	}
	else if ((symbols[pos] == 'p') && (symbols[pos + 1] == 'i'))
	{
		tail->oper = Node::operators::pi;
		tail->priorit = Node::priorityes::number_p;
		tail->sizeSymb = 2;
	}
	else if (symbols[pos] == 'e')
	{
		tail->oper = Node::operators::e;
		tail->priorit = Node::priorityes::number_p;
		tail->sizeSymb = 1;
	}
	else if (symbols[pos] == '(')
	{
		tail->oper = Node::operators::open_bracket;
		tail->priorit = Node::priorityes::brackets;
		tail->sizeSymb = 1;
	}
	else if (symbols[pos] == ')')
	{
		tail->oper = Node::operators::close_bracket;
		tail->priorit = Node::priorityes::brackets;
		tail->sizeSymb = 1;
	}
	else if ((symbols[pos] == '0') || (symbols[pos] == '1') || (symbols[pos] == '2') || (symbols[pos] == '3') || (symbols[pos] == '4') || (symbols[pos] == '5') || (symbols[pos] == '6') || (symbols[pos] == '7') || (symbols[pos] == '8') || (symbols[pos] == '9'))
	{
		bool correct_input = true;
		string Num = "";
		Num.push_back(symbols[pos]);
		int dot = 1;
		const int size_Num = 20; // 20 signs
		size_t i = 1;
		while ((symbols[pos + i] == '0') || (symbols[pos + i] == '1') || (symbols[pos + i] == '2') || (symbols[pos + i] == '3') || (symbols[pos + i] == '4') || (symbols[pos + i] == '5') || (symbols[pos + i] == '6') || (symbols[pos + i] == '7') || (symbols[pos + i] == '8') || (symbols[pos + i] == '9') || (symbols[pos + i] == '.'))
		{
			if (symbols[i] == '.') dot--;
			if ((dot < 0) || (i > size_Num) || ((symbols[pos] == '0') && (symbols[pos+1] != '.')))
			{
				correct_input = false;
			}
			if (correct_input)
			{
				Num.push_back(symbols[pos + i]);
				i++;
			}
			else break;
		}
		if (correct_input)
		{
			tail->oper = Node::operators::number;
			tail->priorit = Node::priorityes::number_p;
			tail->sizeSymb = i;
		}
		else
		{
			cout << "\nIncorrect Num: ";
			for (size_t k = 0; k < i; k++)
			{
				cout << symbols[pos + k];
			}
		}
	}
	else
	{
		correct = false;
	}
}
bool calculator::correct_reeding()
{
	if (!isEmpty())
	{
		Node* cur = head;
		int count_open_bracket = 0;
		if (cur->oper == Node::operators::unknown) // symbol indefined
		{
			cout << "\nIncomrehemsible symbol: " << cur->data << "...";
			return false;
		}
		if ((cur->priorit == Node::priorityes::plus_minus) || (cur->priorit == Node::priorityes::multiplication_divide) || (cur->priorit == Node::priorityes::power_p) || (cur->oper == Node::operators::close_bracket)) { cout << endl << cur->data; return false; } // +Num... / *Num... / ^Num...
		while (cur != nullptr)
		{
			if (cur->oper == Node::operators::unknown) // symbol indefined
			{
				cout << "\nIncomrehemsible symbol: " << cur->data << "...";
				return false;
			}
			if (cur->prev != nullptr)
			{
				if ((cur->prev->priorit >= Node::priorityes::plus_minus) && (cur->prev->priorit <= Node::priorityes::power_p) // *+ -+ ^/
					&& (cur->priorit >= Node::priorityes::plus_minus) && (cur->priorit <= Node::priorityes::power_p))
				{
					cout << endl << cur->data; return false;
				}
				else if ((cur->prev->oper == Node::operators::unary_minus) && (cur->oper == Node::operators::close_bracket)) { // unary_min)
					cout << endl << cur->data; return false; }
				else if ((cur->prev->oper == Node::operators::close_bracket) && ((cur->priorit == Node::priorityes::number_p) || (cur->priorit == Node::priorityes::function) || (cur->oper == Node::operators::open_bracket))) {
					cout << endl << cur->data; return false; }
				else if ((cur->oper == Node::operators::close_bracket) && !((cur->prev->priorit == Node::priorityes::number_p) || (cur->prev->oper == Node::operators::close_bracket))) { 
					cout << endl << cur->data; return false; } // *) // only a num and close_bracket before the close_bracket
				else if ((cur->prev->oper == Node::operators::open_bracket) && !((cur->priorit == Node::priorityes::number_p) || (cur->priorit == Node::priorityes::function) || (cur->oper == Node::operators::open_bracket))) {
					cout << endl << cur->data; return false; } // (* // only (( , (fun , (num , (unarminus
				else if ((cur->prev->oper == Node::operators::number) && ((cur->priorit == Node::priorityes::function) || (cur->priorit == Node::priorityes::number_p) || (cur->oper == Node::operators::open_bracket))) {
					cout << endl << cur->data; return false;
				}
			}
			if ((cur->oper == Node::operators::close_bracket) && (count_open_bracket == 0)) {
				cout << endl << cur->data; return false;
			} // Num + Num ) + Num
			else if (cur->oper == Node::operators::close_bracket) count_open_bracket--;
			if (cur->oper == Node::operators::open_bracket) count_open_bracket++;
			cur = cur->next;
		}
		if (count_open_bracket != 0)
		{
			cout << "(";
			return false;
		}
		return true;
	}
}
bool calculator::reeding(string formula)
{
	char stop_symbol = '|';
	bool stop = false; // flag - stop reeding
	size_t pos = 0;
	while (!stop)
	{
		while (formula[pos] == ' ') pos++; // removing spaces
		if ((formula[pos] == stop_symbol) || (correct == false)) // if stop symbol - exit
		{
			stop = true;
			break;
		}
		push_back("", Node::operators::unknown, Node::priorityes::unknown_p);
		priorityes_operator_definition(formula, pos);
		if (tail->oper == Node::operators::unknown)
		{
			stop = true;
			tail->sizeSymb = 1;
		}
		for (int k = pos; k < pos + tail->sizeSymb; k++)
		{
			tail->data.push_back(formula[k]);
		}
		pos = pos + tail->sizeSymb;
	}
	if (correct_reeding() == false)
	{
		cout << " - Wrong position symbol.\n";
		correct = false;
		return false;
	}
	else return true;
}
////////////////////////////////////////////////////////////////////////////////////////////////////INFIX TO PREFIX + CALCULATION
void calculator::inf_to_pref()
{
	Node* cur = tail; // infex form
	calculator* pref = new calculator; // prefix form
	calculator* stack = new calculator;

	Node* bonus = pref->head;//////////////////////////////////////////////////////////

	for (size_t now = 0; now < sizeCalc; now++) // пока сущ предыдущий
	{
		if (cur->oper == Node::operators::close_bracket)
		{
			stack->push_back(cur->data, cur->oper, cur->priorit);
		}
		else if (cur->oper == Node::operators::number)
		{
			pref->push_front(cur->data, cur->oper, cur->priorit);
		}
		else if (cur->oper == Node::operators::open_bracket)
		{
			while (stack->tail->oper != Node::operators::close_bracket)
			{
				pref->push_front(stack->tail->data, stack->tail->oper, stack->tail->priorit);
				stack->pop_back();
			}
		}
		else //if (cur->num != 0)// operatori
		{
			if (stack->isEmpty())
			{
				stack->push_back(cur->data, cur->oper, cur->priorit);
			}
			else
			{
				while ((int)stack->tail->priorit >= (int)cur->priorit)
				{
					pref->push_front(stack->tail->data, stack->tail->oper, stack->tail->priorit);
					stack->pop_back();
					if (stack->isEmpty()) break;
				}
				stack->push_back(cur->data, cur->oper, cur->priorit);
			}
		}
		cur = cur->prev;
	}
	while (!stack->isEmpty())
	{
		if (stack->tail->oper != Node::operators::close_bracket)
		{
			pref->push_front(stack->tail->data, stack->tail->oper, stack->tail->priorit);
		}
			stack->pop_back();
	}

	// check tail
	head = pref->head;
	cur = head;
	for (size_t pos = 0; pos < pref->sizeCalc; pos++)
	{
		tail = cur;
		cur = cur->next;
	}
	sizeCalc = pref->sizeCalc;
}
double calculator::calculations()
{
	Node* pref = tail;
	LinkedList* stack = new LinkedList;
	double a, b;
	while(pref != head->prev)
	{
		switch (pref->oper)
		{
		case Node::operators::plus:
		{
			a = stack->return_pop_back();
			b = stack->return_pop_back();
			stack->push_back(a + b);
		}
		break;
		case Node::operators::minus:
		{
			a = stack->return_pop_back();
			b = stack->return_pop_back();
			stack->push_back(a - b);
		}
		break;
		case Node::operators::multiplication:
		{
			a = stack->return_pop_back();
			b = stack->return_pop_back();
			stack->push_back(a * b);
		}
		break;
		case Node::operators::division:
		{
			a = stack->return_pop_back();
			b = stack->return_pop_back();
			stack->push_back(a / b);
		}
		break;
		case Node::operators::number:
		{
			stack->push_back(atof(pref->data.c_str())); // перевод строки в дабл
		}
		break;
		case Node::operators::power:
		{
			a = stack->return_pop_back();
			b = stack->return_pop_back();
			stack->push_back(pow(a, b));
		}
		break;
		case Node::operators::cos:
		{
			a = stack->return_pop_back();
			stack->push_back(cos(a));
		}
		break;
		case Node::operators::sin:
		{
			a = stack->return_pop_back();
			stack->push_back(sin(a));
		}
		break;
		case Node::operators::tg:
		{
			a = stack->return_pop_back();
			stack->push_back(tan(a));
		}
		break;
		case Node::operators::ctg:
		{
			a = stack->return_pop_back();
			stack->push_back(1 / tan(a));
		}
		break;
		case Node::operators::ln:
		{
			a = stack->return_pop_back();
			stack->push_back(log(a));
		}
		break;
		case Node::operators::log:
		{
			a = stack->return_pop_back();
			stack->push_back(log10(a));
		}
		break;
		case Node::operators::sqrt:
		{
			a = stack->return_pop_back();
			stack->push_back(sqrt(a));
		}
		break;
		case Node::operators::pi:
		{
			stack->push_back(M_PI);
		}
		break;
		case Node::operators::e:
		{
			stack->push_back(M_E);
		}
		break;
		case Node::operators::unary_minus:
		{
			a = stack->return_pop_back();
			stack->push_back((-1) * a);
		}
		break;
		case Node::operators::module:
		{
			a = stack->return_pop_back();
			if (a < 0) stack->push_back((-1) * a);
			else stack->push_back(a);
		}
		break;
		}
		pref = pref->prev;
	} 
	return stack->return_pop_back();
}