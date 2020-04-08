/*
模板模式
模板模式是一种行为型模式，它用来定义一个算法的框架，而将一些步骤延迟到子类中。
模板方法模式使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤
使用场景：多个类里面使用相同的逻辑
*/

#include<iostream>
using namespace std;

class OnlineShopping
{
public:
    void shopping()
    {
        selectProduct();
        addToCart();
        account();
    }

    virtual void selectProduct() = 0;
    virtual void addToCart() = 0;
    virtual void account() = 0;
};

class shoppingFromTaobao : public OnlineShopping
{
public:
    void selectProduct()
    {
        cout << "在淘宝上选择商品"<<endl;
    }
    void addToCart()
    {
        cout << "在淘宝上添加购物车" << endl;
    }
    void account()
    {
        cout << "在淘宝上支付" << endl;
    }
};

class shoppingOnJD : public OnlineShopping
{
public:
    void selectProduct()
    {
        cout << "在京东上选择商品" << endl;
    }
    void addToCart()
    {
        cout << "在京东上添加购物车" << endl;
    }
    void account()
    {
        cout << "在京东上支付" << endl;
    }
};

int main()
{
    OnlineShopping* shop = new shoppingOnJD();
    shop->shopping();
    delete shop;
    shop = new shoppingFromTaobao();
    shop->shopping();
    return 0;
}