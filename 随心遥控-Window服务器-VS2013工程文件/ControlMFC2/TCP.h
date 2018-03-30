#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef TCP_H
#define TCP_H
#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <process.h>
#include "Control\Control.h"
#include "stdafx.h"

#include "afxdialogex.h"
#pragma  comment(lib,"ws2_32.lib")

using namespace std;

void RestoreData(string& page, string& botton, int&volunme, char *buf);
void TCPServer();
string page="", botton="";
int volunme=0;
Control *control = new Control();

/************************************************************
** ������:TCPServer
** ����������TCP���񲢵ȴ��ͻ��˽������ӣ����������ͽ���SOCKET����
** SOCKET���յ����ݴ������Ϊbuf���ַ����У����ú���retoreData��ԭԭʼ����
*************************************************************/

char a[100];
char b[100];
SOCKET socket2;

//�����ֻ����͵���Ϣ
unsigned __stdcall recive(void* p){
	MessageBox(NULL,_T("���ӳɹ�"),_T("����ң��)"),MB_OK);
	while (true){
		memset(a, 0, 100);

		int aa = recv(socket2, a, 100, 0);
		if (aa == SOCKET_ERROR || aa == 0){
			MessageBox(NULL,_T("����ʧ�ܣ��Ͽ�����"),_T("��������)"),MB_ICONHAND);
			break;
		}
		else
		if (aa>0){
			a[aa] = '\0';
			//char* a2 = U2G(a);

			RestoreData(page, botton, volunme, a);//�������
			printf("%s\n", a);
			bool success = control->control(page, botton, volunme);
			//printf("%s %s\n", page, botton);
			cout <<"page:" <<page<<endl<<"botton:" << botton << endl;

			send(socket2, a, 100, 0);
		}
		aa = 0;
	}
	return 0;
}


//������Ϣ���ֻ�
unsigned __stdcall send(void* p){
	while (scanf_s("%s", b) && strlen(b)>0){
		int aa = send(socket2, b, 100, 0);
		memset(b, 0, 100);
		if (aa == SOCKET_ERROR || aa == 0)
			printf("%s\n", "send failed");     //����������ر��׽���sock��
		else if (aa > 0) {
			printf("%s", b);                    // ��ʾ�����ַ��ɹ�
		}
	}
	return 0;
}

//wstring���ֽڲ�Ϊ0������FALSE
 BOOL WStringToString(const std::wstring &wstr,std::string &str)
 {    
     int nLen = (int)wstr.length();    
     str.resize(nLen,' ');
 
     int nResult = WideCharToMultiByte(CP_ACP,0,(LPCWSTR)wstr.c_str(),nLen,(LPSTR)str.c_str(),nLen,NULL,NULL);
 
     if (nResult == 0)
     {
         return FALSE;
     }
 
     return TRUE;
 }
