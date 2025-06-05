#include<iostream>
using namespace std;
int main() {
	//int i = 3;
	//double d = 1.5;
	//cout << i * static_cast<int>(d);
	//const string* ps;
	//char* pc;
	//void* pv;
	//pv = const_cast<string*>(ps);
	//pv = static_cast<void*>(pv);
	//i = static_cast<int>(*pc);
	//pv = static_cast<void*>(&d);
	//pc = static_cast<char*>(pv);
	int arr[10] = {1,2,3,4,5,6,7,8,9};
	int (*p)[10] = &arr;
	cout << p[0] << endl;
	return 0;
}