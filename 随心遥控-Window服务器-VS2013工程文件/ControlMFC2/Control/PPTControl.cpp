#include<iostream>
#include "PPTControl.h"
using namespace std;

void PPTControl::control(string button){
	if(button == "play")
		play();
	else if (button == "next")
		next();
	else if(button == "previous")
		pageup();
	else if(button == "quit")
		quit();
}

//ģ��������µ���
void PPTControl::next()
{
keybd_event(VK_NEXT, 0, 0 ,0);
keybd_event(VK_NEXT, 0, KEYEVENTF_KEYUP,0);
}

//ģ�ⰴ��'F5'��
void PPTControl::play()
{
keybd_event(VK_F5,(BYTE)0, 0 ,0);
keybd_event(VK_F5, (BYTE)0, KEYEVENTF_KEYUP,0);
}

//ģ�ⰴ��page up
void PPTControl::pageup()
{
keybd_event(VK_PRIOR, 0, 0 ,0);
keybd_event(VK_PRIOR, 0, KEYEVENTF_KEYUP,0);
}

void PPTControl::quit()
{
keybd_event(VK_ESCAPE, (BYTE)0, 0 ,0);
keybd_event(VK_ESCAPE, (BYTE)0, KEYEVENTF_KEYUP,0);
}
