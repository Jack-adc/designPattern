/*
组合模式
组合模式，将对象组合成属性结构以表示‘部分-整体’的层次结构。
组合模式使得用户对单个对象和组合对象的使用具有一致性

这个模式可以创建一个树形结构，在同一个结构中处理嵌套菜单和菜
单项组。通过菜单和项放在同样结构中，我们创建了一个“总体/部
分”层次结构，即由菜单和菜单项组成的对象树。使用组合结构，我
们能把同样的操作应用在组合和个别对象上。换句话说，在大多数情
况下，我们可以忽略对象组合和个别对象之间的区别。

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