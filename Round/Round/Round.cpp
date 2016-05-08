/************************************************************

FileName    :   Round.cpp

Author      :   TheSkuFucker
Version     :   1
Date        :   2016.5.8

Description:
    һ����������Բ����

Function List:
    Round(double r)     ���캯������ʼ��Բ�İ뾶        
    void SetR(double r) �޸�Բ�İ뾶
    double GetArea()    ����Բ�����������

***********************************************************/


//====0 ͷ�ļ���������
#include <cmath>
#include "Round.h"



//====0 �궨�岿��
#define PI acos(-1)



//====0 Structure
Round::Round(double r)
{
    this->r = r;
}



//====1 SetR
void Round::SetR(double r)
{
    this->r = r;
}



//====2 Area
double Round::GetArea()
{
    return PI*r*r;
}

