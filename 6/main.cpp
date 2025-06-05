#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include<numeric>
using namespace std;

//6.1-17
int func(int val) {
    if (val==1)return 1;
    return val*func(val-1);
}
int func_abs(int val) {
    return abs(val);
}
int func_static() {
    static int static_val = 0;
    int ans=static_val;
    static_val++;
    return ans;
}
void swap_int(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void reset(int& a) {
    a = 0;
}
void swap_yiny(int& a, int& b) {
    int temp=a;
    a=b;
    b=temp;
}
bool haveupper(string& s) {
    for (auto w:s) {
        if (isupper(w)) {
            return true;
        }
    }
    return false;
}
string& tolower(string& s) {
    for (auto& w:s) {
        w=tolower(w);
    }
    return s;
}
//class maxtrix;
//bool compare(maxtrix&,maxtrix&);
//vector<int>::iterator change_val(int,vector<int>::iterator)
void swap_intptr_to(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void swap_intptr_adress(int* &a, int* &b) {
    swap(a,b);
}
string link_string(string &s,string& s2) {
    return s+s2;
}
int add_initializer(initializer_list<int>il) {
    int ans=0;
    ans=accumulate(il.begin(), il.end(),ans);
    return ans;
}
void rec_print(int index,vector<int>& v) {
    if (index==v.size()) {return;}
    cout<<v[index]<<" ";
    rec_print(index+1,v);
}
string (& func1())[10];
//类型别名
typedef string arr[10];
arr& func2();
//尾置返回类型
auto func3()->string (&)[10];
//decltype关键字
string arr2[10];
decltype(arr2) &func4();

int odd[]={1,3,5,7,9};
int even[]={2,4,6,8,10};
decltype(odd)& arrPtr(int i) {
    return (i%2)?odd:even;
}

string make_plural(size_t ctr,const string &word,const string &ending="s") {
    return (ctr>1)?word+ending:word;
}

inline bool isShorter(const string &s1, const string &s2) {
    return s1.size()<s2.size();
}
//#define NDEBUG
// void new_rec_print(int index,vector<int>& v) {
//     if (index==v.size()) {return;}
//     cout<<v[index]<<" ";
//     #ifdef NDEBUG
//     cout<<"vector objsize"<<v.size()<<endl;
//     #endif
//     new_rec_print(index+1,v);
// }
void f(double,int) {
    cout<<"f1"<<endl;
}
void f(int) {
    cout<<"f2"<<endl;
}
void f(int,int) {
    cout<<"f3"<<endl;
}
void f(double,double) {
    cout<<"f4"<<endl;
}

int fun(int,int);
// using elem =int(*)(int,int);
typedef int(*ptr)(int,int);
//vector<elem>v;
vector<ptr>v2;

int add(int a,int b) {
    return a+b;
}
int minus1(int a,int b) {
    return a-b;
}
int cheng(int a,int b) {
    return a*b;
}
int chu(int a,int b) {
    return a/b;
}
int main() {
    using elem =int(*)(int,int);
    vector<elem>v;
    v.push_back(add);
    v.push_back(minus1);
    v.push_back(cheng);
    v.push_back(chu);
    for(int i=0;i<v.size();i++) {
        cout<<v[i](4,2)<<" ";
    }
}

