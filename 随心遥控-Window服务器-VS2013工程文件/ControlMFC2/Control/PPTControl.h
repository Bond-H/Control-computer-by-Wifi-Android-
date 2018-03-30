#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<stdio.h>
#include<Mmsystem.h>
using namespace std;
class PPTControl{
	public:
		void control(string button);    //根据按键信息选择调用函数
	private:
	
		 void play();					//播放、暂停
		 void next();					//下一页
		 void pageup();					//上一页
		 void quit();					//退出
};