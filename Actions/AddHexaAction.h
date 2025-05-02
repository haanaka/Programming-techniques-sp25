#pragma once
#include "Action.h"
class AddHexaAction : public Action
{
private:
	Point center; 
	GfxInfo HexaGfxInfo; 
public:
	AddHexaAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	
};

