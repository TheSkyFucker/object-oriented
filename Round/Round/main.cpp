/************************************************************

FileName    :   Round.cpp

Author      :   TheSkuFucker
Version     :   1
Date        :   2016.5.8

Description:
    主代码

Function List:
    main()          主程序

***********************************************************/


//====0 头文件包含部分
#include "Round.h"
#include <iostream>
using namespace std;



//====1 主程序
int  main()
{
    
    //--1 Applications
    double r;
    Round *round = new Round(0.0);


    //--2 work
    for (;;)
    {

        //-1 read
        cout << "输入圆的半径(为0代表退出程序)" << endl << "     ";
        cin >> r;
        
        //-2 check
        if (r == 0.0)
        {
            delete round;
            return 0;
        }

        //-3 print
        round->SetR(r);
        cout << "该圆的面积为（保留5位小数）：" << endl;
        printf("     %.5f\n\n", round->GetArea());

    }


}