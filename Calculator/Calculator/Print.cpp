/************************************************************

FileName    :   Print.cpp

Author      :   TheSkuFucker
Version     :   1
Date        :   2016.2.16

Description:
    定义Print类中的类方法；

Function List:
    void PrintStringQueue()	输出字符串队列

***********************************************************/


//====0 头文件包含部分
#include "Print.h"



//====0 Structure
Print::Print(bool debuging)
{
    this->debuging = debuging;
}



//====1 输出
void Print::PrintStringQueue(queue<string> *que)
{
    int i;


    //--0 init
    cout << endl << "拆解结果如下：" << endl;


    //--1 print
    for (; !que->empty(); que->pop())
    {
        cout << que->front() << endl;
    }
    cout << endl;
    cout << "------------------------------------------------------" << endl;


    //--2 return result;
    if (debuging)
    {
        if (que->empty())
        {
            cout << "MESSAGE : Print Compeleted!" << endl;
        }
        else
        {
            cout << "MESSAGE : Print Failed!" << endl;
        }
    }


}