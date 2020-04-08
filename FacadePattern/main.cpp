/*
���ģʽ
https://www.cnblogs.com/ring1992/p/9593112.html
������ʹ��visual studio���б���C++����ʱ����ֻ���ڲ˵���ѡ����Build��
Ȼ��visual studio�Ϳ�ʼ��һ�ѵı��빤������Ӧ��֪������Ϊ���һ����
����Build�������������ں�̨������﷨�����������м���룬���ɻ���
�룬���ӳɿ�ִ�г�����ȵȶ���������һ�У���Ϊֻ�ǿ�����������ǣ�
������ȥ������������ʲô�ģ������������������˱����һϵ�и��Ӳ���
����ֻ�ṩһ��Build��ť�����Build��ť���Ϳ���ִ��һ�еĲ�����������
���Build��ťʱ��Build��Ļ�󣬽�����ַ�����ͬ����ϵͳȥ��ɣ�������
ϵͳ����Э������������ı������񡣶���������һЩ���Ӳ�����ֻ�ṩһ��
���߲��ͳһ�ӿڣ������ҽ����ܽ�����ģʽ��


Facade:֪����Щ��ϵͳ�ฺ�������󣬲��ҽ��ͻ������������ʵ�����ϵͳ����

SubSystem:ʵ����ϵͳ����Ĺ��ܣ�������Facade����ָ�ɵ����񣻵��ǣ�SubSystem
û��Facade���κ������Ϣ��Ҳ����˵��û��ָ��Facade��ָ�롣

Clientͨ�����������Facade�ķ�ʽ����ϵͳ����ͨ�ţ�����ֱ������ϵͳ�򽻵���
Facade����Щ��Ϣת�����ʵ�����ϵͳ���󡣾�������ϵͳ�е��йض�������ʵ�ʹ�����
��Facadeģʽ����Ҳ���뽫���Ľӿ�ת������ϵͳ�Ľӿڣ������ǲ����е�������ģʽ
�ĸо��أ������ѧϰ�ṹ�����ģʽ�ĸо����о��������ƣ�������ϸ��ȥ�о�ʱ��
�ͻᷢ�ָ��Ե��ô���

*/

#include<iostream>
using namespace std;

// �﷨������ϵͳ
class CSyntaxParser
{
public:
    void SyntaxParser()
    {
        cout << "Syntax Parser" << endl;
    }
};

// �����м������ϵͳ
class CGenMidCode
{
public:
    void GenMidCode()
    {
        cout << "Generate middle code" << endl;
    }
};

// ���ɻ�������ϵͳ
class CGenAssemblyCode
{
public:
    void GenAssemblyCode()
    {
        cout << "Generate assembly code" << endl;
    }
};

// �������ɿ�ִ��Ӧ�ó�������ϵͳ
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

// �ͻ���
int main()
{
    Facade facade;
    facade.Compile();
    return 0;
}

/*
�ܽ�

���ģʽ�����ã��ÿͻ��ܸ��򵥵�ȥʹ����ϵͳ��
1.����Ƴ��ڣ�Ӧ������ʶ�Ľ���ͬ����룬���糣�õ�����ܹ������ǿ��������ݷ��ʲ㣬
��ҵ���߼����ʾ��֮�䣬����Facade��ʹ���ӵ���ϵͳ�ṩһ���򵥵Ľӿڣ���������ԣ�
2.�ڿ����׶Σ���ϵͳ������Ϊ���ϵ��ع������Խ��Խ���ӣ��������Facade�����ṩһ
���򵥵Ľӿڣ���������֮���������
3.��ά���׶Σ��������ϵͳ�Ѿ��ǳ�����ά������չ�ˣ���ʱ�����Ϊ��ϵͳ����һ����
���࣬���ṩ��ƴֲڻ�߶ȸ��ӵ���������ıȽ������򵥵Ľӿڣ�����ϵͳ��Facade��
�󽻻���Facade���������뽻�����и��ӵĹ�����

*/