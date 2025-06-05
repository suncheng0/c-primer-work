//
// Created by a1735 on 25-5-23.
//

#ifndef MAIN_H
#define MAIN_H
#include <string>
#include<iostream>
#include <memory>
#include <queue>
#include <set>
#include<vector>
using namespace std;
class Quote;
double print_total(std::ostream &os,const Quote &item,size_t n);

class Quote {
public:
    Quote()=default;
    Quote(const string &book,double sales_price):bookNo(book),price(sales_price){}
    std::string isbn() const{return bookNo;}//书籍的编号
    virtual double net_price(std::size_t n) const{return  n*price;}//书籍打折后的实际销售价格
    virtual Quote *clone() const &{return new Quote(*this);}
    virtual Quote *clone() const &&{return new Quote(*this);}

    Quote(const Quote&)=default;
    Quote(Quote&&)=default;
    Quote& operator=(const Quote&)=default;
    Quote& operator=(Quote&&)=default;
    //虚析构函数会阻止自动产生合成移动操作，基类缺少移动操作会导致派生类也没有移动操作 所以我们要自己定义一个
    virtual ~Quote()=default;
private:
    string bookNo;//书籍的编号
protected :
    double price=0.0;//不打折的价格
};
class Disc_quote:public Quote {
public:
    Disc_quote()=default;
    Disc_quote(string &book,double price,size_t qty,double disc):Quote(book,price),quantity(qty),discount(disc){}
    pair<size_t,double> discount_policy() const{return {quantity,discount};}
    double net_price(std::size_t n) const=0;

protected:
    size_t quantity=0;//折扣的购买量
    double discount=0.0;
};
class Bulk_quote : public Disc_quote {//超过一定量就打折
public:
    using Disc_quote::Disc_quote;//重用基类的构造函数
    //Bulk_quote()=default;
    // Bulk_quote(string &book,double price,size_t qty,double disc):Disc_quote(book,price,qty,disc){}
    Bulk_quote* clone() const &{return new Bulk_quote(*this);};
    Bulk_quote* clone() &&{return new Bulk_quote(std::move(*this));};
    double net_price(std::size_t cnt) const override {
        if (cnt >= min_qty) {//超过min_qty的数量就打折
            return cnt * (1-discount)*price;
        }else {
            return cnt * price;
        }
    }//新的折扣政策
private:
    size_t min_qty=0;//折扣政策的最低购买量
    double discount=0.0;//折扣额
};
class Basket {//购物篮
    public:
    //void add_item(const shared_ptr<Quote> &sale){items.insert(sale);}
    void add_item(const Quote &sale) {
        items.insert(shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale) {
        items.insert(shared_ptr<Quote>(move(sale).clone()));
    }
    double total_receipt(ostream &os) const {//把购物篮的内容打印成清单，返回总价格
        double sum=0.0;
        for (auto iter=items.cbegin(); iter!=items.cend();iter=items.upper_bound(*iter)) {
            sum+=print_total(os,**iter,items.count(*iter));
        }
        os<<"Total Receipt: "<<sum<<endl;
        return sum;
    }
    private:
    static bool compare(const shared_ptr<Quote> &lhs,const shared_ptr<Quote> &rhs) {
        return lhs->isbn() < rhs->isbn();
    }
    multiset<shared_ptr<Quote>,decltype(compare)*> items{compare};
};
double print_total(std::ostream &os,const Quote &item,size_t n) {
    //打印总的费用
    double ret = item.net_price(n);
    os<<"ISBN: "<<item.isbn()<<"# sold:"<<n<<"total due "<<ret<<endl;
    return ret;
}
#endif //MAIN_H
