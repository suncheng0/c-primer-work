#include<iostream>
#include<string>
#include<vector>
using namespace std;
//p21
//Sales_item是表示一本书的总销售额，售出册数和平均售价
//
class Person {
public:
    Person(string n,string a):name(n),address(a) {}
    Person()=default;
    string get_name() const{
        return name;
    }
    string get_adress() const {
        return address;
    }
    ostream& print(ostream& os,Person& p){
        cout<<"Name: "<<p.get_name()
        <<"  Address: "<<p.get_adress();
        return os;
    }
    istream& read(istream& is,Person& p) {
        cin>>p.name>>p.address;
        return is;
    }
private:
    string name;
    string address;
};

//

class Window_mgr {
    public:
    void clear();
};
class Screen {
    friend void Window_mgr::clear();
    typedef string::size_type pos;
public:
    Screen()=default;
    Screen(int ht,int wd):height(ht),width(wd),contents(ht*wd,' '){}
    Screen(int ht,int wd,char c):height(ht),width(wd),contents(ht*wd,c){}
private:
    pos height=0,width=0;
    pos cursor=0;
    string contents;
public:
    Screen& move(int r,int c) {
        cursor=r*width+c;
        return *this;
    }
    Screen& set(char ch) {
        contents[cursor]=ch;
        return *this;
    }
    Screen& set(int r,int c,char ch) {
        contents[r*width+c]=ch;
        return *this;
    }
    Screen& display(ostream& os) {
        os<<contents;
        return *this;
    }
    pos size() const {return height*width;}
};
void Window_mgr::clear() {
    Screen A(10,10,'X');
    cout<<"before:"<<A.contents<<endl;
    A.contents.clear();
    cout<<"next:"<<A.contents<<endl;
}

//
class Y;
class X {
    Y* ptry=nullptr;
};
class Y {
    X objX;
};


int main() {
    Window_mgr w;
    w.clear();
}