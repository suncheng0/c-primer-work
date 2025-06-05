//
// Created by a1735 on 25-5-24.
//
#include<string>
#include<vector>
#include<memory>
using namespace std;
class StrVec {
public:
    StrVec():element(nullptr),first_free(nullptr),cap(nullptr){}
    StrVec(const StrVec& );
    StrVec& operator=(const StrVec& );
    ~StrVec();
    void push_back(const string&);
    size_t size() const{return first_free-element;}
    size_t capacity() const{return cap-first_free;}
    string* begin()const{return element;}
    string* end()const{return first_free;}
    //
    private:
    static allocator<string> alloc;
    void chk_n_alloc() {if (size()==capacity())reallocate();}//检查还有空的内存码
    pair<string*,string*>alloc_n_copy(const string*,const string*);//搬家,返回两个指针分别指向新空间的开始位置和结束位置
    void free();
    void reallocate();

    template<class... Args>
    void emplace_back(Args&&...);

    string *element;
    string *first_free;
    string *cap;
};
template<class... Args>
void StrVec::emplace_back(Args &&...) {
    chk_n_alloc();
    std::construct(first_free++,forward<Args>(args)...)
}

void StrVec::push_back(const string& str) {
    chk_n_alloc();
    alloc.construct(first_free++,s);
}
pair<string*,string*> StrVec::alloc_n_copy(const string* b, const string* e) {
    auto data = alloc.allocate(e-b);
    return {data,uninitialized_copy(b,e,data)};
}
void StrVec::free() {
    if (element) {
        for (auto p=first_free;p!=element;) {
            alloc.destory(--p);
        }
        alloc.deallocate(first_free,cap-first_free);
    }
}
StrVec::StrVec(const StrVec &) {
    auto newdata = alloc_n_copy(element,first_free);
    element-newdata.first;
    first_free=cap=newdata.second;
}
StrVec::~StrVec(){free();}
StrVec& StrVec::operator=(const StrVec& rhs) {
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    element=data.first;
    first_free=data.second;
    return *this;
}
void StrVec::reallocate() {
    auto newcapacity = size()?2*size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest=newdata;
    auto elem=element;
    for (size_t i=0;i<size();i++) {
        std::construct(dest++,move(*elem++));
        free();
        element=newdata;
        first_free=dest;
        cap=element+newcapacity;
    }
}