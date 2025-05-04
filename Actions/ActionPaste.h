#pragma once
#include "Action.h"

class ActionPaste :public Action
{
public:
	ActionPaste(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	~ActionPaste();
};

