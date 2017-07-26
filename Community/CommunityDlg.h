
// CommunityDlg.h : ͷ�ļ�
//

#pragma once
#include "config.h"

#include "tinyxml/tinystr.h"
#include "tinyxml/tinyxml.h"

#include "DuiButton.h"
#include "DlgLayout.h"


// CCommunityDlg �Ի���
class CCommunityDlg : public CDialogEx
{
// ����
public:
	CCommunityDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void index_import();
	//DlgLayout mainlayout;
// �Ի�������

	static UINT Omainwnd(LPVOID pParama);
	enum { IDD = IDD_COMMUNITY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
