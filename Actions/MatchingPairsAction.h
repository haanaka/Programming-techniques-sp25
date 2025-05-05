#pragma once
#include"Action.h"
#include "..\Figures\CFigure.h"
class MatchingPairsAction : public Action
{
private:
	int score;
	CFigure* FirstFigure;
	CFigure* SecondFigure;
	

public:
	MatchingPairsAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~MatchingPairsAction();
	
	
};

