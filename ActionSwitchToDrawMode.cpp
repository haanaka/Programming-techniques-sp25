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
    Output* pOut = pManager->GetOutput();


    pOut->ClearStatusBar();

    // Create Draw Mode toolbar
    pOut->CreateDrawToolBar();

	//  Printing a message to the status bar
    pOut->PrintMessage("Switched to Draw Mode");
}
