#include <sstream>
#include <fstream>
#include <vector>

using namespace std;

struct PersonInfo
{
	string name;
	vector<string> phones;
};

int main()
{

	ifstream in("phone_number.txt");
	string line, word;
	vector<PersonInfo> people;

	while(getline(in, line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;

		while(record >> word)
			info.phones.push_back(word);

		people.push_back(info);
	}	

	in.close();
	ofstream out("new_phone_number.txt");
	for(const auto &p : people)
	{
		out << p.name << ' ';
		if(p.phones.empty()) continue;
		int i = 0;
		for( ; i != p.phones.size() - 1; i++)
			out << p.phones[i] << ' ';
		out << p.phones[i] << '\n';
	}
	out.close();

	return 0;
}
