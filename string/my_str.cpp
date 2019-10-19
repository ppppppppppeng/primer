#include <iostream>

using namespace std;

class my_str
{
public:
	my_str()
	{
		cout << "direct intalization" << endl;
	}
/*	my_str(char *buf)
	{
		cout << "direct initalization" << endl;
	}
*/	my_str(const char *buf)
	{
		cout << "direct initalization" << endl;
	}
	my_str(const my_str &str)
	{
		cout << "copy initalization" << endl;
	}
};

int main()
{
	my_str str1;
	my_str str2 = str1;
	my_str str3(str1);
	my_str str4 = "aaa";
	my_str str5("aaa");
	my_str str6 = my_str("aaa");
	return 0;
}
