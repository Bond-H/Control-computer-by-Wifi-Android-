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
** 函数名:control
** 输 入: page,command,volunm
** page---安卓端传过来的activity名称，用于选择对象
** command---安卓端传输过来的按键名称，用于选择函数
** volunm---音量大小，用于设置音量，为百分数
** 输 出: x---返回调用功能成功或失败
** 功能描述:PC端总的控制模块.根据安卓端发送过来的信息来调用控制PC的函数
** 全局变量:无
** 调用模块:日常控制类DayControl,PPT控制类PPTControl
多媒体控制类MediaControl,游戏控制GameControl
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
	Sleep(200);    // 千万别忘了，否则键盘消息会发送到cmd窗口
	DC->control(command);
	cout << command << " succeed" << endl;
	return true;
}
bool Control::PptControl(string command){
	Sleep(200);    // 千万别忘了，否则键盘消息会发送到cmd窗口
	PPTC->control(command);
	cout << command << " succeed" << endl;
	return true;
}
bool Control::mediaControl(string command,int volunm){ 
	Sleep(200);    // 千万别忘了，否则键盘消息会发送到cmd窗口
	MC->control(command, volunm);
	cout << command << " succeed" << endl;
	return true;
}
bool Control::gameControl(string command){
	Sleep(200);    // 千万别忘了，否则键盘消息会发送到cmd窗口
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

	// 游戏控制
	else if (page == "Game")
		gameControl(command);
	else
		return false;

	return true;
}




