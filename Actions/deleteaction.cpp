#include "dELETEAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

dELETEAction::dELETEAction(ApplicationManager* pApp) : Action(pApp)
{
	
}

void dELETEAction::ReadActionParameters()
{

}

void dELETEAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->getSelectedFigure()){
		pOut->PrintMessage("Figure Deleted");
		pManager->deleteselectedfigure();
	}
	else
		pOut->PrintMessage("No figure selected");
}
void dELETEAction::Execute1()
{
	Output* pOut = pManager->GetOutput();

	if (pManager->getCopyOrCut()) {
		pOut->PrintMessage("Figure Deleted");
		pManager->deleteClipboard();
	}
	else
		pOut->PrintMessage("No figure selected");

}
