#include "ActionPaste.h"
#include "ActionCopyOrCut.h"
#include "deleteaction.h"
#include "SelectAction.h"
#include "AddRectAction.h"
#include "AddTriAction.h"
#include "..\ApplicationManager.h"


ActionPaste::ActionPaste(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionPaste::ReadActionParameters()
{
	// Read action parameters if needed
}
void ActionPaste::Execute()
{
    dELETEAction* pAct = NULL;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* pClipboard = pManager->GetClipboard();
	CFigure* pOriginal = pManager->GetClipboard();
    int x, y;
	if (pClipboard == nullptr) {
		pManager->GetOutput()->PrintMessage("Error: Clipboard is empty. Nothing to paste.");
		pManager->GetInput()->GetPointClicked(x, y);  // Dummy click to clear message
		pManager->GetOutput()->ClearStatusBar();
		return;
	}
	pOut->PrintMessage("Click where you want to paste the figure");
	pIn->GetPointClicked(x, y);
    if (pManager->getCopyOrCut()) {
        if (pOriginal == nullptr)
        {
            pOut->PrintMessage("no shape selected,click to return");
            pIn->GetPointClicked(x, y);
            return;
        }
        CFigure* PasteFigure = pOriginal->Clone();
        PasteFigure->shiftTo(x, y);
        PasteFigure->SetSelected(false);
		pClipboard->SetSelected(false);
		pAct = new dELETEAction(pManager);
		pAct->Execute1();
        pManager->AddFigure(PasteFigure);
        pManager->UpdateInterface();
    }
    else
    {
        if (pOriginal == nullptr)
        {
            pOut->PrintMessage("no shape selected,click to return");
            pIn->GetPointClicked(x, y);
            return;
        }


        CFigure* PasteFigure = pOriginal->Clone();
        PasteFigure->shiftTo(x, y);
        PasteFigure->SetSelected(false);
		pClipboard->SetSelected(false); 
        pManager->deleteClipboard();
        pManager->AddFigure(PasteFigure);
        pManager->UpdateInterface();
    }
    pManager->SetClipboard(nullptr);

}
/*  // Get references to manager components
    int x, y;
    // 1. Verify clipboard has content
    if (pManager->GetClipboard() == nullptr) {
        pManager->GetOutput()->PrintMessage("Error: Clipboard is empty. Nothing to paste.");
        pManager->GetInput()->GetPointClicked(x, y);  // Dummy click to clear message
        pManager->GetOutput()->ClearStatusBar();
        return;
    }

    // 2. Get paste location from user
    pManager->GetOutput()->PrintMessage("Click where you want to paste the figure");
    pManager->GetInput()->GetPointClicked(x, y);
    pManager->GetOutput()->ClearStatusBar();

    // 3. Create a deep copy of the figure
    CFigure* pOriginal = pManager->GetClipboard();
    CFigure* pNewFigure = pOriginal->Clone();  
    if (!pNewFigure) {
        pManager->GetOutput()->PrintMessage("Error: Failed to create figure copy");
        return;
    }

    // 4. Position and add the new figure
    pNewFigure->shiftTo(x, y);
    pNewFigure->SetSelected(false);  // Deselect after pasting
    pManager->AddFigure(pNewFigure);

    // 5. Handle cut operation (delete original if this was a cut)
    if (!pManager->getCopyOrCut()) {  // If it was a cut
        int originalIndex = pManager->GetClipboardIndex();
        if (originalIndex != -1) {
            pManager->deleteClipboard();  // Remove original
        }
    }

    // 6. Update display
    pManager->UpdateInterface();
    pManager->GetOutput()->PrintMessage("Paste completed successfully");*/