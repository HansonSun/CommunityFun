#pragma once
#include "stdafx.h"

//#include <>
class DuiButton
{
public:
	DuiButton(CString path,int x, int y, int w, int h);
	DuiButton();
	~DuiButton();
	CString img_path;
	int top_x;
	int top_y;
	int width;
	int height;
	int botoom_x;
	int botoom_y;
	Image *m_pImg;


	int  is_in_rect(CPoint point);
};

