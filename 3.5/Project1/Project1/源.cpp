#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{	
	//char a[] = { 'a','b','c','\0'};
	//char b[] = { 'd','e','f','\0'};
	//char c[8];
	//strcpy_s(c,a);
	//strcat_s(c, " ");
 //   strcat_s(c,b);
	//cout<<c<<endl;
	//int int_arr[] = { 1,2,3 };
	//vector<int>v(begin(int_arr), end(int_arr));
	//int ary[3];
 //   for (int i = 0; i < v.size(); i++)
 //   {
 //       ary[i] = v[i];
 //   }
 //   for (int i = 0; i < v.size(); i++)
 //   {
 //       cout << ary[i] << endl;
 //   }


	int ia[3][4] = { {1,2,3,4},{5,6,7,8} ,{9,10,11,12} };
	//版本1
	//for (int(&row)[4]:ia) {
	//	for (int& i : row) {
	//		cout<< i << " ";
	//	}
	//	cout<<endl;
	//}
	//版本2
	//for (int i = 0; i < 3; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		cout<< ia[i][j] << " ";
	//	}cout<<endl;
	//}
	//版本3
	//for(int (*p)[4] = ia; p != ia + 3; ++p)
 //   {
 //       for (int *q = *p; q != *p + 4; ++q)
 //       {
 //           cout << *q << " ";
 //       }
 //       cout << endl;
 //   }



	/*using int_array = int[4];*/
	//版本1
	//for (int_array &row:ia) {
	//	for (int& i : row) {
	//		cout<< i << " ";
	//	}
	//	cout<<endl;
	//}
//版本2
//for (int i = 0; i < 3; i++) {
//	for (int j = 0; j < 4; j++) {
//		cout<< ia[i][j] << " ";
//	}cout<<endl;
//}
//版本3
//for(int_array*p = ia; p != ia + 3; ++p)
//   {
//       for (int *q = *p; q != *p + 4; ++q)
//       {
//           cout << *q << " ";
//       }
//       cout << endl;
//   }



		//版本1
	//for (auto &row:ia) {
	//	for (int& i : row) {
	//		cout<< i << " ";
	//	}
	//	cout<<endl;
	//}
	//版本2
	//for (auto i = 0; i < 3; i++) {
	//	for (auto j = 0; j < 4; j++) {
	//		cout<< ia[i][j] << " ";
	//	}cout<<endl;
	//}
	//版本3
	//for(auto p = ia; p != ia + 3; ++p)
 //   {
 //       for (auto *q = *p; q != *p + 4; ++q)
 //       {
 //           cout << *q << " ";
 //       }
 //       cout << endl;
 //   }

	return 0;
}