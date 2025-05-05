#include "Rotate.h"
#include "Rotate.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Figures/CFigure.h"
#include "Figures/CHexagon.h"
Rotate::Rotate(ApplicationManager* pApp) : Action(pApp)
{
};
void Rotate::ReadActionParameters()
{

}
void Rotate::Execute()
{
    int x=0, y=0;
	ReadActionParameters();
	const int figlist = pManager->GetFigCount();
    CFigure* RotatedFigure=nullptr;
	CFigure** FigList=new CFigure* [figlist];
    for (int i = 0; i < figlist; i++) 
    {
        FigList[i] = pManager->getFigureI(i);
    }
  
    Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
    pOut->PrintMessage("Rotate: Select one figure to rotate clockwise by 90 degrees");
	pIn->GetPointClicked(x, y); // Wait for user to click
    for (int i = figlist - 1; i >= 0; i--)
    {
        if (FigList[i] != nullptr && FigList[i]->IsPointInside(x, y))
        {
            RotatedFigure = FigList[i];
            RotatedFigure->SetSelected(true);
            break;
        }
    }
    if (RotatedFigure != NULL)
    {
        if (RotatedFigure->getType() == 3)
        {
			RotatedFigure->setisrotated(true);
            pOut->DrawHexagon(RotatedFigure->getCenter(RotatedFigure->getCenter(Point())), RotatedFigure->getgfxinfo(), RotatedFigure->isSelected(), 1);
        }

          bool is= RotatedFigure->Rotation();
		  if (is)
			  pOut->PrintMessage("Figure rotated successfully.");
		  else
			  pOut->PrintMessage("Figure cannot be rotated.");
       
    }
    else
    {
        pOut->PrintMessage("Select exactly one figure to rotate.");
    }
		pManager->UpdateInterface();
		
}
