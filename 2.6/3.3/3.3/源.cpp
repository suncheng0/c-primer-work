#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	//vector<string> text;
	//string word;
	//while (cin >> word) {
	//	for (auto& c : word) {
	//		c=toupper(c);
	//	}
	//	text.push_back(word);
	//}
	//for (auto& s : text) {
	//	cout << s << endl;
	//}
	//vector<string> text = {"diyiduan","","dierduan"};
	//for (auto it = text.begin(); it != text.end() && (*it).empty() != true; it++) {
	//	for (auto& c : *it) {
	//		c=toupper(c);
	//	}
	//	cout << *it << endl;
	//}
	vector<int>v = { 0,1,2,3,4,5,6,7,8,9 };
	for (auto it = v.begin(); it != v.end(); it++) {
		*it = *it * 2;
		cout << *it << endl;
	}
	return 0;
}