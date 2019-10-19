#include <iostream>
#include <vector>

using namespace std;

int add(int a, int b)
{
	return a + b;
}
int substract(int a, int b)
{
	return a - b;
}
int multiply(int a, int b)
{
	return a * b;
}
int divide(int a, int b)
{
	if(b)
		return a / b;
	throw runtime_error("donot divide zero");
}

int main()
{
	vector<int (*)(int, int)> v;
	v.push_back(add);
	v.push_back(substract);
	v.push_back(multiply);
	v.push_back(divide);

	for(auto x : v)
		cout <<  x(10 , 0) << endl;
		
	return 0;
}
