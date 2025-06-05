#include<iostream>
using namespace std;
int main(){
	int a = 0,b=2, *p = &a;
	cout << *p << endl;
	p = &b;
	cout << *p << endl;
	return 0;
}