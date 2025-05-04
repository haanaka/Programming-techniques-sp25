#include "Rotate.h"
#include "Rotate.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

Rotate::Rotate(ApplicationManager* pApp) : Action(pApp)
{
};

void Rotate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Rotate: Select one figure to rotate clockwise by 90 degrees");
}
void Rotate::Execute()
{
    int x, y;
	ReadActionParameters();
    CFigure* SelectedFig = pManager->getSelectedFigure();
    Output* pOut = pManager->GetOutput();
    if (SelectedFig != NULL)
    {
        bool didRotate = SelectedFig->Rotation();
        pManager->UpdateInterface();

        if (didRotate)
        {
            pOut->PrintMessage("Figure rotated successfully.");

            pManager->GetInput()->GetPointClicked(x, y); // Wait for user to click before clearing the message
        }
        else
        {
            pOut->PrintMessage("No effect on this shape.");
            pManager->GetInput()->GetPointClicked(x, y); // Wait for user to click before clearing the message
        }
    }
    else
    {
        pOut->PrintMessage("Select exactly one figure to rotate.");
    }
}
