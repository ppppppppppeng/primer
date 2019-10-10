#include "Screen.h"
#include <iostream>

using namespace std;

int main()
{

	Screen myScreen;
	const Screen blank(5, 3, 'Y');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	blank.display(cout);
	cout  << "\n";
	myScreen.display(cout);
	cout << "\n";
	return 0;
}
