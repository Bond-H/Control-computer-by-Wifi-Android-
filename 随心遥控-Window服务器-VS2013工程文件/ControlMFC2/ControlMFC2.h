
// ControlMFC2.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CControlMFC2App:
// �йش����ʵ�֣������ ControlMFC2.cpp
//

class CControlMFC2App : public CWinApp
{
public:
	CControlMFC2App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	DECLARE_MESSAGE_MAP()
};

extern CControlMFC2App theApp;