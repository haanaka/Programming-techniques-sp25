#pragma once
#include "Actions\Action.h"
class ActionSwitchToDrawMode : public Action
{
public:
    ActionSwitchToDrawMode(ApplicationManager* pApp);
    virtual void ReadActionParameters() override;
    virtual void Execute() override;
};

