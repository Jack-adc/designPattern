/*
外观模式
https://www.cnblogs.com/ring1992/p/9593112.html
我们在使用visual studio进行编译C++代码时，你只是在菜单中选择了Build，
然后visual studio就开始了一堆的编译工作；你应该知道，因为你的一个简
单的Build动作，编译器在后台会进行语法分析，生成中间代码，生成汇编代
码，链接成可执行程序或库等等动作；而这一切，作为只是开发程序的我们，
而不用去理解编译器在做什么的，编译器向我们隐藏了背后的一系列复杂操作
，而只提供一个Build按钮，这个Build按钮，就可以执行一切的操作；当单击
这个Build按钮时，Build在幕后，将任务分发给不同的子系统去完成，最终子
系统进行协作完成了整个的编译任务。而这样隐藏一些复杂操作，只提供一个
更高层的统一接口，就是我今天总结的外观模式。


Facade:知道哪些子系统类负责处理请求，并且将客户的请求代理给适当的子系统对象；

SubSystem:实现子系统具体的功能；处理由Facade对象指派的任务；但是，SubSystem
没有Facade的任何相关信息，也就是说，没有指向Facade的指针。

Client通过发送请求给Facade的方式与子系统进行通信，而不直接与子系统打交道，
Facade将这些消息转发给适当的子系统对象。尽管是子系统中的有关对象在做实际工作，
但Facade模式本身也必须将它的接口转换成子系统的接口，这里是不是有点适配器模式
的感觉呢？这就是学习结构型设计模式的感觉，感觉都很相似，但是仔细的去研究时，
就会发现各自的用处。

*/

#include<iostream>
using namespace std;

// 语法分析子系统
class CSyntaxParser
{
public:
    void SyntaxParser()
    {
        cout << "Syntax Parser" << endl;
    }
};

// 生成中间代码子系统
class CGenMidCode
{
public:
    void GenMidCode()
    {
        cout << "Generate middle code" << endl;
    }
};

// 生成汇编代码子系统
class CGenAssemblyCode
{
public:
    void GenAssemblyCode()
    {
        cout << "Generate assembly code" << endl;
    }
};

// 链接生成可执行应用程序或库子系统
class CLinkSystem
{
public:
    void LinkSystem()
    {
        cout << "Link System" << endl;
    }
};

class Facade
{
public:
    void Compile()
    {
        CSyntaxParser syntaxParser;
        CGenMidCode genMidCode;
        CGenAssemblyCode genAssemblyCode;
        CLinkSystem linkSystem;
        syntaxParser.SyntaxParser();
        genMidCode.GenMidCode();
        genAssemblyCode.GenAssemblyCode();
        linkSystem.LinkSystem();
    }
};

// 客户端
int main()
{
    Facade facade;
    facade.Compile();
    return 0;
}

/*
总结

外观模式简单易用，让客户能更简单的去使用子系统：
1.在设计初期，应该有意识的将不同层分离，比如常用的三层架构，就是考虑在数据访问层，
与业务逻辑层表示层之间，建立Facade，使复杂的子系统提供一个简单的接口，降低耦合性；
2.在开发阶段，子系统往往因为不断的重构而变的越来越复杂，增加外观Facade可以提供一
个简单的接口，减少它们之间的依赖；
3.在维护阶段，可能这个系统已经非常难以维护和扩展了，此时你可以为新系统开发一个外
观类，来提供设计粗糙或高度复杂的遗留代码的比较清晰简单的接口，让新系统与Facade对
象交互，Facade与遗留代码交互所有复杂的工作。

*/