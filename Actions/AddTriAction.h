#pragma once
#include"Action.h"
class AddTriAction : public Action
{
private:
	Point Vertex1, Vertex2, Vertex; 
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};