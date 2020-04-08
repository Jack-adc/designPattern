/*
https://www.jb51.net/article/55998.htm
Strategy：定义所有支持的算法的公共接口。Context使用这个接口来调用某ConcreteStrategy定义的算法；
ConcreteStrategy：实现Strategy接口的具体算法；
Context：使用一个ConcreteStrategy对象来配置；维护一个对Stategy对象的引用，同时，可以定义一个接口来让Stategy访问它的数据。
*/

#include <iostream>
using namespace std;

class Strategy
{
public:
    virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout << "I am from ConcreteStrategyA." << endl;
    }
};

class ConcreteStrategyB :public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout << "I am from ConcreteStrategyB." << endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    void AlgorithmInterface()
    {
        cout << "I am from ConcreteStrategyC." << endl;
    }
};

class Context
{
public:
    Context(Strategy *pStrategyArg) : pStragegy(pStrategyArg)
    {}

    void ConcreteInterface()
    {
        pStragegy->AlgorithmInterface();
    }
private:
    Strategy *pStragegy;
};

int main()
{
    Strategy *pStrategyA = new ConcreteStrategyA();
    Strategy *pStrategyB = new ConcreteStrategyB();
    Strategy *pStrategyC = new ConcreteStrategyC();

    Context *pContextA = new Context(pStrategyA);
    Context *pContextB = new Context(pStrategyB);
    Context *pContextC = new Context(pStrategyC);

    pContextA->ConcreteInterface();
    pContextB->ConcreteInterface();
    pContextC->ConcreteInterface();

    if (pStrategyA)
        delete pStrategyA;

    if (pStrategyB)
        delete pStrategyB;

    if (pStrategyC)
        delete pStrategyC;

    if (pContextA)
        delete pContextA;

    if (pContextB)
        delete pContextB;

    if (pContextC)
        delete pContextC;
    return 0;
}
