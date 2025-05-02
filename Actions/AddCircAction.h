#pragma once
#include "Action.h"
class AddCircAction:public Action
{
private:
	Point p1;
	Point p2;
	int radius;
	GfxInfo CircleGfxInfo;
public:	
	AddCircAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	
};

