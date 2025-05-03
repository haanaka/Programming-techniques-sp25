#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
class AddSwapAction : public Action
{
private:
	CFigure * FirstFigure;  
	CFigure* SecondFigure;
public:
	AddSwapAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddSwapAction();

};

