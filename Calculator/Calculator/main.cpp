/************************************************************

FileName	:	main.cpp

Author		:	TheSkuFucker        
Version		:	1
Date		:	2016.2.16

Description:
	��������룬ʵ�ֽ�����������ʽ���������

Function List: 
	void PrintScene()	���ڻ��Ʋ�������
	void clear()		���������ϴβ����Ĳ�������
	int  main()			�������

***********************************************************/

#include "Scan.h"
#include "Print.h"

#include <string>
using namespace std;

bool debuging = false;	//���Դ���ʱ��Ϊtrue���ɵõ�һЩִ�н������Ϣ��
bool runing = true; //�жϳ����Ƿ������



//--���Ʋ�������
void PrintScene()
{


	//--0 ���ģʽ
	cout << "��ǰ����ģʽ��";
	if (debuging)
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "�ر�" << endl;
	}
	cout << endl;
	cout << "------------------------------------------------------" << endl;


	//--1 ����ָ��
	cout << endl;
	cout << "����ָ�ϣ�" << endl;
	cout << "   ���ܣ��������������ʽ" << endl;
	cout << "   ʹ�ã�����һ������������ʽ�󰴻س����ɣ�" << endl;
	cout << "   Ҫ��ʵ�����ù�10λ������С���㣩" << endl;
	cout << "   �����������Ͻ�  ��  ����end���س��������  ����" << endl << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl << "������ʽ��" << endl;


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
int  main()
{
	//--0 application
	string str;
	Scan *pChanger = new Scan(debuging);
	Print *pPrinter = new Print(debuging);
	

	//--1 run 
	for (; runing; )
	{

		//=0 ���ƽ���
		PrintScene();


		//=1 ��������
		cin >> str;
		if (str == "end")
		{
			break;
		}
		cout << endl;
		cout << "------------------------------------------------------" << endl;

		pChanger->ToStringQueue(str);
		if (pChanger->GetStringQueue() != NULL)
		{
			pPrinter->PrintStringQueue(pChanger->GetStringQueue());
		}

		//=2 clear
		clear(pChanger, pPrinter);


		//=3 finish
		cout << "���س��ٴ����г���" << endl;
		system("pause");
		cout << endl << endl << endl;
		cout << "============================================================================================================" << endl;
		cout << endl << endl << endl;


	}


	//--2 release memory
	delete pChanger;
	delete pPrinter;


	//--3 end
	return 0;
}