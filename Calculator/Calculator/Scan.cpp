/************************************************************

FileName    :   Scan.cpp

Author      :   TheSkyFucker
Version     :   2
Date        :   2016.4.14

Description:
    ����Scan���е��෽����

Function List:
    void ToStringQueue(string input)    ���������ַ����������У�
    queue<string> *GetStringQueue()     ��ȡ�洢������Ķ��У�
    void ClearErrorCode()               ���������Ϣ��
    void ClearStringQueue()             ����������ݣ�

***********************************************************/


//====0 ͷ�ļ���������
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

        //=1 ��������
        if ((input[i] >= '0' && input[i] <= '9') || (input[i] == '.'))
        {
            if (lenth == 0) dai = "";
            lenth++;
            dai += input[i];
        }
        else

        //=2 �������
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

        //=3 ���������ַ�
        {
            errorcode |= ERROR_CODE_OTHERS;
        }

        //=4 ����ƥ��
        kuohao += input[i] == '(';
        kuohao -= input[i] == ')';
        if (kuohao<0) errorcode |= ERROR_CODE_KUOHAO;

        //=5 ���ʵ������
        if (lenth > 10) errorcode |= ERROR_CODE_RANGE;
		
    }


    if (lenth) que->push(dai);
    if (kuohao != 0) errorcode |= ERROR_CODE_KUOHAO;


	//--2 return result
    if (errorcode)
    {

	    i=0;
        cout << endl << "������Ϣ" << endl;
        if (errorcode & ERROR_CODE_KUOHAO)
            cout << "    ����" << ++i << "�� ���ʽ���Ų�ƥ��" << endl;
        if (errorcode & ERROR_CODE_RANGE)
            cout << "    ����" << ++i << "�� ������ڷ�Χ����ʵ������10λ������С���㣩" << endl;
        if (errorcode & ERROR_CODE_OTHERS)
            cout << "    ����" << ++i << "�� ���� + , - , * , / , ( , ) , . , 0~9 ����ַ�" << endl;
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