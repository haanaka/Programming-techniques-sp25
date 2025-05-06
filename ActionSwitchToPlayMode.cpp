#include "ActionSwitchToPlayMode.h"
#include "ApplicationManager.h"


ActionSwitchToPlayMode::ActionSwitchToPlayMode(ApplicationManager* pApp) :Action(pApp) {}
void ActionSwitchToPlayMode::ReadActionParameters() {}

void ActionSwitchToPlayMode::Execute()
{
	pManager->SwitchToPlayMode();


	/*pManager->GetInput()->SwitchToPlayMode();*/
}