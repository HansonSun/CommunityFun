
#include "DlgLayout.h"


DlgLayout::DlgLayout()
{
}


void DlgLayout:: setup_layout(){

	AllocConsole();
	freopen("conout$", "w", stdout);
	cout << "hello";
	string fullPath_cs = "config\\Community.xml";//获取配置文件路径


	TiXmlDocument *doc = new TiXmlDocument;
	doc->LoadFile(fullPath_cs.c_str());

	TiXmlElement  *RootElem = doc->RootElement();  //获得根节点
	TiXmlElement *LayoutManger = RootElem->FirstChildElement("布局管理"); //指向布局管理
	TiXmlElement *Layout_Mian = LayoutManger->FirstChildElement("主界面"); //指向主界面

	TiXmlElement *btn = Layout_Mian->FirstChildElement();

	for (btn; btn; btn = btn->NextSiblingElement()){
		string  name(btn->Attribute("name"));
		int top_x = atoi(btn->Attribute("top_x"));
		int top_y = atoi(btn->Attribute("top_y"));
		int width = atoi(btn->Attribute("width"));
		int height = atoi(btn->Attribute("height"));
		CString pic_path(btn->Attribute("pic"));
		this->button_map[name] = DuiButton(pic_path, top_x, top_y, width, height);

	}

	cout << button_map["AnKangYiYang"].top_x << endl;
	FreeConsole();
}

DlgLayout::~DlgLayout()
{
}
