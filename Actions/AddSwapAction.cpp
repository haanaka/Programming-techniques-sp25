#include "AddSwapAction.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"
#include"SelectAction.h"

AddSwapAction::AddSwapAction(ApplicationManager* pApp) :Action(pApp)
{
	FirstFigure = nullptr;
	SecondFigure = nullptr;
}
void AddSwapAction::ReadActionParameters()
{
	
}
void AddSwapAction::Execute()
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
	FirstFigure->SetSelected(false);
	SecondFigure->SetSelected(false);
	pManager->UpdateInterface();
	if (!FirstFigure || !SecondFigure)
		return;
		
	Point center1;
	Point center2;
	FirstFigure->getCenter(center1);
   SecondFigure->getCenter(center2);
	FirstFigure->MoveTo(center2);
	SecondFigure->MoveTo(center1);
   
	pManager->GetOutput()->PrintMessage("No figure selected, please select a figure");
	pManager->UpdateInterface();
	pOut->PrintMessage("Figure swapped");
	pOut->ClearDrawArea();
}
AddSwapAction::~AddSwapAction()
{
}