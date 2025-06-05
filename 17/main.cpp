//
//
// //书店程序
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include<tuple>
// #include<numeric>
// #include<algorithm>
// #include <bits/atomic_base.h>
// using namespace std;
// class Sales_data;
// Sales_data add(const Sales_data&,const Sales_data&);
// ostream& &print(ostream&, const Sales_data&);
// istream &read(istream&, Sales_data&);
// Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
// bool operator==(const Sales_data& lhs, const Sales_data& rhs) ;
// bool compareIsbn(const Sales_data&  l, const Sales_data&  r) ;
// ostream& operator<<(ostream &os,const Sales_data& item);
// istream& operator>>(istream &is,Sales_data& item);
// class Sales_data {
//     friend ostream & operator<<(ostream &os,const Sales_data& item);
//     friend istream & operator>>(istream &is,Sales_data& item);
//     friend istream &read(istream&, Sales_data&);
//     friend ostream& &print(ostream&, const Sales_data&);
//     friend Sales_data add(const Sales_data&, const Sales_data&);
//     friend Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs);
//     friend bool compareIsbn(const Sales_data&  l, const Sales_data&  r);
//     friend bool operator==(const Sales_data& lhs, const Sales_data& rhs) ;
// public:
//     string isbn() const { return bookNo; }//书的编号
//     Sales_data& combine(const Sales_data&);
//     Sales_data()=default;
//     Sales_data(const string&s):bookNo(s){}
//     Sales_data(string s,unsigned n,double p):bookNo(s),units_sold(n),revenue(p*n){}
//     Sales_data(istream&);
//
//     Sales_data& operator+=(const Sales_data&);
//
//     private:
//     double avg_price() const ;
//     string bookNo;
//     unsigned units_sold = 0;//书的销售数量
//     double revenue = 0.0;//总销售收入
// };
// ostream& operator<<(ostream &os,const Sales_data& item) {
//     os<<item.isbn()<<" "<<item.units_sold<<" "<<item.revenue<<" "<<item.avg_price();
//     return os;
// }
// istream& operator>>(istream &is,Sales_data &item) {
//     double price;
//     is>>item.bookNo>>item.units_sold>>price;
//     if (is)
//         item.revenue=item.units_sold*price;
//     else
//         item=Sales_data();
//     return is;
// };
// Sales_data& Sales_data::operator+=(const Sales_data& rhs) {
//     units_sold=units_sold+rhs.units_sold;
//     revenue=revenue+rhs.revenue;
//     return *this;
// }
// bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
//     return lhs.isbn()==rhs.isbn() && lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue;
// }
// bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
//     return !(lhs == rhs);
// }
// Sales_data operator+(const Sales_data& lhs, const Sales_data& rhs) {
//     Sales_data sum=lhs;
//     sum+=rhs;
//     return sum;
// }
// bool compareIsbn(const Sales_data&  lhs, const Sales_data&  rhs) {
//     return lhs.isbn()<rhs.isbn();
// }
// double Sales_data::avg_price()const {//平均每本书的销售价格
//     if (units_sold) {
//         return revenue / units_sold;
//     }else {
//         return 0.0;
//     }
// }
// Sales_data::Sales_data(istream &is) {
//     read(is,*this);
// }
// Sales_data& Sales_data::combine(const Sales_data& rhs) {//合并两笔账单
//     units_sold = units_sold + rhs.units_sold;
//     revenue = revenue + rhs.revenue;
//     return *this;
// }
// istream &read(istream& is, Sales_data& item) {//读入一条账单
//     double price=0;
//     is >> item.bookNo >> item.units_sold >> price;
//     item.revenue = price*item.units_sold;
//     return is;
// }
// ostream& print(ostream& os, const Sales_data& item) {//打印一张账单
//     os << item.isbn() << " " << item.units_sold << " "
//     << item.revenue<<" "<<item.avg_price();
//     return os;
// }
// Sales_data add(const Sales_data& rhs,const Sales_data& lhs) {
//     Sales_data sum=lhs;
//     sum.combine(rhs);
//     return sum;
// }
//
// //一个Sale_data是一种书籍的账单
// //一个vector<Sales_dara>表示一个书店的所有种类书籍的账单
// //vector<vector<Sales_data>>表示多个书店
// vector<vector<Sales_data>> files;
// typedef tuple<vector<Sales_data>::size_type,vector<Sales_data>::const_iterator,vector<Sales_data>::const_iterator>matches;//书店号  迭代器 迭代器
// vector<matches>
//     findBook(const vector<vector<Sales_data>>& files,const string& book) {
//     vector<matches>ret; // 一个matches表示一家书店
//     for (auto it=files.cbegin();it!=files.cend();++it) {//遍历每一家书店
//         auto found =equal_range(it->cbegin(),it->cend(),book,compareIsbn);
//         if (found.first!=found.second) {//找到了编号是"book"的书籍账单
//             ret.push_back(make_tuple(it-files.cbegin(),found.first,found.second));
//         }
//     }
//     return ret;
// }
// //打印汇总信息
// void reporResults(istream& in,ostream& os,const vector<vector<Sales_data>>& files) {
//     string s;//要查找的书
//     while (in>>s) {
//         auto trans=findBook(files,s);
//         if (trans.empty()) {//没有书店买这种编号是s的书
//             cout<<"No such book in any stores"<<s<<endl;
//             continue;
//         }
//         for (const auto &store:trans)//对有卖这种书的每家书店
//             os<<"store "<<get<0>(store)<<" sales"<<accumulate(get<1>(store),get<2>(store),Sales_data(s))<<endl;
//      }
// }
//
// int main() {
//     return 0;
// }

