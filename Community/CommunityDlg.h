
// CommunityDlg.h : 头文件
//

#pragma once
#include "config.h"

#include "tinyxml/tinystr.h"
#include "tinyxml/tinyxml.h"

#include "DuiButton.h"
#include "DlgLayout.h"


// CCommunityDlg 对话框
class CCommunityDlg : public CDialogEx
{
// 构造
public:
	CCommunityDlg(CWnd* pParent = NULL);	// 标准构造函数
	void index_import();
	//DlgLayout mainlayout;
// 对话框数据

	static UINT Omainwnd(LPVOID pParama);
	enum { IDD = IDD_COMMUNITY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
