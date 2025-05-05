#include "LoadAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <iostream>

LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}


void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter the file name to load from");
	n = pIn->GetString(pOut);
}


void LoadAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ifstream file(n);
	if (!file.is_open()) {
		pOut->PrintMessage("File not found");
		return;
	}

}
