#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v1 = {1, 2, 3, 4, 5},
		v2 = {1, 2, 3, 4, 6 };
	for(auto i : v1)
		cout << i;
	cout  << endl;
	for(auto i : v2)
		cout << i;

	if(v1.size() != v2.size()){
		cout << "v1 != v2" << endl;
		return 0;
	}
	for(int i = 0; i < v1.size(); i++)
		if(v1[i] != v2[i]) {
			cout << "v1 != v2" << endl;
			return 0;
		}

	cout << "v1 == v2" << endl;
	return 0;
}

