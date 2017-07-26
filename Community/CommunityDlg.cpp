
// CommunityDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Community.h"
#include "CommunityDlg.h"
#include "afxdialogex.h"
#include <map> 
#include <iostream>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CCommunityDlg 对话框

//UINT Omainwnd(LPVOID pParama);		//主界面进程声明			

CRect   cli_rect;			//全屏客户区的大小
HWND    MyMainWnd;			//主界面句柄全局声明
CWnd*   MyMainPtr;          //主界面窗口指针

map<string, string> mainwin_map;


CCommunityDlg::CCommunityDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCommunityDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCommunityDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCommunityDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CCommunityDlg 消息处理程序

BOOL CCommunityDlg::OnInitDialog()
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);  //全屏显示

	//mainlayout.setup_layout();

	AfxBeginThread(Omainwnd, "greeting");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCommunityDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCommunityDlg::OnPaint()
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
		/*CPaintDC dc(this);

		Graphics graphics(dc.GetSafeHdc());
		graphics.SetSmoothingMode(SmoothingModeAntiAlias);
		Pen newPen(Color(0, 255, 255), 2);

		graphics.DrawLine(&newPen, 0, 0, 500, 500);*/
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCommunityDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



UINT  CCommunityDlg::Omainwnd(LPVOID pParama)
{
	DlgLayout mainlayout;
	mainlayout.setup_layout();

	CClientDC dc(MyMainPtr);
	CRect cli_rect(0, 0, 1920, 1080);
	//MyMainPtr->GetClientRect(&cli_rect);

	//加载安康医养按钮图片
	CString but_com_pre("a.png");
	Image but_akyy(but_com_pre);


	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	CBitmap memBMP;
	memBMP.CreateCompatibleBitmap(&dc, cli_rect.Width(), cli_rect.Height());
	memDC.SelectObject(&memBMP);
	Graphics *buffer = Graphics::FromHDC(memDC.GetSafeHdc());


	while (1)
	{
		buffer->DrawImage(mainlayout.button_map["AnKangYiYang"].m_pImg, Rect(0, 0, 100, 100));
		dc.BitBlt(0, 0, cli_rect.Width(), cli_rect.Height(), &memDC, 0, 0, SRCCOPY);

	}

	return 0;
}




//参数导入函数
void  CCommunityDlg::index_import()
{

	
}



void CCommunityDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CPoint mv_point = point;

	CDialogEx::OnMouseMove(nFlags, point);
}


void CCommunityDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	/*if ( mainlayout.button_map["AnKangYiYang"].is_in_rect(point ) ) {
		MessageBox(_T("fff"));
		}*/
	


	CDialogEx::OnLButtonDown(nFlags, point);
}
