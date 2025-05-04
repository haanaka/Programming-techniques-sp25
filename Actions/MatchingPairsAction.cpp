#include "MatchingPairsAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include "..\Figures\CFigure.h"
#include"..\Actions\SAVE.h"
#include "..\DEFS.h"
MatchingPairsAction::MatchingPairsAction(ApplicationManager* pApp) : Action(pApp),score(0)
{

	FirstFigure = nullptr;
	SecondFigure = nullptr;
}	
void MatchingPairsAction::ReadActionParameters()
{
	// No parameters to read for this action
}
void MatchingPairsAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point clickpoint;
	pOut->PrintMessage("Select the first figure to swap");
	while (true) {
		pIn->GetPointClicked(clickpoint.x, clickpoint.y);
		FirstFigure = pManager->selectFigure(clickpoint.x, clickpoint.y);
		if (FirstFigure) {
			FirstFigure->SetSelected(true);
			pManager->UpdateInterface();
			break;
		}
		pOut->PrintMessage("No figure selected, please select a figure");
	}
	pOut->PrintMessage("Select the second figure to swap");
	while (true) {
		pIn->GetPointClicked(clickpoint.x, clickpoint.y);
		SecondFigure = pManager->selectFigure(clickpoint.x, clickpoint.y);
		if (SecondFigure) {
			SecondFigure->SetSelected(true);
			pManager->UpdateInterface();
			break;
		}
		pOut->PrintMessage("No figure selected, please select a figure");
	}
	if (!FirstFigure && !SecondFigure)
		return;
  
	bool isMatch = (FirstFigure->getType() == SecondFigure->getType()) ||
		(FirstFigure->getdrawcolor() == SecondFigure->getdrawcolor()) ||
		(FirstFigure->getfillcolor() == SecondFigure->getfillcolor());
	if (isMatch) {
		score++;
		pOut->PrintMessage(" Excellent Correct! Score:" + to_string(score));
	}
	else {
		score--;
		pOut->PrintMessage(" Wrong! score: " + to_string(score));
	}
}



