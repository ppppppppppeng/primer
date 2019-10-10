#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
	string line;
	while(getline(cin, line)){
		cout << line << endl;
		cout << line.size() << endl;
	}
	return 0;
}
