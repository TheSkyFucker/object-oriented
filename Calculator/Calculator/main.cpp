/************************************************************

FileName	:	main.cpp

Author		:	TheSkuFucker        
Version		:	1
Date		:	2016.2.16

Description:
	主程序代码，实现将四则运算表达式拆解后输出；

Function List: 
	void PrintScene()	用于绘制操作界面
	void clear()		用于清理上次操作的残留数据
	int  main()			主体代码

***********************************************************/

#include "Scan.h"
#include "Print.h"

#include <string>
using namespace std;

bool debuging = false;	//调试代码时赋为true，可得到一些执行结果的信息；
bool runing = true; //判断程序是否结束；



//--绘制操作界面
void PrintScene()
{


	//--0 检查模式
	cout << "当前调试模式：";
	if (debuging)
	{
		cout << "开启" << endl;
	}
	else
	{
		cout << "关闭" << endl;
	}
	cout << endl;
	cout << "------------------------------------------------------" << endl;


	//--1 操作指南
	cout << endl;
	cout << "操作指南：" << endl;
	cout << "   功能：拆解四则运算表达式" << endl;
	cout << "   使用：输入一个四则运算表达式后按回车即可；" << endl;
	cout << "   要求：实数不得过10位（包括小数点）" << endl;
	cout << "   结束：按右上角  或  输入end按回车后按任意键  即可" << endl << endl;
	cout << "------------------------------------------------------" << endl;
	cout << endl << "输入表达式：" << endl;


}



//--清理上次运行的结果
void clear(Scan *changer,Print *printer)
{
	//--1 清理错误代码 && 队列残留
	changer->ClearErrorCode();
	changer->ClearStringQueue();

	//--2 
}



//--主程序
int  main()
{
	//--0 application
	string str;
	Scan *pChanger = new Scan(debuging);
	Print *pPrinter = new Print(debuging);
	

	//--1 run 
	for (; runing; )
	{

		//=0 绘制界面
		PrintScene();


		//=1 程序主体
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
		cout << "按回车再次运行程序" << endl;
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