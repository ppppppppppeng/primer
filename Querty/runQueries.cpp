#include <iostream>
#include <fstream>
#include <string>

#include "TextQuery.h"
#include "Query.h"

using namespace std;

void runQueries(ifstream &file)
{

	TextQuery t(file);
	string s1, s2, s3;

	cout << "search for a word : ";
	cin >> s1;
    Query q = Query(s1);
    cout << "\nExecuting query for: " << q << endl;
    auto results = q.eval(t);
    print(cout, results);
    cout << endl;
    
	cout << "search for a word ~ : ";
	cin >> s1;
	auto q2 =  ~Query(s1);
	cout << "\nExecuting query for: " << q2 << endl;
    print(cout, q2.eval(t));
    cout << endl;


	cout << "search for two words |";
	cin >> s1 >> s2;
	q = Query(s1) | Query(s2);
	cout << "\nExecuting query for: " << q << endl;
    results = q.eval(t);
    print(cout, results);
    cout << endl;

	cout << "search for three words & |";
	cin >> s1 >> s2 >> s3;
	q =  Query(s1) & Query(s2) | Query(s3);
	cout << "\nExecuting query for: " << q << endl;
    results = q.eval(t);
    print(cout, results);
    cout << endl;
 


}



int main()
{
	ifstream fin("storyDataFile");

	runQueries(fin);
	return 0;
}
