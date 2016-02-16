#pragma once

#include "Scan.h"

class Print
{


private:
	bool debuging = false;	//调试代码时赋为true，可得到一些执行结果的信息；


public:


	/*
		输入是否为调试代码模式
	*/
	Print(bool debuging);



	/*
		输入一个队列指针；
		按行输出指针指向的队列；
	*/
	void PrintStringQueue(queue<string> *que);



};

