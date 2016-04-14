/************************************************************

FileName	:   main.cpp

Author		:   TheSkuFucker        
Version		:   1
Date		:   2016.2.16

Description:
	��������룬ʵ�ֽ�����������ʽ���������

Function List: 
	void PrintScene()   ���ڻ��Ʋ�������
	void clear()        ���������ϴβ����Ĳ�������
	int  main()         �������

***********************************************************/

#include "Scan.h"
#include "Print.h"
#include "Calculation.h"

#include <string>
using namespace std;

bool debuging = false;  //���Դ���ʱ��Ϊtrue���ɵõ�һЩִ�н������Ϣ��
bool runing = true;     //�жϳ����Ƿ������



//--���Ʋ�������
void PrintScene()
{


	//--0 ���ģʽ


	//--1 ����ָ��
	cout << endl;
    cout << "|====================!!!ATENTION!!!====================" << endl;
    cout << "|                                                      " << endl;
    cout << "|      New �� �� �� ��������                            " << endl;
    cout << "|      ˢ BUG �� �� �� �� �� ������                      " << endl;
    cout << "|      �� �� �� �� �� �� �� �� �� �� �� �� �� λ��        " << endl;
    cout << "|      �� ϵ �� ʽ��Q Q  3 5 9 0 8 4 4 1 5              " << endl;
    cout << "|                                                      " << endl;
    cout << "|      �� �� B U G �� �� �� ���� ר ҵ ��                " << endl;
    cout << "|                                                      " << endl;
    cout << "|====================!!!ATENTION!!!====================" << endl;
    cout << "|                                                      " << endl;
    cout << "|  �� �� ָ �ϣ�                                        " << endl;
	cout << "|      �� �� : �������������ʽ                        " << endl;
	cout << "|      ʹ �� : ����һ������������ʽ�󰴻س�����         " << endl;
	cout << "|      Ҫ �� : ʵ�����ù�10λ������С���㣩               " << endl;
    cout << "|      �� �� : �����Ͻ�  ||  ���� end + �س�             " << endl;
    cout << "|      �� ע : ����������������ؾصı��ʽ             " << endl;
    cout << "|      �� ע : ��ֵı��ʽˢBUG�ã��۸��������          " << endl;
    cout << "|                                                      " << endl;
    cout << "|======================================================" << endl;
    cout << "|                                                      " << endl;


}



//--�����ϴ����еĽ��
void clear(Scan *changer,Print *printer)
{
	//--1 ���������� && ���в���
	changer->ClearErrorCode();
	changer->ClearStringQueue();

	//--2 
}



//--������
int  main(int argc,char *argv[])
{
	//--0 application
	string str = "helloworld";
	Scan *pChanger = new Scan(debuging);
	Print *pPrinter = new Print(debuging);
    Calculation *pCalculator = new Calculation(debuging);
	


	//--1 run 
	for (; runing; )
	{

		//=0 ���ƽ���
		PrintScene();



		//=1 ���ݶ���
        if (str!="helloworld")
        {
            cout << "|  ��������ʽ��" << endl << "|" << endl;
            cout << "|          ";
            cin >> str;
            if (str == "end")
            {
                break;
            }
        }
        else
        {
            str = argv[argc - 1];
            if (argc>2)
            {
                cout << str << endl;
            }
            argc = 0;
        }
        cout << "|" << endl;
        cout << "|======================================================" << endl;



        //=2 ��������
		pChanger->ToStringQueue(str);
		if (pChanger->GetStringQueue() != NULL)
		{
            pCalculator->CalculateStringQueue(*(pChanger->GetStringQueue()));
		}
        
        

		//=2 clear
		clear(pChanger, pPrinter);

        

		//=3 finish
		system("pause");
		cout << "| " << endl << "|" << endl << "|" << endl;
        cout << "|============================================================================================================" << endl;
        cout << "| " << endl << "|" << endl << "|" << endl << "|";


	}


	//--2 release memory
	delete pChanger;
	delete pPrinter;
    delete pCalculator;


	//--3 end
	return 0;
}