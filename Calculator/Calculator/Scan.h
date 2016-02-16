#pragma once

#include <queue>
#include <string>
#include <iostream>
using namespace std;

class Scan
{


private:
	bool debuging = false;	//���Դ���ʱ��Ϊtrue���ɵõ�һЩִ�н������Ϣ��

	int kuohao = 0;			//�����ж�����ƥ��
	int errorcode = 0;		//�洢������Ϣ

	queue<string> *que = new queue<string>;	//�洢���ʽ�Ķ���



public:

	/*
		�����Ƿ�Ϊ���Դ���ģʽ
	*/
	Scan(bool debuging);


	/*
		����	:	����һ������������ʽ����ֺ������У�
	*/	
	void ToStringQueue(string input);
	

	/*
		������	��ȡ  ָ��  �洢���ʽ�ַ�������  ��ָ�룻
	*/
	queue<string> *GetStringQueue();


	/*
		������	���������룻
	*/
	void ClearErrorCode();



	/*
		������	����������ݣ�
	*/
	void ClearStringQueue();

};

