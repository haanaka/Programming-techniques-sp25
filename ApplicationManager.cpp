#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"
#include "Actions\ActionCopyOrCut.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddSquAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexaAction.h"
#include "Actions\AddSwapAction.h"
#include "Actions\dELETEAction.h"
#include "Actions\ActionPaste.h"
#include "Actions\SAVE.h"
#include "ActionSwitchToPlayMode.h"
/*#include "../../../source/repos/Programming-techniques-sp25/ApplicationManager.h"*/

#include "Rotate.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	Clipboard = NULL;
	FigCount = 0;
	copyorCut = true;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

int ApplicationManager::GetFigCount() const
{
	return FigCount;
}
//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_SQR:
			pAct = new AddSquAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircAction(this);
			break;
		case DRAW_HEXA:
			pAct = new AddHexaAction(this);
			break;
		case SWAP:
			pAct = new AddSwapAction(this);
			break;
		case SAVE:
			pAct = new SAVEAction(this);
			break;
		case dELETE:
			pAct = new dELETEAction(this);
			break;
		case ROTATE:
			pAct = new Rotate(this);
			break;
		case EXIT:
			///create ExitAction here
			break;
		case PASTE:
			pAct = new ActionPaste(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case COPY:
			copyorCut = true;
			pAct = new ActionCopyOrCut(this,true);
			break;
		case CUT:
			copyorCut = false;
			pAct = new ActionCopyOrCut(this, false);
			break;
		case SWITCH_TO_PLAY:
			pAct = new ActionSwitchToPlayMode(this);
				break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
void ApplicationManager::deleteselectedfigure()
{
	int index = getSelectedFigureIndex();
	if (index != -1) {
		delete SelectedFig;
		for (int i = index; i < FigCount; i++)
			FigList[i] = FigList[i + 1];
		FigCount--;
	}
}
void ApplicationManager::ClearSelectedFigure()
{
	delete SelectedFig;// assuming SelectedFig is the pointer you use
	// (optionally) also clear any multi‐selection array/list here
}
void ApplicationManager::deleteClipboard() {
	int index = GetClipboardIndex();
	if (index != -1) {
		delete Clipboard;
		for (int i = index; i < FigCount; i++)
			FigList[i] = FigList[i + 1];
			FigCount--;
	}
	UpdateInterface();
}

/*void ApplicationManager::Saveall(ofstream& out)
{
	for (int i = 0; i < FigCount; i++)
	{
		FigList[i]->Save(out);
	}
}*/

void ApplicationManager::clearallfigure()
{
		for (int i = 0; i < FigCount; i++) {
			FigList[i] = FigList[i + 1];
			delete FigList[FigCount];
			FigList[FigCount] = NULL;
			FigCount--;
		}
	
}

//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsPointInside(x, y))
			return FigList[i];
	}
	return NULL;
}
CFigure* ApplicationManager::getSelectedFigure() {
	return SelectedFig;
}
bool ApplicationManager::getCopyOrCut() {
	return copyorCut;
}
CFigure* ApplicationManager::GetClipboard() {
	return Clipboard;
}
void ApplicationManager::SetSelectedFigure(CFigure* c) { SelectedFig = c; }
CFigure* ApplicationManager::selectFigure(int x, int y) {

	int numCIR = 0, numRECT = 0, numSQ = 0, numTRI = 0, numHEX = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != nullptr && FigList[i]->IsPointInside(x, y)) {
			switch (FigList[i]->getType()) {
			case 1: numCIR++; break;
			case 2: numTRI++; break;
			case 3: numHEX++; break;
			case 4: numSQ++; break;
			case 5: numRECT++; break;
			}
		}
	}

	if (SelectedFig != nullptr) {
		SelectedFig->SetSelected(false);
		SelectedFig->Draw(pOut);
	}
	if (Clipboard != nullptr) {
		Clipboard->SetSelected(false);
		Clipboard->Draw(pOut);
	}

	for (int i = FigCount - 1; i >= 0; i--) {
		if (FigList[i] != nullptr && FigList[i]->IsPointInside(x, y)) {
			SelectedFig = FigList[i];
			SelectedFig->SetSelected(true);
			SelectedFig->Draw(pOut);

			GetOutput()->PrintMessage(
				"Selected: " + std::to_string(numCIR) + " Circles, " +
				std::to_string(numTRI) + " Triangles, " +
				std::to_string(numHEX) + " Hexagons, " +
				std::to_string(numSQ) + " Squares, " +
				std::to_string(numRECT) + " Rectangles."
			);
			int X, Y; GetInput()->GetPointClicked(X, Y);
			return SelectedFig;
		}
	}

	// If clicked on empty space, clear selection
	if (SelectedFig != nullptr) {
		SelectedFig->SetSelected(false);
		SelectedFig->Draw(pOut);
		SelectedFig = nullptr;
	}
	return nullptr;
}
CFigure* ApplicationManager::getFigureI(int index) const
{
	if (index >= 0 && index < FigCount)
		return FigList[index];
	else
		return nullptr;

}
void ApplicationManager::SetClipboard(CFigure* C) { Clipboard = C; }
CFigure* ApplicationManager::SelectClipboardFigure(int x, int y) {
	// Check if the point (x, y) is inside the selected figure
	for (int i = FigCount-1; i >=0; i--) {
		if (FigList[i]->IsPointInside(x, y)&&FigList[i]!=nullptr)
		{
			Clipboard = FigList[i];
			if (Clipboard != nullptr) {
				Clipboard->SetSelected(false);
				Clipboard->Draw(pOut); //Deselect the previously selected figure
			}
			Clipboard = FigList[i];
			Clipboard->SetSelected(true);
			Clipboard->Draw(pOut);
			return Clipboard;
		}
	}
	if (Clipboard != NULL) {
		Clipboard->SetSelected(false);
		Clipboard->Draw(pOut);
		Clipboard = NULL;
	}
	return NULL;
}
int ApplicationManager::getSelectedFigureIndex() const
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == SelectedFig) {
			return i;
		}
	}
	return -1; // Return -1 if no selected figure is found
}
int ApplicationManager::GetClipboardIndex() const
{
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] == Clipboard) {
			return i;
		}
	}
	return -1; // Return -1 if no selected figure is found
}
// It returns a pointer to the selected figure
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for(int i=0; i<FigCount; i++)
		if (FigList[i] != NULL)
			FigList[i]->Draw(pOut);	
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
