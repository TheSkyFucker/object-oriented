/************************************************************

FileName    :   Round.cpp

Author      :   TheSkuFucker
Version     :   1
Date        :   2016.5.8

Description:
    ������

Function List:
    main()          ������

***********************************************************/


//====0 ͷ�ļ���������
#include "Round.h"
#include <iostream>
using namespace std;



//====1 ������
int  main()
{
    
    //--1 Applications
    double r;
    Round *round = new Round(0.0);


    //--2 work
    for (;;)
    {

        //-1 read
        cout << "����Բ�İ뾶(Ϊ0�����˳�����)" << endl << "     ";
        cin >> r;
        
        //-2 check
        if (r == 0.0)
        {
            delete round;
            return 0;
        }

        //-3 print
        round->SetR(r);
        cout << "��Բ�����Ϊ������5λС������" << endl;
        printf("     %.5f\n\n", round->GetArea());

    }


}