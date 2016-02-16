#pragma once

#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Scan
{


private:
	bool debuging = false;	//调试代码时赋为true，可得到一些执行结果的信息；

	int kuohao = 0;			//用于判断括号匹配
	int errorcode = 0;		//存储错误信息

	queue<string> *que = new queue<string>;	//存储表达式的队列



public:

	/*
		输入是否为调试代码模式
	*/
	Scan(bool debuging);


	/*
		描述	:	接受一个四则运算表达式，拆分后存入队列；
	*/	
	void ToStringQueue(string input);
	

	/*
		描述：	获取  指向  存储表达式字符串队列  的指针；
	*/
	queue<string> *GetStringQueue();


	/*
		描述：	清理错误代码；
	*/
	void ClearErrorCode();



	/*
		描述：	清理队列内容；
	*/
	void ClearStringQueue();

};

