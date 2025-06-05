#include<iostream>
#include <vector>
#include<string>
#include<unordered_map>
using namespace std;
//5.4
// int main() {
//     //5.4
//     int sum = 0,val=0;
//     while (val<=10)sum=sum+val,++val;
// }
//5.5
// int main() {
//     const vector<string> scores = {"F","D","C","B","A","A++"};
//     int grade;
//     cin>>grade;
//     string lettergrade;
//     if (grade<60) {
//         lettergrade =scores[0] ;
//     }else {
//         lettergrade =scores[(grade-50)/10] ;
//         if (lettergrade != "A++")
//             if (grade%10>7) lettergrade += '+' ;
//             else if (grade%10<3) lettergrade += '-' ;
//     }
//     cout<<lettergrade;
// }
//5.6
// int main() {
//     char ch;
//     int yuanyin_num=0;
//     int kongge_num=0;
//     int zhibiao_num=0;
//     int huanhang_num=0;
//     cout<<"Enter any character:";
//     while (cin.get(ch)&&ch!='#') {
// //cin>>会自动跳过“空白字符”，比如空格 换行 制表符 所以这里要用cin.get()
//         if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'
//             ||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') {
//             yuanyin_num++;
//         }else if (ch==' ') {
//             kongge_num++;
//         }else if (ch=='\n') {
//             huanhang_num++;
//         }else if (ch=='\t') {
//             zhibiao_num++;
//         }
//     }
//     cout<<"yuanyin num"<<yuanyin_num<<endl;
//     cout<<"kongge num"<<kongge_num<<endl;
//     cout<<"huanhang num"<<huanhang_num<<endl;
//     cout<<"zhibiao num"<<zhibiao_num<<endl;
//}
// int main() {
//     char ch=' ';
//     int ffnum=0,flnum=0,finum=0;
//     while(cin>>ch&&ch!='#') {
//         switch(ch) {
//             case 'f':
//                 cin>>ch;
//                 switch(ch) {
//                     case 'f':
//                         ffnum++;
//                         break;
//                     case 'l':
//                         flnum++;
//                         break;
//                     case 'i':
//                         finum++;
//                         break;
//                     default:
//                         break;
//                 }
//             default:
//                 break;
//         }
//     }
//     cout<<"ffnum:"<<ffnum<<endl;
//     cout<<"flnum:"<<flnum<<endl;
//     cout<<"finum:"<<finum<<endl;
// }
//5.14
// int main() {
//     string word;
//     unordered_map<string,int> map;
//     int maxn=0;
//     string maxw=" ";
//     while (cin >> word&&word!="#") {
//         map[word]++;
//         if (map[word]>maxn) {maxn=map[word];maxw=word;}
//     }
//     cout<<maxn<<" "<<maxw;
// }
//5.17
// int main() {
//     vector<int> v={0,1,1,2};
//     vector<int> v2={0,1,1,2,3,5,8};
//     vector<int>* p_small =(v.size()<v2.size())?&v:&v2;
//     vector<int>* p_large =(v.size()>=v2.size())?&v:&v2;
//     bool ans=true;
//     for (int i=0;i<p_small->size();i++) {
//         if (p_small->at(i)!=p_large->at(i)) {
//             ans=false;
//         }
//     }
//     cout<<ans<<endl;
// }
//5.19
// int main() {
//     string s;
//     string t;
//     char c;
//     do {
//         cout<<"Enter string1:";
//         cin>>s;
//         cout<<"\nEnter string2:";
//         cin>>t;
//         if(s.length()>t.length())
//             cout<<"\n"<<t<<"";
//         else
//             cout<<"\n"<<s<<"\n";
//         cout<<"如果想退出，请输入Q";
//         cin>>c;
//     }while (c!='Q');
// }
//5.20
// int main() {
//     string curs;
//     string pres=" ";
//     bool bi=true;
//     while (cin >> curs&&curs!="Q") {
//         if (curs==pres&&isupper(curs[0])) {
//             bi=false;
//             cout<<curs<<"  is chongfu word"<<endl;
//             break;
//         }else {
//             pres=curs;
//         }
//     }
//     if (bi==true) {
//         cout<<"no chongfu word"<<endl;
//     }
// }
//5.23
// int main() {
//     begin:
//     try {
//         int a,b;
//         cout<<"Enter two number:";
//         cin>>a>>b;
//         if (b==0) {
//             throw runtime_error("the second digit should not be zero");
//         }
//             int c=a/b;
//         cout<<c<<endl;
//     }catch (runtime_error err){
//         cout<<err.what()<<endl;
//         cout<<"\n do you want to do next time? y/n"<<endl;
//         char ch;
//         cin>>ch;
//         if (ch=='y' || ch=='Y') {
//             goto begin;
//         }else {
//             return 0;
//         }
//     }
// }