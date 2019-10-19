#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> v1(10, "hi");
//	vector<string> v2("hi");
	vector<int> v3(12);
	vector<string> v4(v1);
	for(auto s : v4)
		cout << s << endl;
	return 0;
}
