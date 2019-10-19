#include "include.h"
#include "Message.h"
#include "Folder.h"

using namespace std;

int main()
{
	vector<Message> vm;
	string s;
	while(cin >> s)
		vm.push_back(Message(s));
	vector<Folder> vf;
	
	for(auto &m : vm)
		vf.push_back(m);
	for(auto &f : vf)
		f.print();
	cout << endl;


	return 0;
}
