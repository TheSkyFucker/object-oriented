/************************************************************

FileName    :   Calculation.cpp

Author      :   TheSkyFucker
Version     :   1
Date        :   2016.4.14

Description:
    定义Calculation类中的类方法；

Function List:
    void InitData()                                 初始化类中的资料;
    void CheckStringQueue(queue<string> *input)     检测所给定的表达式是否合法;
    void CalculateStringQueue(queue<string> input)  计算所给定的表达式;

***********************************************************/


//====0 头文件包含部分
#include "Calculation.h"



//====0 Define Error Table
#define ERROR_CODE_EXPRESSION   1
#define ERROR_CODE_DEVIDEZERO   2



//====0 Structure
Calculation::Calculation(bool debuging)
{

    //--0 init mode
    this->debuging = debuging;


    //--0 init level table
    lv['#'] = 0;
    lv['+'] = lv['-'] = 1;
    lv['*'] = lv['/'] = 2;

}



//====1 InitData
void Calculation::InitData()
{

    //--1 init errorcode
    errorcode = 0;


    //--2 init queue
    for (; tmp->empty() == false; tmp->pop());


    //--3 init stacks
    for (; oper->empty() == false; oper->pop());
    for (; numb->empty() == false; numb->pop());
    for (; level->empty() == false; level->pop());

}



//====2 CheckStringQueue
void Calculation::CheckStringQueue(queue<string> input)
{

    //--1 check first -
    if (input.front() == "-")
    {
        tmp->push("0");
    }
    for (; input.empty() == false; input.pop())
    {
        tmp->push(input.front());
    }

}



//====2 CalculateStringQueue
void Calculation::CalculateStringQueue(queue<string> input)
{
    
    //--0 init
    int level_base = 0;
    double tmp1;
    double tmp2;

    InitData();
    CheckStringQueue(input);

    


    //--1 Calculate
    for (tmp->push("#"); tmp->empty() == false; tmp->pop())
    {

        //=1 处理数字
        if (tmp->front()[0] >= '0' && tmp->front()[0] <= '9')
        {
            //1 change
            std::stringstream stream;
            stream << tmp->front();
            stream >> tmp1;

            //2 push
            numb->push(tmp1);
        }
        else

        //=2 调整基础优先级
        if (tmp->front()[0] == '(' || tmp->front()[0] == ')')
        {
            level_base += 100 * (tmp->front()[0] == '(');
            level_base -= 100 * (tmp->front()[0] == ')');
        }
        else

        //=3 处理运算符
        {
            //1 clear
            for (; level->empty() == false && level_base + lv[tmp->front()[0]] <= level->top();)
            {
                //Get numbers
                if (numb->empty() == false)
                {
                    tmp1 = numb->top();
                    numb->pop();
                }
                else
                {
                    errorcode |= ERROR_CODE_EXPRESSION;
                    cout << endl << "|       表达式错误" << endl << "|" << endl;
                    cout << "|======================================================" << endl;
                    return;
                }
                if (numb->empty() == false)
                {
                    tmp2 = numb->top();
                    numb->pop();
                }
                else
                {
                    errorcode |= ERROR_CODE_EXPRESSION;
                    cout << endl << "|       表达式错误" << endl << "|" << endl;
                    cout << "|======================================================" << endl;
                    return;
                }

                //Check 
                if (oper->top() == '/' && tmp1 == 0)
                {
                    cout << endl << "|       表达式错误，出现除0" << endl << "|" << endl;
                    cout << "|======================================================" << endl;
                    errorcode |= ERROR_CODE_DEVIDEZERO;
                    return;
                }

                //operate
                switch (oper->top())
                {
                    case '+': numb->push(tmp2 + tmp1); break;
                    case '-': numb->push(tmp2 - tmp1); break;
                    case '*': numb->push(tmp2 * tmp1); break;
                    case '/': numb->push(tmp2 / tmp1); break;
                }

                //pop
                oper->pop();
                level->pop();
            }

            //2 push
            oper->push(tmp->front()[0]);
            level->push(level_base + lv[tmp->front()[0]]);
            
        }

    }


    //--2 Print Answer
    if (numb->size() != 1)
    {
        cout << "|" << endl << "|       表达式错误" << endl << "|" << endl;
    }
    else
    {
        cout << "|" << endl << "|  计算结果如下：" << endl << "|" << endl << "|         ";
        cout << numb->top() << endl << "|" << endl;

    }
    cout << "|======================================================" << endl;
}


