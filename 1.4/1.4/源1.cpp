#include<iostream>
using namespace std;
int main() {
	//int sum = 0;
	//for (int i = -100; i <= 100; ++i) {
	//	sum += i;
	//}
	//cout << sum;

	//int sum = 0;
	//for (int i = 51; i < 100; i++)sum += i;
	//cout << sum;
	//for (int j = 9; j > 0; j--) {
	//	cout << j << " ";
	//}
	//cout << "��������������" << endl;
	//int a, b;
	//cin >> a >> b;
	//if (a < b) {
	//	for (int i = a + 1; i < b; i++) {
	//		cout << i << endl;
	//	}
	//}
	//else {
	//	for (int i = b + 1; i < a; i++) {
	//		cout << i << endl;
	//	}
	//}
	//int a=0, sum=0;
	//while (cin >> a) {
	//	sum += a;
	//}
	//cout << sum;
	int currVal = 0, val = 0;
	if (cin >> currVal) {
		int cnt = 1;
		while (cin >> val) {
			if (val == currVal) {
				++cnt;
			}
			else {
				cout << "ֵ" << currVal << "������" << cnt << "��" << endl;
				currVal = val;
				cnt = 1;
			}
		}
		cout << "ֵ" << currVal << "������" << cnt << "��" << endl;
	}
	return 0;
}