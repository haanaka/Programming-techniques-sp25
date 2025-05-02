#pragma once
#include"Action.h"
class AddSquAction : public Action
{
private:
	Point P1; 
	GfxInfo SquGfxinfo;
public:
	AddSquAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};

