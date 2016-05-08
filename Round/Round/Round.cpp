/************************************************************

FileName    :   Round.cpp

Author      :   TheSkuFucker
Version     :   1
Date        :   2016.5.8

Description:
    一个用来定义圆的类

Function List:
    Round(double r)     构造函数，初始化圆的半径        
    void SetR(double r) 修改圆的半径
    double GetArea()    计算圆的面积并返回

***********************************************************/


//====0 头文件包含部分
#include <cmath>
#include "Round.h"



//====0 宏定义部分
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

