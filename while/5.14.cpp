#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	vector<string> v;

	while(cin >> s)
		v.push_back(s);

	unsigned int i = 0;
	unsigned int res = 0;
	while(i != v.size() && res < v.size() - res)
	{
		int cnt = 0;
		do{
			i++;
			cnt++;
		} while(i != v.size() && v[i] == v[i - 1 ]);
		if(res <= cnt){
			s = v[cnt-1];
			res = cnt;
		}
	}
	cout << s  << " " << res << endl;
	
	return 0;
}
