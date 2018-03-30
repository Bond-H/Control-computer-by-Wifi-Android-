#include<iostream>
#include<string>
//#include <winuser.h>
#include<stdio.h>
#include<cstdlib>
#include <stdlib.h>
#include <shellapi.h>
#include"DayControl.h"
#include"PPTControl.h"
#include"DayControl.cpp"
#include"PPTControl.cpp"
#include"MediaControl.h"
#include"GameControl.h"
using namespace std;

/**************************************************
** ������:control
** �� ��: page,command,volunm
** page---��׿�˴�������activity���ƣ�����ѡ�����
** command---��׿�˴�������İ������ƣ�����ѡ����
** volunm---������С����������������Ϊ�ٷ���
** �� ��: x---���ص��ù��ܳɹ���ʧ��
** ��������:PC���ܵĿ���ģ��.���ݰ�׿�˷��͹�������Ϣ�����ÿ���PC�ĺ���
** ȫ�ֱ���:��
** ����ģ��:�ճ�������DayControl,PPT������PPTControl
��ý�������MediaControl,��Ϸ����GameControl
**************************************************/
class Control{
private:
	string command;
	DayControl *DC = new DayControl();
	PPTControl *PPTC = new PPTControl();
	MediaControl *MC = new MediaControl();
	GameControl *GC = new GameControl();
public:
	bool dailyControl(string command);
	bool PptControl(string command);
	bool mediaControl(string command, int volunm);
	bool gameControl(string command);

	bool control(string page, string command, int volunm);
};

bool Control::dailyControl(string command){
	Sleep(200);    // ǧ������ˣ����������Ϣ�ᷢ�͵�cmd����
	DC->control(command);
	cout << command << " succeed" << endl;
	return true;
}
bool Control::PptControl(string command){
	Sleep(200);    // ǧ������ˣ����������Ϣ�ᷢ�͵�cmd����
	PPTC->control(command);
	cout << command << " succeed" << endl;
	return true;
}
bool Control::mediaControl(string command,int volunm){ 
	Sleep(200);    // ǧ������ˣ����������Ϣ�ᷢ�͵�cmd����
	MC->control(command, volunm);
	cout << command << " succeed" << endl;
	return true;
}
bool Control::gameControl(string command){
	Sleep(200);    // ǧ������ˣ����������Ϣ�ᷢ�͵�cmd����
	GC->control(command);
	cout << command << " succeed" << endl;
	return true;
}

bool Control::control(string page, string command, int volunm)
{

	if (page == "Daily")
		dailyControl(command);

	else if (page == "PPT")
		PptControl(command);

	else if (page == "Media")
		mediaControl(command, volunm);

	// ��Ϸ����
	else if (page == "Game")
		gameControl(command);
	else
		return false;

	return true;
}




