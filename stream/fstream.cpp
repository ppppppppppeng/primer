#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
	ifstream in("text.txt");
	ofstream out("copy.txt");
	if(!in)
		return 0;
	vector<string> v;
	string s;

	while(getline(in, s))
		v.push_back(s);

	for(const auto &x : v)
		out << x << '\n';




	return 0;
}
