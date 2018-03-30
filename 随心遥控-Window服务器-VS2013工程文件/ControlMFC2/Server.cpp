
// ControlMFC2Dlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// Server 对话框
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


// Server 消息处理程序

BOOL Server::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Server::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR Server::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Server::OnBnClickedButton1()
{
	// 设置过滤器   
    TCHAR szFilter[] = _T("所有文件(*.*)|*.*||");   
    // 构造打开文件对话框   
    CFileDialog fileDlg(TRUE, _T(""), NULL, 0, szFilter, this);   
    CString strFilePath;   
  
    // 显示打开文件对话框   
    if (IDOK == fileDlg.DoModal())   
    {   
        // 如果点击了文件对话框上的“打开”按钮，则将选择的文件路径显示到编辑框里   
        strFilePath = fileDlg.GetPathName();
        SetDlgItemText(IDC_MFCEDITBROWSE1, strFilePath);
		
    }   
}



void Server::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFilePath;  
	GetDlgItemText(IDC_MFCEDITBROWSE1,strFilePath);
	std::wstring temp(strFilePath);
	SendFile(temp);
}
	
	


void Server::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	HANDLE hThread;
	hThread = (HANDLE)_beginthreadex(NULL, 0, &TCPServer, 0, 0, NULL);
	MessageBox(_T("服务器已开启"),_T("服务器"),MB_OK);
}


void Server::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString user,pass;  
	GetDlgItemText(IDC_EDIT1,user);
	GetDlgItemText(IDC_EDIT2,pass);
	int a=pass.GetLength();
	if (a < 8)
		MessageBox(_T("请填写新建无线网络名称或密码且密码至少8位"), _T("错误"), MB_ICONHAND);
	else
		wifi.start_wifi(user,pass);
}


void Server::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
}
