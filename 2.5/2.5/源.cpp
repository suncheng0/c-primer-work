#include<iostream>
using namespace std;
int main() {
	int i = 0, & r = i;
	auto a = r;//int
	const int ci = i, & cr = ci;
	auto b = ci;//int
	auto c = cr;//int
	auto d = &i;//int*
	auto e = &ci;//const int*

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	cout << typeid(e).name() << endl;
	return 0;
}