/*
其实这才是正宗的工厂模式，简单工厂模式只是一个简单的对创建过程封装。
工厂方法模式在简单工厂模式的基础上增加对工厂的基类抽象，不同的产品
创建采用不同的工厂创建（从工厂的抽象基类派生），这样创建不同的产品
过程就由不同的工厂分工解决：FactoryA专心负责生产ProductA，FactoryB
专心负责生产ProductB，FactoryA和FactoryB之间没有关系；如果到了后期，
如果需要生产ProductC时，我们则可以创建一个FactoryC工厂类，该类专心
负责生产ProductC类产品。
该模式相对于简单工厂模式的优势在于：便于后期产品种类的扩展。
*/

#include <iostream>
using namespace  std;
class product
{
public:
    virtual void show() = 0;
};

class basketBallProduct :public product
{
public:
    void show()
    {
        cout << "我是篮球" << endl;
    }
    basketBallProduct()
    {
        cout << "生成一个篮球" << endl;
    }
};

class footBallProduct :public product
{
public:
    void show()
    {
        cout << "我是足球" << endl;
    }

    footBallProduct()
    {
        cout << "生成一个足球" << endl;
    }
};

class tennisProduct :public product
{
public:
    void show()
    {
        cout << "我是网球" << endl;
    }

    tennisProduct()
    {
        cout << "生成一个网球" << endl;
    }
};

class Factory
{
public:
    virtual product* createProduct() = 0;
};

class basketBallFactory :public Factory
{
public:
    product* createProduct()
    {
        return new basketBallProduct();
    }
};

class footBallFactory :public Factory
{
public:
    product* createProduct()
    {
        return new footBallProduct();
    }
};

class tennisFactory :public Factory
{
public:
    product* createProduct()
    {
        return new tennisProduct();
    }
};

int main()
{
    Factory* factory1 = new basketBallFactory();
    product* basketBall = factory1->createProduct();
    basketBall->show();
    Factory* factory2 = new footBallFactory();
    product* footBall = factory2->createProduct();
    footBall->show();
    Factory* factory3 = new tennisFactory();
    product* tennis = factory3->createProduct();
    tennis->show();
    return 0;
}