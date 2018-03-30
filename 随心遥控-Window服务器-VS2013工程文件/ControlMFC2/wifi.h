#include "stdafx.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
class WiFi{
public:
	char* netstate;
	char* detect;
	bool start_wifi(CString user, CString pass){
		ofstream out("wifi.bat");
		out << "netsh wlan set hostednetwork mode=allow ssid=" << user << " key=" << pass << endl;
		out << "netsh wlan start hostednetwork" << endl;
		bool ex = ShellExecute(NULL, _T("open"), _T("wifi.bat"), NULL, NULL, SW_HIDE);
		isStart = true;
		return ex;
	}
	bool stop_wifi(){
		bool ex = WinExec("netsh wlan stop hostednetwork", SW_NORMAL);
		isStart - false;
		return ex;
	}
private:
	bool isStart = false;
};
