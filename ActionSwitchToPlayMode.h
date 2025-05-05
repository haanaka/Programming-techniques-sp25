#pragma once
#include "Actions\Action.h"
class ActionSwitchToPlayMode : public Action
{
public:
	ActionSwitchToPlayMode(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

