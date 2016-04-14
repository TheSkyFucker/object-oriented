/************************************************************

FileName	:   main.cpp

Author		:   TheSkuFucker        
Version		:   1
Date		:   2016.2.16

Description:
	主程序代码，实现将四则运算表达式拆解后输出；

Function List: 
	void PrintScene()   用于绘制操作界面
	void clear()        用于清理上次操作的残留数据
	int  main()         主体代码

***********************************************************/

#include "Scan.h"
#include "Print.h"
#include "Calculation.h"

#include <string>
using namespace std;

bool debuging = false;  //调试代码时赋为true，可得到一些执行结果的信息；
bool runing = true;     //判断程序是否结束；



//--绘制操作界面
void PrintScene()
{


	//--0 检查模式


	//--1 操作指南
	cout << endl;
    cout << "|====================!!!ATENTION!!!====================" << endl;
    cout << "|                                                      " << endl;
    cout << "|      New 最 新 活 动！！！                            " << endl;
    cout << "|      刷 BUG 火 爆 订 购 中 ！！！                      " << endl;
    cout << "|      价 格 公 道 ！ 剧 本 纯 熟 ！ 演 技 到 位！        " << endl;
    cout << "|      联 系 方 式：Q Q  3 5 9 0 8 4 4 1 5              " << endl;
    cout << "|                                                      " << endl;
    cout << "|      生 产 B U G ！ 我 们 、更 专 业 ！                " << endl;
    cout << "|                                                      " << endl;
    cout << "|====================!!!ATENTION!!!====================" << endl;
    cout << "|                                                      " << endl;
    cout << "|  操 作 指 南：                                        " << endl;
	cout << "|      功 能 : 拆解四则运算表达式                        " << endl;
	cout << "|      使 用 : 输入一个四则运算表达式后按回车即可         " << endl;
	cout << "|      要 求 : 实数不得过10位（包括小数点）               " << endl;
    cout << "|      结 束 : 按右上角  ||  输入 end + 回车             " << endl;
    cout << "|      备 注 : 本计算器仅计算规规矩矩的表达式             " << endl;
    cout << "|      备 注 : 奇怪的表达式刷BUG用，价格好商量！          " << endl;
    cout << "|                                                      " << endl;
    cout << "|======================================================" << endl;
    cout << "|                                                      " << endl;


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

		//=0 绘制界面
		PrintScene();



		//=1 数据读入
        if (str!="helloworld")
        {
            cout << "|  请输入表达式：" << endl << "|" << endl;
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



        //=2 计算主体
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