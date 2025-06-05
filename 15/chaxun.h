//
// Created by a1735 on 25-5-23.
//

#ifndef CHAXUN_H
#define CHAXUN_H
#include<fstream>
#include<iostream>
#include <map>
#include<set>
#include <memory>
#include <string>
#include<vector>
#include<sstream>
using namespace std;
std::string make_plural(size_t ctr, const std::string &word,const std::string &ending = "s");

//文本查询程序
class QueryResult;
class TextQuery {
    public:
    using line_no = vector<string>::size_type;//
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
    private:
    shared_ptr<vector<string>> file;//输入文件  这个智能指针指向vector
    map<string, shared_ptr<set<line_no>>>wm;//string到shared_ptr<set>的map 每个单词对应一个指针 这个指针指向的set里记录了这个单词都在哪几行出现了
};
class QueryResult {
    using line_no = vector<string>::size_type;
    friend ostream& print(ostream&,const QueryResult&);
public:
    shared_ptr<vector<string>>& get_file() {
        return files;
    }
    QueryResult(string s,shared_ptr<set<line_no>>p,shared_ptr<vector<string>>f):sought(s),lines(p),files(f) {
        begin1=lines->begin();
        end1=lines->end();
    }
    set<line_no>::iterator& begin() {return begin1;}
    set<line_no>::iterator& end() {return end1;}
private:
    set<line_no>::iterator begin1,end1;
    string sought;//要查询的单词
    shared_ptr<vector<string>> files;//输入文件
    shared_ptr<set<line_no>>lines;//指向单词出现行号的set


};
void runQueries(ifstream &infile) {
    TextQuery tq(infile);//建立查询map
    while (1) {
        cout << "Enter query word:   or q to quit";
        string s;
        if (!(cin>>s)||s=="q")break;
        print(cout,tq.query(s))<<endl;
    }
};
ostream& print(ostream &os, const QueryResult &qr) {
    os<<qr.sought<<" occurs "<<qr.lines->size()<<" "
    <<make_plural(qr.lines->size(),"time","s")<<endl;
    for (auto num:*qr.lines) {
        os<<"\t(line "<<num+1<<") "<<*(qr.files->begin()+num)<<endl;
    }
    return os;
}
std::string make_plural(size_t ctr, const std::string &word,const std::string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

//文本查询程序拓展
class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};
class Query {//这是一个接口
    friend Query operator~(const Query &);
    friend Query operator|(const Query &,const Query &);
    friend Query operator~(const Query &,const Query &);
    public:
    inline Query(const string &s);
    QueryResult eval(const TextQuery&t) const{return q->eval(t);};
    string rep() const {return q->rep();}
    private:
    Query(shared_ptr<Query_base>query):q(query){}
    shared_ptr<Query_base> q;
};
class WordQuery:public Query_base {
    friend class Query;
    WordQuery(const string &s):query_word(s){}
    QueryResult eval(const TextQuery&t) const {return t.query(query_word);}
    string rep()const{return query_word;}
    string query_word;
};
inline Query::Query(const string &s):q(new WordQuery(s)) {};
class NotQuery:public Query_base {
    friend Query operator~(const Query &);
    NotQuery(const Query &q):query(q){}
    string rep()const {return "~("+query.rep()+")";}
    QueryResult eval(const TextQuery&)const;
    Query query;
};
inline Query operator~(const Query &operand) {
    return shared_ptr<Query_base>(new NotQuery(operand));
}
class BinaryQuery:public Query_base{
protected:
    BinaryQuery(const Query &l,const Query &r,string s):lhs(l),rhs(r),opSym(s){}
    string rep()const {return "("+lhs.rep()+" "+opSym+" "+rhs.rep()+")";}
    Query lhs,rhs;
    string opSym;
};
class AndQuery:public BinaryQuery {
    friend Query operator&(const Query &,const Query &);
    AndQuery(const Query &left,const Query& right):BinaryQuery(left,right,"&"){}
    QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query &lhs,const Query &rhs) {
    return shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
class OrQuery:public BinaryQuery {
    friend Query operator|(const Query &,const Query &);
    OrQuery(const Query &left,const Query& right):BinaryQuery(left,right,"&"){}
    QueryResult eval(const TextQuery&)const;

};
inline Query operator|(const Query &lhs, const Query &rhs){
    return shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

#endif //CHAXUN_H
