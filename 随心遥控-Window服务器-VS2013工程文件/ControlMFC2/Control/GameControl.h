//#define _WIN32_WINNT 0x500 
 
#include<iostream>
//#include <winuser.h>
#include<stdio.h>   


class GameControl
{
public:
	void control(string button);    //根据按键信息选择调用函数

private:
	void select();
	void start();
	void up();
	void down();
	void left();
	void right();
	void X();
	void Y();
	void A();
	void B();
};

void GameControl::control(string button)
{
	if (button == "select")
		select();
	else if (button == "start")
		start();
	else if (button == "up")
		up();
	else if (button == "down")
		down();
	else if (button == "left")
		left();
	else if (button == "right")
		right();
	else if (button == "X")
		X();
	else if (button == "Y")
		Y();
	else if (button == "A")
		A();
	else if (button == "B")
		B();
}

void GameControl::select()
{
	keybd_event(VK_SHIFT, 0, 0, 0);                 // SHIFT
	keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::start()
{
	keybd_event(VK_RETURN, 0, 0, 0);                 // RETURN 
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::up()
{
	keybd_event(0x57, 0, 0, 0);                      // W键
	keybd_event(0x57, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::down()
{
	keybd_event(0x53, 0, 0, 0);                      // S键
	keybd_event(0x53, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::left()
{
	keybd_event(0x41, 0, 0, 0);                      // A键
	keybd_event(0x41, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::right()
{
	keybd_event(0x44, 0, 0, 0);                      // D键
	keybd_event(0x44, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::A()
{
	keybd_event(0x4A, 0, 0, 0);                      // J键
	keybd_event(0x4A, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::B()
{
	keybd_event(0x55, 0, 0, 0);                      // U键
	keybd_event(0x55, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::X()
{
	keybd_event(0x4B, 0, 0, 0);                      // K键
	keybd_event(0x4B, 0, KEYEVENTF_KEYUP, 0);
}

void GameControl::Y()
{
	keybd_event(0x49, 0, 0, 0);                      // I键
	keybd_event(0x49, 0, KEYEVENTF_KEYUP, 0);
}