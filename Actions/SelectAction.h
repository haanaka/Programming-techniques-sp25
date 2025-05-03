#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"	
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
class SelectAction : public Action
{
	CFigure* SelectedFig; // Pointer to the currently selected figure
public:
	SelectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~SelectAction();
};

