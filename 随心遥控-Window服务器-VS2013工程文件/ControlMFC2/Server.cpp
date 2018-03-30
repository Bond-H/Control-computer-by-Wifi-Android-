
// ControlMFC2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ControlMFC2.h"
#include "Server.h"

#include "afxdialogex.h"
#include "TCP.h"

#include <string>
#include <atlconv.h>
#include<fstream>
#include<iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace std;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Server �Ի���
Server::Server(CWnd* pParent /*=NULL*/)
	: CDialogEx(Server::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDB_BITMAP1);
}

void Server::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Server, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Server::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Server::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &Server::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON2, &Server::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Server::OnBnClickedButton3)
END_MESSAGE_MAP()


// Server ��Ϣ�������

BOOL Server::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void Server::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void Server::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR Server::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Server::OnBnClickedButton1()
{
	// ���ù�����   
    TCHAR szFilter[] = _T("�����ļ�(*.*)|*.*||");   
    // ������ļ��Ի���   
    CFileDialog fileDlg(TRUE, _T(""), NULL, 0, szFilter, this);   
    CString strFilePath;   
  
    // ��ʾ���ļ��Ի���   
    if (IDOK == fileDlg.DoModal())   
    {   
        // ���������ļ��Ի����ϵġ��򿪡���ť����ѡ����ļ�·����ʾ���༭����   
        strFilePath = fileDlg.GetPathName();
        SetDlgItemText(IDC_MFCEDITBROWSE1, strFilePath);
		
    }   
}



void Server::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strFilePath;  
	GetDlgItemText(IDC_MFCEDITBROWSE1,strFilePath);
	std::wstring temp(strFilePath);
	SendFile(temp);
}
	
	


void Server::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HANDLE hThread;
	hThread = (HANDLE)_beginthreadex(NULL, 0, &TCPServer, 0, 0, NULL);
	MessageBox(_T("�������ѿ���"),_T("������"),MB_OK);
}


void Server::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CString user,pass;  
	GetDlgItemText(IDC_EDIT1,user);
	GetDlgItemText(IDC_EDIT2,pass);
	int a=pass.GetLength();
	if (a < 8)
		MessageBox(_T("����д�½������������ƻ���������������8λ"), _T("����"), MB_ICONHAND);
	else
		wifi.start_wifi(user,pass);
}


void Server::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
