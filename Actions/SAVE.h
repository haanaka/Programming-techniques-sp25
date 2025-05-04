#ifndef SAVEAction_h
#define SAVEAction_h
#pragma once
#include "Action.h"

class SAVEAction : public Action
{
	string S;
public:
	SAVEAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();
	string getcolorname(color c);

	virtual void Execute();

};

#endif

