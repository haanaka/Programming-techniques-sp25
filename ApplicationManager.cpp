#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"
#include "Actions\ActionCopyOrCut.h"
#include "Actions\AddTriAction.h"
#include "Actions\deleteaction.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	SelectedFig = NULL;
	Clipboard = NULL;
	FigCount = 0;
		
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

		case EXIT:
			///create ExitAction here
			
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case COPY:
			pAct = new ActionCopyOrCut(this,true);
			break;
		case CUT:
			pAct = new ActionCopyOrCut(this, false);
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
		SelectedFig = NULL; 
		for (int i = index; i < FigCount; i++) {
			FigList[i] = FigList[i + 1];
			delete FigList[FigCount];
			FigList[FigCount] = NULL;
			FigCount--;

		}
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
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsPointInside(x, y))
			return FigList[i];
	}

	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
CFigure* ApplicationManager::getSelectedFigure() {
	return SelectedFig;
}
void ApplicationManager::SetSelectedFigure(CFigure* c) { SelectedFig = c; }
CFigure* ApplicationManager::selectFigure(int x, int y) {
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsPointInside(x, y)) {
			if (SelectedFig != NULL) {
				SelectedFig->SetSelected(false);
				SelectedFig->Draw(pOut); //Deselect the previously selected figure
			}
			if (Clipboard != NULL) {
				Clipboard->SetSelected(false);
				Clipboard->Draw(pOut); //Deselect the previously selected figure
			}
			SelectedFig = FigList[i];
			SelectedFig->SetSelected(true);
			SelectedFig->Draw(pOut);
			return SelectedFig;
		}
	}
	if (SelectedFig != NULL) {
		SelectedFig->SetSelected(false);
		SelectedFig->Draw(pOut); 
		SelectedFig = NULL;
	}
	return NULL;
}
CFigure* ApplicationManager::SelectClipboardFigure(int x, int y) {
	// Check if the point (x, y) is inside the selected figure
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i]->IsPointInside(x, y)) {
			if (Clipboard != NULL) {
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
}
// It returns a pointer to the selected figure
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
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
