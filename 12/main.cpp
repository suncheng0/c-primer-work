#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include<memory>
#include<fstream>
#include<sstream>
#include <string.h>
using namespace std;

// class StrBlob {
// public:
//     typedef std::vector<std::string>::size_type size_type;
//     StrBlob();
//     StrBlob(std::initializer_list<std::string> il);
//     size_type size() const{return data->size();};
//     bool empty() const{return data->empty();};
//     void push_back(const std::string &t){data->push_back(t);};
//     void pop_back() {
//         check(0, "pop_back");
//         data->pop_back();
//     };
//     std::string& front() {
//         check(0,"empty");
//         return data->front();
//     };
//     std::string& back() {
//         check(0,"empty");
//         return data->back();
//     };
//     private:
//     std::shared_ptr<std::vector<std::string>> data;
//     void check(size_type pos, const std::string& msg) const {
//         if (pos >= data->size()) {
//             throw std::out_of_range(msg);
//         }
//     };
// };
//12.6
// vector<int>* new_vector() {
//     vector<int>* v = new vector<int>;
//     return v;
// }
// void duru(vector<int>* &v,istream& is=cin) {
//     istream_iterator<int> is_begin(is),is_end;
//     while (is_begin!=is_end) {
//         (*v).push_back(*is_begin++);
//     }
// }
// void shuchu(vector<int>* &v,ostream& os=cout) {
//     ostream_iterator<int> os_begin(os," ");
//     for_each((*v).begin(),(*v).end(),[&](int &i) {
//        os_begin++=i;
//     });
//     delete v;
// }
//12.7
// shared_ptr<vector<int>> new_vector() {
//     shared_ptr<vector<int>>v(new vector<int>);
//     return v;
// }
// void duru(shared_ptr<vector<int>>v,istream& is=cin) {
//     istream_iterator<int> is_begin(is),is_end;
//     while (is_begin!=is_end) {
//         (*v).push_back(*is_begin++);
//     }
// }
// void shuchu(shared_ptr<vector<int>>v,ostream& os=cout) {
//     ostream_iterator<int> os_begin(os," ");
//     for_each((*v).begin(),(*v).end(),[&](int &i) {
//        os_begin++=i;
//     });
// }
// int main() {
//     auto v = new_vector();
//     duru(v);
//     shuchu(v);
// }
//12.14
// struct connection{};
// struct destination{};
// connection connect(destination* pd) {
//     cout<<"Connection established"<<endl;
//     return connection();
// }
// void disconnect(connection c) {
//     cout<<"Disconnection"<<endl;
// }
// void end_connection(connection *p) {disconnect(*p);}
// void f(destination& pd) {
//     connection c = connect(&pd);
//     //shared_ptr<connection> sp(&c,end_connection);
//     shared_ptr<connection> sp(&c,[&](connection* &p) {
//         disconnect(*p);
//     });
// }
//
// int main() {
//     destination d;
//     f(d);
// }
//12.19
// class StrBlobPtr;
// class StrBlob {//这里维护着一个vector<string>
//     friend class StrBlobPtr;
// public:
//     typedef std::vector<std::string>::size_type size_type;
//     StrBlob():data(new vector<string>){};
//     StrBlob(std::initializer_list<std::string> il);
//     size_type size() const{return data->size();};
//     bool empty() const{return data->empty();};
//     void push_back(const std::string &t){data->push_back(t);};
//     void pop_back() {
//         check(0, "pop_back");
//         data->pop_back();
//     };
//     std::string& front() {
//         check(0,"empty");
//         return data->front();
//     };
//     std::string& back() {
//         check(0,"empty");
//         return data->back();
//     };
//     private:
//     std::shared_ptr<std::vector<std::string>> data;
//     void check(size_type pos, const std::string& msg) const {
//         if (pos >= data->size()) {
//             throw std::out_of_range(msg);
//         }
//     };
// };
// class StrBlobPtr {//这是一个指向StrBlob的指针
//     public:
//     StrBlobPtr():curr(0){}
//     StrBlobPtr(StrBlob& a,size_t sz=0):wptr(a.data),curr(sz){}
//     string& deref() const {//解引用weak_ptr
//         auto ptr = check(curr,"dereference");
//         return (*ptr)[curr];
//     };
//     StrBlobPtr& incr() {
//         check(curr,"increment");
//         ++curr;
//         return *this;
//     };
//
//     private:
//     shared_ptr<std::vector<std::string>> check(size_t i,const std::string &msg) const {
//         auto ret = wptr.lock();
//         if (!ret) {
//             throw runtime_error("no bound");
//         }
//         if (i>=ret->size()) {
//             throw std::out_of_range(msg);
//         }
//         return ret;
//     };
//     std::weak_ptr<std::vector<std::string>> wptr;//指向一个StrBlob的vector<string>
//     size_t curr;//现在在Blob中的下标
// };
// int main() {
//     fstream file("D:/c++primer/12/input.txt");
//     if (!file.is_open()) {
//         cout << "can't open file" << endl;
//         return 0;
//     }
//     StrBlob a;
//     string line;
//     while (getline(file,line)) {
//         string word;
//         istringstream ss(line);
//         //字符串流方案
//         // while (ss>>word) {
//         //     a.push_back(word);
//         // }
//         //输入迭代器方案
//         istream_iterator<string> beg(ss),end;
//         while (beg != end) {
//             a.push_back(*beg++);
//         }
//         // a.push_back(line);
//         // cout << line << endl;
//     }
//     file.close();
//     StrBlobPtr p(a);
//     //
//     while (1) {
//         cout<<p.deref()<<endl;
//         p.incr();
//     }
//     //
// }
//12.23
#include<string.h>
// int main() {
//     const string le = "tdsadads";
//     const string s1 = "AAAAqqdsadadeqfq";
//     char*p=new char[100];
//     strcpy(p,(le+s1).c_str());
//     const char*c1="hello";
//     const char*c2="world";
//     char* n = new char[100];
//     strcpy(n,c1);
//     strcat(n,c2);
//     cout<<n<<endl;
//     cout<<p<<endl;
//     delete[] p;
// }
//12.24
// int main() {
//     string line;
//     cin>>line;
//     char* p=new char[line.length()+1];
//     strcpy(p,line.c_str());
//     cout<<p<<endl;
//     delete[] p;
// }
//12.26
int main() {
    allocator<string> alloc;
    int n=5;
    auto p=alloc.allocate(n);
    string str;
    string*q=p;
    while (cin>>str&&q!=p+n) {
        q=uninitialized_fill_n(q,1,str);
    }
    q=p;
    for(int i=0;i<n;i++) {
        cout<<*q++;
    }
    alloc.deallocate(p,n);
}