#include <iostream>

using namespace std;

int main()
{
	string s("ab2c3d7R4E6");
	string nums("0123456789");
	unsigned long pos = 0;
	while( (pos = s.find_first_of(nums,pos)) != string::npos)
	{
		cout << s[pos] << " ";
		++pos;
	}
	pos = 0;
	while( (pos = s.find_first_not_of(nums,pos)) != string::npos)
	{
		cout << s[pos] << " ";
		++pos;
	}
	cout << endl;

	return 0;
}
