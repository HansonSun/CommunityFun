
// Community.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCommunityApp: 
// �йش����ʵ�֣������ Community.cpp
//

class CCommunityApp : public CWinApp
{
public:
	CCommunityApp();

// ��д
public:
	virtual BOOL InitInstance();
	GdiplusStartupInput   m_GdiplusStartupInput;
	ULONG_PTR               m_GdiplusToken;
// ʵ��


	DECLARE_MESSAGE_MAP()
};

extern CCommunityApp theApp;