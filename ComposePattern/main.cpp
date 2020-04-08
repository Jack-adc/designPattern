/*
���ģʽ
���ģʽ����������ϳ����Խṹ�Ա�ʾ������-���塯�Ĳ�νṹ��
���ģʽʹ���û��Ե����������϶����ʹ�þ���һ����

���ģʽ���Դ���һ�����νṹ����ͬһ���ṹ�д���Ƕ�ײ˵��Ͳ�
�����顣ͨ���˵��������ͬ���ṹ�У����Ǵ�����һ��������/��
�֡���νṹ�����ɲ˵��Ͳ˵�����ɵĶ�������ʹ����Ͻṹ����
���ܰ�ͬ���Ĳ���Ӧ������Ϻ͸�������ϡ����仰˵���ڴ������
���£����ǿ��Ժ��Զ�����Ϻ͸������֮�������

*/

#include <iostream>
#include <vector>
using namespace  std;

class component
{
public:
    virtual void operation() = 0;
    virtual void add(component*) = 0;
};

class Leaf :public component
{
public:
    void operation()
    {
        cout << "operation leaf" << endl;
    }
    void add(component*)
    {

    }
};

class composite :public component
{
public:
    void operation()
    {
        cout << "operation composite" << endl;
        vector <component>::iterator iter_component = m_vctLeaf.begin();
        for (; iter_component != m_vctLeaf.end(); iter_component++)
        {
            cout << "-----" << endl;
            iter_component->operation();
        }
    }

    void add(component* c)
    {
        m_vctLeaf.push_back(*c);
    }

private:
    vector <component> m_vctLeaf;
};

int main()
{
    component* leaf1 = new Leaf();
    component* leaf2 = new Leaf();
    component* composite1 = new composite();
//     composite1->add(leaf1);
//     composite1->add(leaf2);
    component* composite2 = new composite();
   // composite2->add(composite1);
    composite2->operation();
    return 0;
}