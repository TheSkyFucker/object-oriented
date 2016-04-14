#pragma once

#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Calculation
{


private:

    int errorcode;  //������
    bool debuging;  //�洢������Ϣ

    int lv[300];    //Ԥ�����ȼ�����


    stack<int> *level = new stack<int>;         //���ȼ�ջ
    stack<char> *oper = new stack<char>;        //�����ջ
    stack<double> *numb = new stack<double>;    //������ջ

    queue<string> *tmp = new queue<string>;

    /*
        ���� :    ��ʼ��������������
    */
    void InitData();



public:

    /*
        ���� :    �����Ƿ�Ϊ���Դ���ģʽ
    */
    Calculation(bool debuging);

    /*
        ���� :    ��� && ����  �ַ���������ʽ  ������������ʽ
    */
    void CheckStringQueue(queue<string> input);

    /*
        ���� :    �������  �ַ���������ʽ  ����������ʽ  �Ĵ�; 
    */
    void CalculateStringQueue(queue<string> input);

};

