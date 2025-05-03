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
	int x, y;

	if (pManager->GetClipboard() == NULL) {
		pManager->GetOutput()->PrintMessage("Clipboard is empty. Paste action failed.");
		pManager->GetInput()->GetPointClicked(x, y);
		return;
	}

	pManager->GetOutput()->PrintMessage("Click to paste the figure");
	pManager->GetInput()->GetPointClicked(x, y);

	CFigure* copiedFigure = pManager->GetClipboard();
	copiedFigure->shiftTo(x, y);
	copiedFigure->SetSelected(false);

	pManager->AddFigure(copiedFigure);

	if (!pManager->getCopyOrCut()) {

		int index = pManager->GetClipboardIndex();
		if (index != -1) {
			pManager->deleteselectedfigure();
		}
	}

}