#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{
}
void ExitAction::ReadActionParameters()
{
	//No parameters to read from the user
}
void ExitAction::Execute()
{
	//Get a Pointer to the Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Are you sure you want to exit? (y/n)");
	string answer = pIn->GetString(pOut);
	if (answer == "y" || answer == "Y") {
		pOut->PrintMessage("Exiting the application...");
	}
	else {
		pOut->PrintMessage("Exit cancelled.");
	}
	
	
}