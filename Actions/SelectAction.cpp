#include "SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"


SelectAction::SelectAction(ApplicationManager* pApp) : Action(pApp)
{
	SelectedFig = NULL; // Initialize the selected figure to NULL
}

SelectAction::~SelectAction()
{	// Destructor
}

void SelectAction::ReadActionParameters()
{

}

void SelectAction::Execute()
{

	// Get the point clicked by the user
	Point p;
	pManager->GetOutput()->PrintMessage("click a shape to select");
	pManager->GetInput()->GetPointClicked(p.x, p.y);
	// Select the figure at the clicked point
	SelectedFig = pManager->selectFigure(p.x, p.y);
}