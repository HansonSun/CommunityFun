
#include "DuiButton.h"


DuiButton::DuiButton(CString path, int x, int y, int w, int h) 
{
	img_path = path;
	 top_x=x;
	 top_y=y;
	 width=w;
	 height=h;
	 botoom_x=top_x+width;
	 botoom_y=top_y+height;
	 m_pImg = new Image(path);
}


DuiButton::DuiButton()
{
}

DuiButton::~DuiButton()
{
}

int DuiButton::is_in_rect(CPoint point ){
	if (point.x >= top_x &&	point.x <= botoom_x  && point.y >= top_y && point.y <= botoom_y)
		return 1;
	else
		return 0;
}