/*
��ʵ��������ڵĹ���ģʽ���򵥹���ģʽֻ��һ���򵥵ĶԴ������̷�װ��
��������ģʽ�ڼ򵥹���ģʽ�Ļ��������ӶԹ����Ļ�����󣬲�ͬ�Ĳ�Ʒ
�������ò�ͬ�Ĺ����������ӹ����ĳ������������������������ͬ�Ĳ�Ʒ
���̾��ɲ�ͬ�Ĺ����ֹ������FactoryAר�ĸ�������ProductA��FactoryB
ר�ĸ�������ProductB��FactoryA��FactoryB֮��û�й�ϵ��������˺��ڣ�
�����Ҫ����ProductCʱ����������Դ���һ��FactoryC�����࣬����ר��
��������ProductC���Ʒ��
��ģʽ����ڼ򵥹���ģʽ���������ڣ����ں��ڲ�Ʒ�������չ��
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
        cout << "��������" << endl;
    }
    basketBallProduct()
    {
        cout << "����һ������" << endl;
    }
};

class footBallProduct :public product
{
public:
    void show()
    {
        cout << "��������" << endl;
    }

    footBallProduct()
    {
        cout << "����һ������" << endl;
    }
};

class tennisProduct :public product
{
public:
    void show()
    {
        cout << "��������" << endl;
    }

    tennisProduct()
    {
        cout << "����һ������" << endl;
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