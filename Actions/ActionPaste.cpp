#include "ActionPaste.h"
#include "ActionCopyOrCut.h"
#include "deleteaction.h"
#include "SelectAction.h"
#include "AddRectAction.h"
#include "AddTriAction.h"


ActionPaste::ActionPaste(ApplicationManager* pApp) : Action(pApp)
{
}

void ActionPaste::ReadActionParameters()
{
	// Read action parameters if needed
}
void ActionPaste::Execute()
{ 
    // Get references to manager components
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
    pManager->GetOutput()->PrintMessage("Paste completed successfully");
}