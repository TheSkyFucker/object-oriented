/************************************************************

FileName    :   Print.cpp

Author      :   TheSkuFucker
Version     :   1
Date        :   2016.2.16

Description:
    ����Print���е��෽����

Function List:
    void PrintStringQueue()	����ַ�������

***********************************************************/


//====0 ͷ�ļ���������
#include "Print.h"



//====0 Structure
Print::Print(bool debuging)
{
    this->debuging = debuging;
}



//====1 ���
void Print::PrintStringQueue(queue<string> *que)
{
    int i;


    //--0 init
    cout << endl << "��������£�" << endl;


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