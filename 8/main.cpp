#include <format>
#include <iostream>
#include <vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
//8.1
istream& func(istream& is) {
    string s;
    while (is>>s) {
        cout<<s;
    }
    is.clear();
    return is;
}
//8.4
// int main() {
//     fstream file;
//     vector<string> v;
//     file.open("D:/c++primer/8/test.txt", ios::in);
//     if (file.is_open()) {
//         string s;
//         while (getline(file, s, '\n')) {
//             v.push_back(s);
//         }
//     }else {
//         cout<<"file not open !"<<endl;
//     }
//     file.close();
//     for (auto it = v.begin(); it != v.end(); it++) {
//         cout << *it << endl;
//     }
// }
//8.5
// int main() {
//     fstream file;
//     vector<string> v;
//     file.open("D:/c++primer/8/test.txt", ios::in);
//     if (file.is_open()) {
//         string s;
//         while (getline(file, s, ' ')) {
//             v.push_back(s);
//         }
//     }else {
//         cout<<"file not open !"<<endl;
//     }
//     file.close();
//     for (auto it = v.begin(); it != v.end(); it++) {
//         cout << *it << endl;
//     }
// }
//8.9
// istream& func(ifstream& is) {
//     string s;
//     while (is>>s&&!is.eof()) {
//         if (is.bad())
//             throw runtime_error("bad input");
//         if (is.fail()) {
//             cerr<<"bad input,please try again";
//             is.clear();//清除错误标志
//             is.ignore(100,'\0');//跳过缓冲区的剩余内容，直到遇到空字符
//             continue;
//         }
//         cout<<s<<" ";
//     }
//     is.clear();
//     return is;
// }
// int main() {
//     ostringstream msg;
//     msg<<"这是字符串流"<<endl;
//     istringstream is(msg.str());//把msg字符串流中的数据输入到is里面
//     func(is);//打印is输入字符串流中的内容
//     return 0;
// }
//8.10
// int main() {
//     ifstream file;
//     file.open("D:/c++primer/8/test.txt");
//     if (!file.is_open()) {
//         cout<<"Can't open file";
//     }
//     string s;
//     vector<string> v;
//     while (getline(file,s)) {
//         v.push_back(s);
//     }
//     file.close();
//     for (auto it = v.begin(); it != v.end(); it++) {
//        istringstream is(it->c_str());
//         string word;
//         while (is>>word) {
//             cout<<word<<endl;
//         }
//     }
//     return 0;
// }
//8.11
// struct PersonInfo {
//     string name;
//     vector<string> phone;
// };
// bool valid(const string& s) {
//     if (s=="111")
//         return false;
//     else
//         return true;
// }
// int main() {
//     //
//     string line,word;
//     vector<PersonInfo> people;
//     istringstream record;
//     while (getline(cin,line)&&line!="") {
//         PersonInfo Info;
//         record.clear();
//         record.str(line);
//         record>>Info.name;
//         while (record>>word) {
//             Info.phone.push_back(word);
//         }
//         people.push_back(Info);
//     }
//     for (const auto &entry:people) {
//         ostringstream formatted,badNums;
//         for (const auto &nums:entry.phone) {
//             if (!valid(nums)) {
//                 badNums<<" "<<nums;
//             }else{
//                 formatted<<" "<<nums;
//             }
//         }
//         if (badNums.str()=="") {
//             cout<<entry.name<<" "<<formatted.str();
//             cout<<endl;
//         }else {
//             cout<<"thie person's phone have some problem"<<endl;
//             cout<<entry.name<<" "<<badNums.str()<<endl;
//         }
//     }
// }
//8.13
struct PersonInfo {
    string name;
    vector<string> phone;
};
bool valid(const string& s) {
    if (s=="111")
        return false;
    else
        return true;
}
int main() {
    //
    ifstream f;
    f.open("D:/c++primer/8/dianhua.txt");
    if (!f.is_open()) {
        cout << "Can't open file";
        return 0;
    }
    string line,word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(f,line)) {
        PersonInfo Info;
        record.clear();
        record.str(line);
        record>>Info.name;
        while (record>>word) {
            Info.phone.push_back(word);
        }
        people.push_back(Info);
    }
    for (const auto &entry:people) {
        ostringstream formatted,badNums;
        for (const auto &nums:entry.phone) {
            if (!valid(nums)) {
                badNums<<" "<<nums;
            }else{
                formatted<<" "<<nums;
            }
        }
        if (badNums.str()=="") {
            cout<<entry.name<<" "<<formatted.str();
            cout<<endl;
        }else {
            cout<<"thie person's phone have some problem"<<endl;
            cout<<entry.name<<" "<<badNums.str()<<endl;
        }
    }
    f.close();
}