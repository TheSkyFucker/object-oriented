/************************************************************

FileName    :   Scan.cpp

Author      :   TheSkyFucker
Version     :   2
Date        :   2016.4.14

Description:
    定义Scan类中的类方法；

Function List:
    void ToStringQueue(string input)    将给定的字符串拆解进队列；
    queue<string> *GetStringQueue()     获取存储拆解结果的队列；
    void ClearErrorCode()               清除错误信息；
    void ClearStringQueue()             清除队列内容；

***********************************************************/


//====0 头文件包含部分
#include "Scan.h"



//====0 Define Error Code Table
#define ERROR_CODE_RANGE    1
#define ERROR_CODE_KUOHAO   2
#define ERROR_CODE_OTHERS   4



//====0 Structure
Scan::Scan(bool debuging)
{

    this->debuging = debuging;

}



//====1 ToStringQueue
void Scan::ToStringQueue(string input)
{

    //--0 init
    int i;
    int lenth = 0;
    string dai;


    //--1 change into queue:que
    for (i = 0; i <input.size(); i++)
    {

        //=1 加入数字
        if ((input[i] >= '0' && input[i] <= '9') || (input[i] == '.'))
        {
            if (lenth == 0) dai = "";
            lenth++;
            dai += input[i];
        }
        else

        //=2 加入表达符
        if (input[i] == '(' || input[i] == ')' || input[i]=='+' ||
            input[i] == '-' || input[i] == '*' || input[i]=='/' )
        {
            if (lenth)
            {
                lenth = 0;
                que->push(dai);
        }
            que->push(dai=input[i]);
        }
        else

        //=3 存在其他字符
        {
            errorcode |= ERROR_CODE_OTHERS;
        }

        //=4 括号匹配
        kuohao += input[i] == '(';
        kuohao -= input[i] == ')';
        if (kuohao<0) errorcode |= ERROR_CODE_KUOHAO;

        //=5 检查实数长度
        if (lenth > 10) errorcode |= ERROR_CODE_RANGE;
		
    }


    if (lenth) que->push(dai);
    if (kuohao != 0) errorcode |= ERROR_CODE_KUOHAO;


	//--2 return result
    if (errorcode)
    {

	    i=0;
        cout << endl << "错误信息" << endl;
        if (errorcode & ERROR_CODE_KUOHAO)
            cout << "    错误" << ++i << "： 表达式括号不匹配" << endl;
        if (errorcode & ERROR_CODE_RANGE)
            cout << "    错误" << ++i << "： 输入存在范围错误，实数超过10位（包括小数点）" << endl;
        if (errorcode & ERROR_CODE_OTHERS)
            cout << "    错误" << ++i << "： 存在 + , - , * , / , ( , ) , . , 0~9 外的字符" << endl;
        cout << endl;
    cout << "------------------------------------------------------" << endl;

    }	
    else
    {
        if (debuging)
        {
            if (i >= input.size())
            {
                cout << "MESSAGE : Change compeleted!" << endl;
            }
            else
            {
                cout << "MESSAGE : Change failed!" << endl;
            }
        }
    }
}



//=====2 GetStringQueue
queue<string> *Scan::GetStringQueue()
{

    if (!errorcode)
    {
        return que;
    }
    else
    {
        return NULL;
    }
    
}



//=====3 ClearErrorCode
void Scan::ClearErrorCode()
{

    Scan::errorcode = 0;

}



//====4 ClearStringQueue
void Scan::ClearStringQueue()
{

    kuohao = 0;
    for (; !que->empty(); que->pop());

}