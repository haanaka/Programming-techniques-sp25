#include "ActionSwitchToDrawMode.h"
#include "ApplicationManager.h"

ActionSwitchToDrawMode::ActionSwitchToDrawMode(ApplicationManager* pApp)
    : Action(pApp)
{
}

void ActionSwitchToDrawMode::ReadActionParameters()
{

}

void ActionSwitchToDrawMode::Execute()
{
    pManager->SwitchToDrawMode();
}
