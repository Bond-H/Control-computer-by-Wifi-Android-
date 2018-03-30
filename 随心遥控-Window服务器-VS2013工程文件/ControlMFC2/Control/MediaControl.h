//#define _WIN32_WINNT 0x500
#define _AFXDLL
 
#include<iostream>
//#include <winuser.h>
#include<string>
#include<cstring>
#include<stdio.h>
#include<Mmsystem.h> // waveOutSetVolume头文件
using namespace std;


class MediaControl
{
public:
	void control(string button,int volume);    //根据按键信息选择调用函数

private:
	void start();       //根据当前的状态选择开始/暂停
	void next();        //下一首
	void previous();    //上一首

	//快进快退是个持续过程(按键按下去一直持续到松开,松开发送信息触发停止)
	void forward();     //持续快进
	void backward();    //持续快退
	void stopward();    //停止快进或快退

	void volumeUp();
	void volumeDown();
};

void MediaControl::control(string button,int volume)
{
	if (button == "play")
		start();
	else if (button == "next")
		next();
	else if (button == "previous")
		previous();
	else if (button == "push")
		forward();
	else if (button == "pull")
		backward();
	else if (button == "stopward")
		stopward();
	else if (button == "volumeUp")
		volumeUp();
	else if (button == "volumeDown")
		volumeDown();
}

void MediaControl::start()
{
	keybd_event(VK_SPACE, 0, 0, 0);                 // SPACE
	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
}

void MediaControl::next()
{
//	keybd_event(VK_CONTROL, 0, 0, 0);               // CLT
//	keybd_event(VK_RIGHT, 0, 0, 0);                 // RIGHT
//	keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
//	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_NEXT, 0, 0 ,0);
    keybd_event(VK_NEXT, 0, KEYEVENTF_KEYUP,0);
}

void MediaControl::previous()
{
//	keybd_event(VK_CONTROL, 0, 0, 0);               // CLT
//	keybd_event(VK_LEFT, 0, 0, 0);                  // LEFT
//	keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
//	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_PRIOR, 0, 0 ,0);
    keybd_event(VK_PRIOR, 0, KEYEVENTF_KEYUP,0);
}

void MediaControl::forward()
{
	keybd_event(VK_RIGHT, 0, 0, 0);                 // RIGHT
	keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
}

void MediaControl::backward()
{
	keybd_event(VK_LEFT, 0, 0, 0);                  // LEFT
	keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
}

void MediaControl::stopward()
{
	keybd_event(VK_SPACE, 0, 0, 0);                 // SPACE
	keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
}

void MediaControl::volumeUp()
{
    cout<<"音量上升"<<endl;
//	keybd_event(VK_CONTROL, 0, 0, 0);               // CLT
	keybd_event(VK_UP, 0, 0, 0);                    // UP
	keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
//	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}

void MediaControl::volumeDown()
{
//	keybd_event(VK_CONTROL, 0, 0, 0);               // CLT
	keybd_event(VK_DOWN, 0, 0, 0);                  // DOWN
	keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
//	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP, 0);
}
