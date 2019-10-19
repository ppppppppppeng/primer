#include <iostream>

using namespace std;

int main()
{
	constexpr size_t rowCnt = 3, colCnt = 4;
	int arr[rowCnt][colCnt];
	for(size_t i = 0; i != rowCnt; i++)
		for(size_t j = 0; j != colCnt; j++)
			arr[i][j] = i * colCnt + j;
	for(const auto &row : arr){
		for(auto col : row)
			cout << col <<  " " ;
		cout << endl;
	}

	for(int (*p)[colCnt] = arr; p != arr + 3; p++){
		for(int * q = *p; q != *p + 4; q++)
			cout << *q << " ";
		cout << endl;
	}

	for(auto p = begin(arr); p != end(arr); p++){
		for(auto q = begin(*p); q != end(*p); q++)
			cout << *q << " ";
		cout << endl;
	}

	using array = int[colCnt];
	for(array *p = arr; p != arr + 3; p++){
		for(int * q = *p; q != *p + 4; q++)
			cout << *q << " ";
		cout << endl;	
	}
	return 0;
}
