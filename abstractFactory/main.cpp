/*
抽象工厂模式对工厂方法模式进行了更加一般化的描述。工厂方法
模式适用于产品种类结构单一的场合，为一类产品提供创建的接口；
而抽象工厂方法适用于产品种类结构多的场合，就是当具有多个抽
象产品类型时，抽象工厂便可以派上用场。

抽象工厂模式更适合实际情况，受生产线所限，让低端工厂生产不
同种类的低端产品，高端工厂生产不同种类的高端产品。
*/

#include <iostream>
using namespace std;

class ProductA
{
public:
    virtual void show() = 0;
};

class ProductA1 : public ProductA
{
public:
    void show()
    {
        cout << "我是A产品 1类" << endl;
    }
};

class ProductA2 :public ProductA
{
public:
    void show()
    {
        cout << "我是A产品2类" << endl;
    }
};

class ProductB
{
public:
    virtual void show() = 0;
};

class ProductB1 : public ProductB
{
public:
    void show()
    {
        cout << "我是B产品1类" << endl;
    }
};

class ProductB2 : public ProductB
{
public:
    void show()
    {
        cout << "我是B产品2类" << endl;
    }
};

class Factory
{
public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class Factory1 :public Factory  // 1号工厂用于生产1类产品
{
public:
    ProductA* createProductA()
    {
        return new ProductA1();
    }
    ProductB* createProductB()
    {
        return new ProductB1();
    }
};

class Factory2 : public Factory // 2号工厂用于生产2号产品
{
public:
    ProductA* createProductA()
    {
        return new ProductA2();
    }
    ProductB* createProductB()
    {
        return new ProductB2();
    }
};

int main()
{

    return 0;
}