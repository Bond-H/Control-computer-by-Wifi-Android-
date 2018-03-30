//#define _WIN32_WINNT 0x500
#define _AFXDLL
 
#include<iostream>
//#include <winuser.h>
#include<string>
#include<cstring>
#include<stdio.h>
#include<Mmsystem.h> // waveOutSetVolumeͷ�ļ�
using namespace std;


class MediaControl
{
public:
	void control(string button,int volume);    //���ݰ�����Ϣѡ����ú���

private:
	void start();       //���ݵ�ǰ��״̬ѡ��ʼ/��ͣ
	void next();        //��һ��
	void previous();    //��һ��

	//��������Ǹ���������(��������ȥһֱ�������ɿ�,�ɿ�������Ϣ����ֹͣ)
	void forward();     //�������
	void backward();    //��������
	void stopward();    //ֹͣ��������

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
    cout<<"��������"<<endl;
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
