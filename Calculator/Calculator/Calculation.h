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

    int errorcode;  //错误码
    bool debuging;  //存储错误信息

    int lv[300];    //预设优先级数组


    stack<int> *level = new stack<int>;         //优先级栈
    stack<char> *oper = new stack<char>;        //运算符栈
    stack<double> *numb = new stack<double>;    //浮点数栈

    queue<string> *tmp = new queue<string>;

    /*
        描述 :    初始化计算的相关数据
    */
    void InitData();



public:

    /*
        描述 :    输入是否为调试代码模式
    */
    Calculation(bool debuging);

    /*
        描述 :    检测 && 处理  字符串队列形式  的四则运算表达式
    */
    void CheckStringQueue(queue<string> input);

    /*
        描述 :    输出给定  字符串队列形式  四则运算表达式  的答案; 
    */
    void CalculateStringQueue(queue<string> input);

};

