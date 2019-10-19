#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	vector<string> v;
	s = "hello";
	v.push_back(s);
	s = "";
	v.push_back(s);
	s = "world";
	v.push_back(s);
	for(auto it = v.begin(); it != v.end() && !it->empty(); ++it)
		for(auto it_s = it->begin(); it_s != it->end(); ++it_s)
			*it_s = toupper(*it_s);
	for(auto x : v)
		cout << x << endl;

	return 0;
}
