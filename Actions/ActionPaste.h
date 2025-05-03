#pragma once
#include "Action.h"

class ActionPaste :public Action
{
	ApplicationManager* pManager;
public:
	ActionPaste(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~ActionPaste();
};

