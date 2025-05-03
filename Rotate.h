#pragma once
#include "Actions\Action.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"

//Add Rotate action class
class CFigure; //need to include Cfigure since it is the item the user will rotate

class Rotate : public Action
{
private:
	CFigure* SelectedFig; //pointer to the figure the user intends to rotate
public:
	Rotate(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};
