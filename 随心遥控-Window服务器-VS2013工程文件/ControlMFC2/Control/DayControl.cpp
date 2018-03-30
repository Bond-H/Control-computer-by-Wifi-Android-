#include "DayControl.h"
#include<cstdlib>
#include<iostream>
#include"sound.h"
using namespace std;

void DayControl::control(string button)
{
	if(button == "guanji")
		shutdown();
	else if(button == "cancelshutdown")
		cancelshutdown();
	else if(button == "rebot")
		rebot();
	else if(button == "logout")
		logout();
	else if(button == "guanping")
		sleep();
	else if(button == "yinliangup" )
		volumeUp();
	else if(button == "yinliangdown")
		volomeDown();
}

void DayControl::shutdown()
{
	cout<<"shutdown"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -s -t 0");
	//return 0;
}
void DayControl::shutdownafter30()
{
	cout<<"shutdown in 30s"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -s -t 1800");
	//return 0;
}
void DayControl::shutdownafter60()
{
	cout<<"shutdown in 60s"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -s -t 3600");
	//return 0;
}
void DayControl::shutdownafter90()
{
	cout<<"shutdown in 90s"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -s -t 5400");
	//return 0;
}
void DayControl::cancelshutdown()
{
	cout<<"cancel shutdown"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -a");
}
void DayControl::rebot()
{
	cout<<"rebot"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -r");
	//return 0;
}
void DayControl::logout()
{
	cout<<"logout"<<endl;
	Sleep(1000);
	system("C:\\Windows\\System32\\shutdown -l");
	//return 0;
}
void DayControl::sleep()
{
	cout<<"sleep"<<endl;
	Sleep(1000);
	system("powercfg -h off");
	system("rundll32.exe powrprof.dll,SetSuspendState");
	//return 0;
}
void DayControl::volumeUp(){ sound("volumeUp"); }

void DayControl::volomeDown(){ sound("volumeDown"); }
