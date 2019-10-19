#include <iostream>
#include <memory>

using namespace std;

int main()
{
	auto p1 = make_shared<string>();
	cout << p1.use_count() << endl;
	auto p2 = p1;
	cout << p1.use_count() << " " << p2.use_count() << endl;

	return 0;
}
