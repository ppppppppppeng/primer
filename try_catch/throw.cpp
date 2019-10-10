#include <iostream>

using namespace std;

int main()
{
	int n, m;
	while(cin >> n >> m)
	{
		try{
			if(m == 0)
				throw runtime_error("0 cannot be a divisor");
			cout << n/m << endl;
		} catch(runtime_error err)
		{
			cout <<err.what()
			<< "\nTry Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if(!cin || c == 'n')
				break;

		}
	}

	return 0;
}
