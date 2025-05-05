#include "ActionSwitchToPlayMode.h"
#include "ApplicationManager.h"
 
ActionSwitchToPlayMode::ActionSwitchToPlayMode(ApplicationManager* pApp):Action(pApp){}
void ActionSwitchToPlayMode::ReadActionParameters(){}
void ActionSwitchToPlayMode::Execute() {
	pManager->GetOutput()->PrintMessage("switching to play mode");
	pManager->GetInput()->SwitchToPlayMode();
}