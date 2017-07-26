
#include "DlgLayout.h"


DlgLayout::DlgLayout()
{
}


void DlgLayout:: setup_layout(){

	AllocConsole();
	freopen("conout$", "w", stdout);
	cout << "hello";
	string fullPath_cs = "config\\Community.xml";//��ȡ�����ļ�·��


	TiXmlDocument *doc = new TiXmlDocument;
	doc->LoadFile(fullPath_cs.c_str());

	TiXmlElement  *RootElem = doc->RootElement();  //��ø��ڵ�
	TiXmlElement *LayoutManger = RootElem->FirstChildElement("���ֹ���"); //ָ�򲼾ֹ���
	TiXmlElement *Layout_Mian = LayoutManger->FirstChildElement("������"); //ָ��������

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
