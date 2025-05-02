#include "deleteaction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

deleteaction::deleteaction(ApplicationManager* pApp) : Action(pApp)
{
	
}

void deleteaction::ReadActionParameters()
{

}

void deleteaction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->getSelectedFigure() {
		pOut->PrintMessage("Figure Deleted");
		pManager->deleteselectedfigure();
	}
	else
	{
		pOut->PrintMessage("No figure selected");
	}
}
