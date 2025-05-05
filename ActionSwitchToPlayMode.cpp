#include "ActionSwitchToPlayMode.h"
#include "ApplicationManager.h"

 
ActionSwitchToPlayMode::ActionSwitchToPlayMode(ApplicationManager* pApp):Action(pApp){}
void ActionSwitchToPlayMode::ReadActionParameters(){}
void ActionSwitchToPlayMode::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pManager->GetOutput()->PrintMessage("switching to play mode");
	pOut->CreatePlayToolBar();
	pManager->UpdateInterface();
	
/*pManager->GetInput()->SwitchToPlayMode();*/
}