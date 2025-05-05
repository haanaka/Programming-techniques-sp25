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
    if (pManager->getSelectedFigure() != NULL){
        pOut->PrintMessage("Figure Deleted");
        pManager->deleteselectedfigure();
        pManager->UpdateInterface();
    }
    else{
        pOut->PrintMessage("No figure selected");
    }
}
