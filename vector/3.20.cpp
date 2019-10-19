#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v;
	int n;
	while(cin >> n)
		v.push_back(n);
	if(v.empty()) {
		cout << "NULL vector" << endl;
		return -1;
	}

	for(unsigned int i = 0; i < v.size() - 1; i++)
		cout << v[i] + v[i + 1] << endl;
	unsigned int i = 0, j = v.size() - 1;
	do{
		cout << v[i] + v[j] << endl;
		i++;
		j--;
	}while(i <= j);




	return 0;
}
