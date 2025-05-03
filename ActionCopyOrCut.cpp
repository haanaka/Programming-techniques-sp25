#include "Actions\ActionCopyOrCut.h"

void ActionCopyOrCut::ReadActionParameters()
{
}
ActionCopyOrCut::ActionCopyOrCut(ApplicationManager* pApp,bool CopyOrCut) : Action(pApp)
{
	this->copyorcut = CopyOrCut;
	Clipboard = pManager->GetClipboard();
}

void ActionCopyOrCut::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (copyorcut)
	pOut->PrintMessage("Select a figure to copy");
	else 
	pOut->PrintMessage("Select a figure to cut");
	int x, y;
	pIn->GetPointClicked(x, y);
	Clipboard = pManager->SelectClipboardFigure(x, y);
	if (Clipboard != NULL) {
		if (pManager->getSelectedFigure() != nullptr) {
		pManager->getSelectedFigure()->SetSelected(false);
		pManager->getSelectedFigure()->Draw(pOut);
		}
		Clipboard->SetSelected(true);
	}
	else {
		pOut->PrintMessage("No figure selected");
	}
	pOut->PrintMessage("Figure copied to clipboard");
	pIn->GetPointClicked(x, y);
}