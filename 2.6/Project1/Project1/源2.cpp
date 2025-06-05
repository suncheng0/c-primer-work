#include<iostream>
using namespace std;
#include<string>
int main() {
	string s;
	getline(cin, s);
	string s1;
	for (auto ch : s) {
		if (!ispunct(ch)) {
			s1 += ch;
		}
	}
	cout << s1 << endl;
	return 0;
}