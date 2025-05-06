#pragma once
#include "Actions\Action.h"
class ActionSwitchToPlayMode : public Action
{
public:
	ActionSwitchToPlayMode(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute() override;
};

