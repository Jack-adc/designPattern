/*
简单工厂是工厂模式最简单的一种实现，对于不同产品的创建定义一个工厂类，
将产品的类型作为参数传入到工厂的创建函数，根据类型分支选择不同的产品构造函数。
*/
#include <iostream>
using namespace std;

typedef enum ProductTypeTag
{
    E_BASKERBALL     = 0,
    E_FOOTBALL          ,
    E_TENNIS            
}PRODUCTTYPE;

class Product           //产品基类
{
public:
    virtual void createProduct() = 0;
};

class ProduceBasketBall: public Product
{
public:
    void createProduct()
    {
        cout << "生产篮球" << endl;
    }
    ProduceBasketBall()
    {
        cout << "生成一个ProduceBasketBall对象" << endl;
    }
};

class ProduceFootball : public Product
{
public:
    void createProduct()
    {
        cout << "生产足球" << endl;
    }
    ProduceFootball()
    {
        cout << "生成一个ProduceFootball对象" << endl;
    }
};

class ProduceTennis :public Product
{
public:
    void createProduct()
    {
        cout << "生产网球" << endl;
    }
    ProduceTennis()
    {
        cout << "生成一个ProduceTennis对象" << endl;
    }
};

class Factory           // 工厂类
{
public:
    Product* createProduct(PRODUCTTYPE e_Type)
    {
        switch (e_Type)
        {
        case E_BASKERBALL:
            return new ProduceBasketBall();
        case E_FOOTBALL:
            return new ProduceFootball();
        case E_TENNIS:
            return new ProduceTennis();
        default:
            return NULL;
        }
    }
};

int main()
{
    Factory produceCreate;
    Product* basketBall = produceCreate.createProduct(E_BASKERBALL);
    basketBall->createProduct();
    Product* Football = produceCreate.createProduct(E_FOOTBALL);
    Football->createProduct();
    Product* Tennis = produceCreate.createProduct(E_TENNIS);
    Tennis->createProduct();
    if (basketBall)
    {
        delete basketBall;
        basketBall = NULL;
    }
    if (Football)
    {
        delete Football;
        Football = NULL;
    }
    if (Tennis)
    {
        delete Tennis;
        Tennis = NULL;
    }
    return 0;
}