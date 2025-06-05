#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include<string>
#include<list>
#include<functional>
#include<fstream>
#include <iterator>
using namespace std;
//10.1
// int num_i() {
//     int num;
//     vector<int> v;
//     while (cin>>num) {
//         v.push_back(num);
//     }
//     return count(v.begin(), v.end(), 3);
// }
//10.2
// int num_i() {
//     string num;
//     list<string> v;
//     while (cin>>num&&num!="Q") {
//         v.push_back(num);
//     }
//     return count(v.begin(), v.end(), "hi");
// }
// int main() {
//     cout<<num_i();
// }
//10.6
// int main() {
//     int n[10];
//     fill_n(n,10,1);
//     for(int i=0;i<10;i++) {
//         cout<<n[i]<<" ";
//     }
// }
//10.9
// bool isShorter(string &a,string &b) {
//     return a.length()<b.length();
// }
// void elimDups(vector<string>&words){
//     sort(words.begin(),words.end(),isShorter);
//     auto it = unique(words.begin(),words.end());
//     words.erase(it,words.end());
// }
// bool long_five(const string& s) {
//     if (s.length() >=5)return true;
//     else return false;
// }
// int main() {
//     vector<string> words={"fox","jumps","over","quick","red","red","slow","the","turtle"};
//     partition(words.begin(),words.end(),long_five);
//     for (auto k:words) {
//         cout<<k<<" ";
//     }
// }
//10.14
// int main() {
//     auto sum_la=[=](const int a,const int b)->int {
//         return a+b;
//     };
//     cout<<sum_la(3,4);
// }
//10.16
// void elimDups(vector<string>&words){
//     sort(words.begin(),words.end());
//     auto it = unique(words.begin(),words.end());
//     words.erase(it,words.end());
// }
// void biggies(vector<string>&words,vector<string>::size_type sz) {
//     elimDups(words);
//     stable_sort(words.begin(),words.end(),[&](const string &a,const string &b) {
//         return a.size() < b.size();
//     });
//     // auto wc=find_if(words.begin(),words.end(),[sz](const string& a) {
//     //     return a.size()>sz;
//     // });
//     auto wc=stable_partition(words.begin(),words.end(),[&](const string &a) {
//         return a.size() < sz;
//     });
//     auto count_num=count_if(words.begin(),words.end(),[&](const string &a) {
//         return a.size() >= sz;
//     });
//     cout<<sz<<" "<<count_num<<endl;
//     for_each(wc,words.end(),[](string &s) {
//         cout<<s<<" ";
//     });
// }
// int main() {
//     vector<string> words={"fox","jumps","over","quick","red","red","slow","the","turtle"};
//     biggies(words,5);
// }
//10.21
// int main() {
//     int n=10;
//     auto to_zero=[&n]() {
//         while (n>0) {
//             n--;
//         }
//         if (n==0) {
//             return true;
//         }
//         return false;
//     };
//     cout<<to_zero();
// }
//10.24
// bool check_size(const string&s,string& sz) {
//     return s.length()<sz.size();
// }
// int main() {
//     vector<string> words={"fox","jumps","over","quick","red","red","slow","the","turtle"};
//     using namespace std::placeholders;
//     string s="abcd";
//     auto n=find_if(words.begin(),words.end(),bind(check_size,s,_1));
//     cout<<*n<<endl;
// }
//10.28
// int main() {
//     vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     deque<int> q;
//     //copy(v.begin(), v.end(), back_inserter(q));
//     //copy(v.begin(), v.end(), front_inserter(q));
//     copy(v.begin(), v.end(), inserter(q, q.begin()));
//     //copy(v.begin(), v.end(), inserter(q, q.end()));
//     //这里inserter的q.begin()只在开始的时候初始化一次
//     for (int i = 0; i < q.size(); i++)
//         cout << q[i] << " ";
// }
//10.29
// int main() {
//     ifstream in("D:/c++primer/9/di.txt");
//     if (in.is_open()) {
//         cout<<"open file"<<endl;
//         istream_iterator<string> is(in);
//         istream_iterator<string> eof;
//         vector<string>words;
//         while (is!=eof) {
//             words.push_back(*is);
//             ++is;
//         }
//         for (auto wo:words) {
//             cout<<wo<<endl;
//         }
//
//     }
// }
//10.30
// int main() {
//     if (1) {
//         cout<<"open file"<<endl;
//         //6 342 5235 15 1 513 51 24 6 6 6 6 6 z
//         istream_iterator<int> is(cin);
//         istream_iterator<int> eof;
//         vector<int>words;
//         while (is!=eof) {
//             words.push_back(*is);
//             ++is;
//         }
//         sort(words.begin(),words.end());
//         ostream_iterator<int> osit(cout," ");
//         unique_copy(words.begin(),words.end(),osit);
//
//     }
// }
//10.33
int main() {
    fstream file("D:/c++primer/9/input.txt");
    fstream file_ji("D:/c++primer/9/ji.txt");
    fstream file_ou("D:/c++primer/9/ou.txt");
    istream_iterator<int> is(file);
    istream_iterator<int> nullis;
    while(is!=nullis) {
        if ((*is)%2==1) {
            ostream_iterator<int> os_ji(file_ji,".");
            os_ji++=*is;
        }else{
            ostream_iterator<int> os_ou(file_ou,".");
            os_ou++=*is;
        }
        is++;
    }
}