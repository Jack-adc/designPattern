/*
���󹤳�ģʽ�Թ�������ģʽ�����˸���һ�㻯����������������
ģʽ�����ڲ�Ʒ����ṹ��һ�ĳ��ϣ�Ϊһ���Ʒ�ṩ�����Ľӿڣ�
�����󹤳����������ڲ�Ʒ����ṹ��ĳ��ϣ����ǵ����ж����
���Ʒ����ʱ�����󹤳�����������ó���

���󹤳�ģʽ���ʺ�ʵ������������������ޣ��õͶ˹���������
ͬ����ĵͶ˲�Ʒ���߶˹���������ͬ����ĸ߶˲�Ʒ��
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
        cout << "����A��Ʒ 1��" << endl;
    }
};

class ProductA2 :public ProductA
{
public:
    void show()
    {
        cout << "����A��Ʒ2��" << endl;
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
        cout << "����B��Ʒ1��" << endl;
    }
};

class ProductB2 : public ProductB
{
public:
    void show()
    {
        cout << "����B��Ʒ2��" << endl;
    }
};

class Factory
{
public:
    virtual ProductA* createProductA() = 0;
    virtual ProductB* createProductB() = 0;
};

class Factory1 :public Factory  // 1�Ź�����������1���Ʒ
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

class Factory2 : public Factory // 2�Ź�����������2�Ų�Ʒ
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