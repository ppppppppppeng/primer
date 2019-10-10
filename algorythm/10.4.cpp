#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	vector<double> v;
	v.push_back(1.1);
	v.push_back(2.2);

	cout << accumulate(v.cbegin(), v.cend(), 0) << endl;


	return 0;
}
