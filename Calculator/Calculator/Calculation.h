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

    int errorcode;
    bool debuging;  //�洢������Ϣ

    int lv[300];


    stack<int> *level = new stack<int>;
    stack<char> *oper = new stack<char>;
    stack<double> *numb = new stack<double>;

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

