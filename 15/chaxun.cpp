//
// Created by a1735 on 25-5-23.
//
#include"chaxun.h"

#include <algorithm>
//读取输入文件  建立单词到行号的映射
TextQuery::TextQuery(ifstream & is):file(new vector<string>) {
    string text;
    while (getline(is, text)) {//读取一行 放到text里
        file->push_back(text);//file是一个智能指针 指向一个vector<string> 类型
        int n = file->size()-1;
        istringstream line(text);
        string word;
        while (line>>word) {
            auto &lines = wm[word];
            //lines是一个指针，是word这一个单词对应的shared_ptr<set> 指向的这个set里记录了单词对应出现的所有的行号
            if (!lines) {//这是这个单词第一次出现
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}
//query函数接受一个要查询的单词，这个函数定位对应的行号
//如果没有找到 返回局部静态对象  是一个指向空set的shared_ptr
QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);//找到这个要查询的单词对应的set
    if (loc == wm.end()) {
        return QueryResult(sought,nodata,file);
    }else {
        return QueryResult(sought,loc->second,file);
    }
}
QueryResult OrQuery::eval(const TextQuery &text) const {
    auto right=rhs.eval(text),left=lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(),left.end());
    ret_lines->insert(right.begin(),right.end());
    return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult AndQuery::eval(const TextQuery &text) const {
    auto right=rhs.eval(text),left=lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines,ret_lines->begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult NotQuery::eval(const TextQuery &text) const {
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin();
    auto end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n=0;n!=sz;++n) {
        if (beg==end||*beg!=n) {
            ret_lines->insert(n);
        }
        else if (beg!=end) {
            ++beg;
        }
    }
    return QueryResult(rep(),ret_lines,result.get_file());
}

