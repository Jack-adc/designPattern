/*
https://blog.csdn.net/wuzhekai1985/article/details/6667467
建造者模式
建造者模式的定义将一个复杂对象的构建与它的表示分离，使得同
样的构建过程可以创建不同的表示（DP）。《大话设计模式》举了
一个很好的例子——建造小人，一共需建造6个部分，头部、身体、
左右手、左右脚。与工厂模式不同，建造者模式是在导向者的控制
下一步一步构造产品的。建造小人就是在控制下一步步构造出来的。
创建者模式可以能更精细的控制构建过程，从而能更精细的控制所
得产品的内部结构
https://blog.csdn.net/wuzhekai1985/article/details/6667467

C++虚函数与纯虚函数的区别
虚函数(impure virtual)
　　C++的虚函数主要作用是“运行时多态”，父类中提供虚函数的实现，为子类提供默认的函数实现。
  　子类可以重写父类的虚函数实现子类的特殊化。
    如下就是一个父类中的虚函数：
    class A
    {
        public:
            virtual void ss()
            {
            cout<<"我是基类的虚函数"<<endl;
            }
    };
纯虚函数(pure virtual)
　　C++中包含纯虚函数的类，被称为是“抽象类”。抽象类不能使用new出对象，只有实现了这个纯虚函数的子类才能new出对象。
　　C++中的纯虚函数更像是“只提供申明，没有实现”，是对子类的约束，是“接口继承”。
　　C++中的纯虚函数也是一种“运行时多态”。
　　如下面的类包含纯虚函数，就是“抽象类”：
    class A
    {
        public:
            virtual void out1(string s)=0;  //我是基类的虚函数
    };
虚函数必须要在基类中有实现，即使是空的虚函数也要在基类中实现，派生类中可以不重写这个虚函数，但调用是会调用基类的函数
纯虚函数不在基类中实现，必须在派生类中实现

*/

#include<iostream>
using namespace std;
class Builder
{
public:
    virtual void BuildHead() {}
    virtual void BuildBody() {}
    virtual void BuildLeftArm() {}
    virtual void BuildRightArm() {}
    virtual void BuildLeftLeg() {}
    virtual void BuildRightLeg() {}
};
//构造瘦人
class ThinBuilder : public Builder
{
public:
    void BuildHead() { cout << "build thin body" << endl; }
    void BuildBody() { cout << "build thin head" << endl; }
    void BuildLeftArm() { cout << "build thin leftarm" << endl; }
    void BuildRightArm() { cout << "build thin rightarm" << endl; }
    void BuildLeftLeg() { cout << "build thin leftleg" << endl; }
    void BuildRightLeg() { cout << "build thin rightleg" << endl; }
};
//构造胖人
class FatBuilder : public Builder
{
public:
    void BuildHead() { cout << "build fat body" << endl; }
    void BuildBody() { cout << "build fat head" << endl; }
    void BuildLeftArm() { cout << "build fat leftarm" << endl; }
    void BuildRightArm() { cout << "build fat rightarm" << endl; }
    void BuildLeftLeg() { cout << "build fat leftleg" << endl; }
    void BuildRightLeg() { cout << "build fat rightleg" << endl; }
};
//构造的指挥官
class Director
{
private:
    Builder *m_pBuilder;
public:
    Director(Builder *builder) { m_pBuilder = builder; }
    void Create() {
        m_pBuilder->BuildHead();
        m_pBuilder->BuildBody();
        m_pBuilder->BuildLeftArm();
        m_pBuilder->BuildRightArm();
        m_pBuilder->BuildLeftLeg();
        m_pBuilder->BuildRightLeg();
    }
};

int main()
{
    Director thinDirector(new ThinBuilder());
    thinDirector.Create();
    return 0;
}