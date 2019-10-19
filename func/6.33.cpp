#include <iostream>
#include <vector>

using namespace std;

int printV(vector<int> &v, int i)
{
	if(i != v.size())
	{
		cout << v[i] << " ";
		return printV(v, (i + 1));
	}
	else
	{
		cout << endl;
		return i;
	}
	
}

int main()
{
	vector<int> v;
	int a;
	while(cin >> a)
		v.push_back(a);
	cout << printV(v, 0) << endl;

	return 0;
}
