#include <iostream>

using std::cin; using std::cout; using std::endl;
using std::string;

int main()
{
	string word;
	while(cin >> word){
		cout << word << endl;
		cout << word.size() << endl;
	}
	return 0;
}
