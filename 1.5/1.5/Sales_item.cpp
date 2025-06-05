//#include"Sales_item.h"
///* 
//*文件重定向
//*输入和输出的文件要放在/1.5/1.5里
//*/
//
//using namespace std;
//int main() {
//	Sales_item curClass,Class;
//	if (cin >> curClass) {
//		int cnt = 1;
//		while (cin >> Class) {
//			if (Class.isbn() == curClass.isbn()) {
//				++cnt;
//			}
//			else {
//				cout << curClass.isbn() << "chu xian le " << cnt << "ci" << endl;
//				curClass = Class;
//				cnt = 1;
//			}
//		}
//		cout<< curClass.isbn() << "chu xian le" << cnt << "ci" << endl;
//	}
//	return 0;
//}