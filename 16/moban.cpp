#include <memory>
#include <vector>
#include <string>
#include<iostream>

//
// Created by a1735 on 25-5-23.
//
using namespace std;

template<typename>class BlobPtr;
template<typename>class Blob;
template<typename T>
    bool operator==(const Blob<T>&,const Blob<T>&);
template<typename T>class Blob {
    friend class BlobPtr<T>;
    friend bool operator==(const Blob<T>&,const Blob<T>&);
    public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(initializer_list<T> il);
    size_type size() const{return data->size();}
    template<typename It>
        Blob(It b,It e);
    bool empty() const{return data->empty();}
    void push_back(const T &t){data->push_back(t);}
    void push_back(T &&t){data->push_back(std::move(t));}
    void pop_back();
    T &back();
    T &operator[](size_type i);
private:
    shared_ptr<vector<T>> data;
    void check(size_type i,const string &msg) const;
};
template<typename T>
template<typename It>
Blob<T>::Blob(It b, It e) {
    data = make_shared<vector<T>>(b,e);
}

template<typename T>
void Blob<T>::check(size_type i,const string &msg)const {
    if (i >= data->size()) {
        throw out_of_range(msg);
    }
}
template<typename T>
T &Blob<T>::operator[](size_type i) {
    check(i,"subscript out of range");
    return (*data)[i];
}
template<typename T>
void Blob<T>::pop_back() {
    check(0,"pop on empty Blob");
    data->pop_back();
}
template<typename T>
Blob<T>::Blob() :data(make_shared<vector<T>>()){}
template<typename T>
Blob<T>::Blob(initializer_list<T> il) :data(make_shared<vector<T>>(il)){}

template<typename T>class BlobPtr {
    public:
    BlobPtr():curr(0){}
    BlobPtr(Blob<T>&a,size_t sz=0):wptr(a.data),curr(sz){}
    T &operator*()const {
        auto p=check(curr,"dereference past end");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr &operator++(int);
    BlobPtr &operator--(int);
    private:
    shared_ptr<vector<T>>check(size_t,const string &);
    weak_ptr<vector<T>> wptr;
    size_t curr;
};
template<typename T>
BlobPtr<T> &BlobPtr<T>::operator++(int) {
    BlobPtr<T> ret = *this;
    ++(*this);
    return ret;
}



class DebugDelete {
    public:
    DebugDelete(ostream& s =std::cerr):os(s) {}
    template<typename T>void operator()(T* p)const {
        os<<"deleteing unique_ptr"<<endl;
        delete p;
    }
    private:
    ostream& os;
};


template<typename T>
ostream& print(ostream& os,const T &t) {
    return os<<t;
}
template<typename T,typename... Args>
ostream& print(ostream &os,const T &t,const Args &...rest) {
    os<<t<<", ";
    return print(os,rest...);
}
