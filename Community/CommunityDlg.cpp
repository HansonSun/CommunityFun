
// CommunityDlg.cpp : ʵ���ļ�
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


// CCommunityDlg �Ի���

//UINT Omainwnd(LPVOID pParama);		//�������������			

CRect   cli_rect;			//ȫ���ͻ����Ĵ�С
HWND    MyMainWnd;			//��������ȫ������
CWnd*   MyMainPtr;          //�����洰��ָ��

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


// CCommunityDlg ��Ϣ�������

BOOL CCommunityDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);  //ȫ����ʾ

	//mainlayout.setup_layout();

	AfxBeginThread(Omainwnd, "greeting");

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCommunityDlg::OnPaint()
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
		/*CPaintDC dc(this);

		Graphics graphics(dc.GetSafeHdc());
		graphics.SetSmoothingMode(SmoothingModeAntiAlias);
		Pen newPen(Color(0, 255, 255), 2);

		graphics.DrawLine(&newPen, 0, 0, 500, 500);*/
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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

	//���ذ���ҽ����ťͼƬ
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




//�������뺯��
void  CCommunityDlg::index_import()
{

	
}



void CCommunityDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CPoint mv_point = point;

	CDialogEx::OnMouseMove(nFlags, point);
}


void CCommunityDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	/*if ( mainlayout.button_map["AnKangYiYang"].is_in_rect(point ) ) {
		MessageBox(_T("fff"));
		}*/
	


	CDialogEx::OnLButtonDown(nFlags, point);
}
