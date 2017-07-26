#pragma once
#include "stdafx.h"
#include "DuiButton.h"
#include <map>
#include <iostream>
#include "tinyxml/tinystr.h"
#include "tinyxml/tinyxml.h"

using namespace std;



class DlgLayout
{
public:
	DlgLayout();
	~DlgLayout();
	void DlgLayout::setup_layout();
	map<string ,DuiButton> button_map;

};

