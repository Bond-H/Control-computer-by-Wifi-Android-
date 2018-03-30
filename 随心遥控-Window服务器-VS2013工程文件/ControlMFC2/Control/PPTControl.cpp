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

//模拟左键按下弹起
void PPTControl::next()
{
keybd_event(VK_NEXT, 0, 0 ,0);
keybd_event(VK_NEXT, 0, KEYEVENTF_KEYUP,0);
}

//模拟按下'F5'键
void PPTControl::play()
{
keybd_event(VK_F5,(BYTE)0, 0 ,0);
keybd_event(VK_F5, (BYTE)0, KEYEVENTF_KEYUP,0);
}

//模拟按下page up
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
