#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	vector<int> vec;
	list<int> lst; int i;
	while(cin >> i)
		lst.push_back(i);
//	copy(lst.cbegin(), lst.cend(), vec.begin());

	for(auto x : vec)
		cout << x << " ";
	cout << endl;

	vec.reserve(10);
	fill_n(vec.begin(), 10, 0);
	
	for(auto x : vec)
		cout << x << " ";
	cout << endl;

	return 0;
}
