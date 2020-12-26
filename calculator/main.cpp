#include <iostream>
#include "calculator.h"
#include <string>

int main()
{
	calculator* Test = new calculator;
	string formula;

	formula = "ln(e) + tg(pi *0.25) + ctg(pi/4)+log10 + cossin0 * 2^4 +(-1)/abs(cos(-pi)) - sqrt196";
	//getline(cin, formula); // консольный ввод
	formula.push_back('|'); // stop symbol
	if (Test->reeding(formula) == true)
	{
		cout << endl;
		cout << "\nInfix form :"; Test->print_to_console();
		Test->inf_to_pref();
		cout << "\nPrefix form :"; Test->print_to_console();
		cout << "\nAnswer: " << Test->calculations();
		cout << endl;
		Test->clear();
	}
	return 0;
}