/*
�򵥹����ǹ���ģʽ��򵥵�һ��ʵ�֣����ڲ�ͬ��Ʒ�Ĵ�������һ�������࣬
����Ʒ��������Ϊ�������뵽�����Ĵ����������������ͷ�֧ѡ��ͬ�Ĳ�Ʒ���캯����
*/
#include <iostream>
using namespace std;

typedef enum ProductTypeTag
{
    E_BASKERBALL     = 0,
    E_FOOTBALL          ,
    E_TENNIS            
}PRODUCTTYPE;

class Product           //��Ʒ����
{
public:
    virtual void createProduct() = 0;
};

class ProduceBasketBall: public Product
{
public:
    void createProduct()
    {
        cout << "��������" << endl;
    }
    ProduceBasketBall()
    {
        cout << "����һ��ProduceBasketBall����" << endl;
    }
};

class ProduceFootball : public Product
{
public:
    void createProduct()
    {
        cout << "��������" << endl;
    }
    ProduceFootball()
    {
        cout << "����һ��ProduceFootball����" << endl;
    }
};

class ProduceTennis :public Product
{
public:
    void createProduct()
    {
        cout << "��������" << endl;
    }
    ProduceTennis()
    {
        cout << "����һ��ProduceTennis����" << endl;
    }
};

class Factory           // ������
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