//17.1
#include<tuple>
#include<iostream>
#include<string>
#include<vector>
// using namespace std;
// int main() {
//     // tuple<int,int,int> t(10,20,30);
//     // cout<<get<0>(t)<<endl;
//     // cout<<get<1>(t)<<endl;
//     // cout<<get<2>(t)<<endl;
//     tuple<string,vector<string>,pair<string,int>> s
//     ("hello",{"my","name","is"},{"sunche",1});
//     cout<<get<0>(s)<<endl;
// }
//7.10
// #include<bitset>
// using namespace std;
// int main() {
//     // bitset<22> b;
//     // vector<int> v{1,2,3,5,8,13,21};
//     // for (auto i : v) {
//     //     b.set(i-1);
//     // }
//     // cout<<b<<endl;
//     //7.11
//     vector<bitset<10>>(100);
// }
//正则表达式
#include<regex>
using namespace std;
//字符串匹配regex_match
void testMatch() {
    //1 判断用户名是否是字符串
    //char userName[50];
    // while (1) {
    //     cout<<"Enter username:";
    //     cin>>userName;
    //     //构建正则对象
    //     regex reg("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");
    //     //调用regex_match函数
    //     bool result = regex_match(userName, reg);
    //     if(result) {
    //         cout<<userName<<"  right"<<endl;
    //         break;
    //     }else {
    //         cout<<userName<<" try again"<<endl;
    //     }
    // }
    //2 完全匹配——区分大小写
    // string str={"Iloveyou1314"};
    // regex reg("[a-z0-9]+");
    // bool result=regex_match(str,reg);
    // if(result==true) {
    //     cout<<"wanquan pipei"<<endl;
    // }else {
    //     cout<<"no pipei"<<endl;
    // }
    // string str={"iloveyou1314"};
    // regex reg("[a-z0-9]+");
    // bool result=regex_match(str,reg);
    // if(result==true) {
    //     cout<<"wanquan pipei"<<endl;
    // }
    //3 忽略大小写——regex_constants::icase
    // string str={"IloVEyou1314"};
    // regex reg("[a-z0-9]+",regex_constants::icase);
    // bool result=regex_match(str,reg);
    // if(result==true) {
    //     cout<<"wanquan pipei"<<endl;
    // }else {
    //     cout<<"no pipei"<<endl;
    // }
}
//字符串捕获（搜索）regex_search
void testSearch() {
    string s = "ILoveyou13you14";
    smatch result;//是一个类，表示匹配的结果
    //只能做一次匹配
    // bool flag=regex_search(s,result,regex("\\d+"));
    // if(flag) {
    //     cout<<"size: "<<result.size()<<endl;
    //     //匹配到的字符串
    //     cout<<result.str()<<endl;
    //     //结果的上下文
    //     cout<<result.prefix()<<endl;
    //     cout<<result.suffix()<<endl;
    // }
    //用迭代器sregex_iterator可以实现多次匹配
    // regex regex("\\d+");
    // sregex_iterator pos(s.begin(), s.end(), regex);
    // sregex_iterator end;
    // while (pos!=end) {
    //     cout << pos->str() << " ";
    //     pos++;
    // }
    //sregex_token_iterator
    //flag: 0 所有匹配的
    //flag: -1 存储的所有的不匹配的
    s="I13love14you520";
    regex regx("\\d+");
    sregex_token_iterator it(s.begin(), s.end(), regx, 0);
    sregex_token_iterator end;
    while (it!=end) {
        cout<<it->str()<<endl;
        it++;
    }
}
//字符串的替换
void testReplace() {
    string s = "ILoveyou13you14me";
    regex regx("\\d+");
    // cout<<regex_replace(s,regx,"AAA");
    //特定条件
    //cout<<regex_replace(s,regx,"AAA",regex_constants::format_first_only);
    cout<<regex_replace(s,regx,"AAA",regex_constants::format_no_copy);

}
int main() {
    //testMatch();
    //testSearch();
    //testReplace();
    enum Dir{left,right,up,down};
    cout<<left<<right<<up<<down<<endl;

}