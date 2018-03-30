#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<Mmsystem.h> 
using namespace std;
class DayControl{
	public:
		void control(string button);    //根据按键信息选择调用函数
	private:
		void shutdown();				//关机
		void shutdownafter30();			
		void shutdownafter60();
		void shutdownafter90();
		void cancelshutdown();			//取消关机
		void rebot();					//重启
		void logout();					//注销
		void sleep();					//待机
		void volumeUp();				//音量+
		void volomeDown();				//音量-
};

