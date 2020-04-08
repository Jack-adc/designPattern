/*
ģ��ģʽ
ģ��ģʽ��һ����Ϊ��ģʽ������������һ���㷨�Ŀ�ܣ�����һЩ�����ӳٵ������С�
ģ�巽��ģʽʹ��������Բ��ı�һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�ض�����
ʹ�ó��������������ʹ����ͬ���߼�
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
        cout << "���Ա���ѡ����Ʒ"<<endl;
    }
    void addToCart()
    {
        cout << "���Ա�����ӹ��ﳵ" << endl;
    }
    void account()
    {
        cout << "���Ա���֧��" << endl;
    }
};

class shoppingOnJD : public OnlineShopping
{
public:
    void selectProduct()
    {
        cout << "�ھ�����ѡ����Ʒ" << endl;
    }
    void addToCart()
    {
        cout << "�ھ�������ӹ��ﳵ" << endl;
    }
    void account()
    {
        cout << "�ھ�����֧��" << endl;
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