#pragma once

#include "Scan.h"

class Print
{


private:
	bool debuging = false;	//���Դ���ʱ��Ϊtrue���ɵõ�һЩִ�н������Ϣ��


public:


	/*
		�����Ƿ�Ϊ���Դ���ģʽ
	*/
	Print(bool debuging);



	/*
		����һ������ָ�룻
		�������ָ��ָ��Ķ��У�
	*/
	void PrintStringQueue(queue<string> *que);



};