//�����ļ����ֻ�
bool SendFile(wstring filePathtemp){//, string fileName
	/*string filepath = "C:\\Users\\I\\Desktop\\TCPServer";
	string filename;
	getchar();
	cout << "�����ļ���,���س�����" << endl;
	getline(cin, filename);
	cout << filename << endl;*/
	string filePath;
	WStringToString(filePathtemp,filePath);
	ifstream file;
	string filename;
	int indexN= filePath.find_last_of('\\');
	filename = filePath.substr(indexN+1);
	string filepath = filePath ;//+ '\\' + filename;
	file.open(filepath.c_str(), ios::binary | ios::ate);
	if (file.fail()){
		MessageBox(NULL,_T("���ļ�ʧ��"),_T("�ļ�����"),MB_OK);
		//cout << "���ļ�ʧ��" << endl;
		//sendfinish();
		return false;
	}
	int filesize = file.tellg();
	file.seekg(0, ios::beg);
	if (filesize>210000000){
		cout << "ѡ����ļ�̫��֧�ֵ�����ļ�Ϊ200M��" << endl;
		return false;
	}
	//���ͱ�־�ַ���
	char mark[100];
	memset(mark, 0, 100);
	string marks = "2557893640";
	for (int i = 0; i<marks.size(); i++)
		mark[i] = marks[i];
	mark[marks.size()] = '\0';
	int aa = send(socket2, mark, 100, 0);
	//�����ļ��� 
	int filenamesize = filename.size();
	char sendname[100];
	memset(sendname, 0, 100);
	for (int i = 0; i < filenamesize; i++)
		sendname[i] = filename[i];
	sendname[filenamesize] = '\0';
	aa = send(socket2, sendname, 100, 0);
	if (aa == SOCKET_ERROR || aa == 0){
		printf("%s\n", "send failed");     //����������ر��׽���sock��
		return false;
	}
	//�����ļ���С 
	char filesizes[100];
	memset(filesizes, 0, 100);
	_itoa_s(filesize, filesizes, 10);
	int filesizel = strlen(filesizes);
	aa = send(socket2, filesizes, 100, 0);
	if (aa == SOCKET_ERROR || aa == 0){
		printf("%s\n", "send failed");     //����������ر��׽���sock��
		return false;
	}
	//�����ļ����� 
	char* filebuffer = new char[filesize];
	file.read(filebuffer, filesize);
	aa = send(socket2, filebuffer, filesize, 0);
	if (aa == SOCKET_ERROR || aa == 0){
		printf("%s\n", "send failed");     //����������ر��׽���sock��
		return false;
	}
	MessageBox(NULL,_T("�������"),_T("�ļ�����)"),MB_OK);
	delete[] filebuffer;
	file.close();

	return true;
}

//void TCPServer()
unsigned __stdcall TCPServer(void* p)
{
	HANDLE hThread[2];
	//��ʼ��WSA
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0){
		return 1;
	}
	//�����׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	if (sockSrv == INVALID_SOCKET)
	{
		MessageBox(NULL,_T("socket error"),_T("����"),MB_ICONHAND);
		return 2;
	}
	//��IP�Ͷ˿�
	SOCKADDR_IN addrSrv;//server IP
	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(8080);//port
	if (bind(sockSrv, (SOCKADDR *)&addrSrv, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		MessageBox(NULL,_T("bind error !"),_T("����"),MB_ICONHAND);
	}


	//��ʼ����
	if (listen(sockSrv, 5) == SOCKET_ERROR)
	{
		MessageBox(NULL,_T("listen error !"),_T("����"),MB_ICONHAND);
		return 2;
	}

	SOCKADDR_IN addrClient;//client IP
	int len = sizeof(SOCKADDR);
	int buflenght = 200000;

	//������������Ӻ�vb�����Ӿͺ�



	while (true){
		socket2 = accept(sockSrv, (SOCKADDR *)&addrClient, &len);
		if (socket2 == INVALID_SOCKET)
		{
			MessageBox(NULL,_T("accept error !"),_T("����"),MB_ICONHAND);
		}
		setsockopt(socket2, SOL_SOCKET, SO_SNDBUF, (char*)&buflenght, buflenght);
		hThread[0] = (HANDLE)_beginthreadex(NULL, 0, &recive, 0, 0, NULL);
		hThread[1] = (HANDLE)_beginthreadex(NULL, 0, &send, 0, 0, NULL);
	}

	closesocket(socket2);
	closesocket(sockSrv);
	WSACleanup();
	return 0;
}

/**************************************************
** ������:restoreData
** ����: �ַ���buf---�Ǵ�SOCKET���յ��ַ���
** �� ��:page,button,volunm
** page---���ַ���buf��ȡ������page����
** button---���ַ���buf��ȡ������button����
** volunm---���ַ���buf��ȡ������������С
** ����������SOCKET���͹������ַ�����ԭԭʼ��Ϣ
����TCP�����ڵ���
** ȫ�ֱ���:��
**************************************************/
void RestoreData(string& page, string& botton, int&volunme, char *buf){
	string str = buf;
	int index1, index2, index3;
	char c = ';';
	index1 = str.find(c);
	if (index1){
		page = str.substr( 0,index1);
	}
	str.erase(0,index1+1);
	index2 = str.find( c);
	if (index2){
		botton = str.substr(0,index2);
	}
	str.erase(0,index2+1);
	index3 = str.find(c);
	if (index3){
		volunme = atoi(str.substr(0,index3 ).c_str());
	}
	str.erase(0,index3+1);

}
#endif
