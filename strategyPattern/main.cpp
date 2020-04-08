/*
https://www.jb51.net/article/55998.htm
Strategy����������֧�ֵ��㷨�Ĺ����ӿڡ�Contextʹ������ӿ�������ĳConcreteStrategy������㷨��
ConcreteStrategy��ʵ��Strategy�ӿڵľ����㷨��
Context��ʹ��һ��ConcreteStrategy���������ã�ά��һ����Stategy��������ã�ͬʱ�����Զ���һ���ӿ�����Stategy�����������ݡ�
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
