#ifndef SAVEAction_h
#define SAVEAction_h
#pragma once
#include "Action.h"

class SAVEAction : public Action
{
	string n;
public:
	SAVEAction(ApplicationManager* pApp);

	void ReadActionParameters();


	void Execute();

};

#endif

