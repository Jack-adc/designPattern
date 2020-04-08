/*
https://blog.csdn.net/wuzhekai1985/article/details/6667467
������ģʽ
������ģʽ�Ķ��彫һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ
���Ĺ������̿��Դ�����ͬ�ı�ʾ��DP�����������ģʽ������
һ���ܺõ����ӡ�������С�ˣ�һ���轨��6�����֣�ͷ�������塢
�����֡����ҽš��빤��ģʽ��ͬ��������ģʽ���ڵ����ߵĿ���
��һ��һ�������Ʒ�ġ�����С�˾����ڿ�����һ������������ġ�
������ģʽ�����ܸ���ϸ�Ŀ��ƹ������̣��Ӷ��ܸ���ϸ�Ŀ�����
�ò�Ʒ���ڲ��ṹ
https://blog.csdn.net/wuzhekai1985/article/details/6667467

C++�麯���봿�麯��������
�麯��(impure virtual)
����C++���麯����Ҫ�����ǡ�����ʱ��̬�����������ṩ�麯����ʵ�֣�Ϊ�����ṩĬ�ϵĺ���ʵ�֡�
  �����������д������麯��ʵ����������⻯��
    ���¾���һ�������е��麯����
    class A
    {
        public:
            virtual void ss()
            {
            cout<<"���ǻ�����麯��"<<endl;
            }
    };
���麯��(pure virtual)
����C++�а������麯�����࣬����Ϊ�ǡ������ࡱ�������಻��ʹ��new������ֻ��ʵ����������麯�����������new������
����C++�еĴ��麯�������ǡ�ֻ�ṩ������û��ʵ�֡����Ƕ������Լ�����ǡ��ӿڼ̳С���
����C++�еĴ��麯��Ҳ��һ�֡�����ʱ��̬����
�������������������麯�������ǡ������ࡱ��
    class A
    {
        public:
            virtual void out1(string s)=0;  //���ǻ�����麯��
    };
�麯������Ҫ�ڻ�������ʵ�֣���ʹ�ǿյ��麯��ҲҪ�ڻ�����ʵ�֣��������п��Բ���д����麯�����������ǻ���û���ĺ���
���麯�����ڻ�����ʵ�֣���������������ʵ��

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
//��������
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
//��������
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
//�����ָ�ӹ�
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