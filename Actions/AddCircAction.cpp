#include "AddCircAction.h"
#include "..\Figures\CCircle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp), p1(), p2(),radius()
{
}
void AddCircAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Circle: click to add acenter");
	pIn->GetPointClicked(p1.x, p1.y);
	pOut->PrintMessage("New Circle: click to add radius");
	pIn->GetPointClicked(p2.x, p2.y);
	CircleGfxInfo.isFilled = false;
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	pIn->CheckColor(pOut, CircleGfxInfo);
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	pIn->CheckFilled(pOut, CircleGfxInfo);
	pOut->ClearStatusBar();
}
void AddCircAction::Execute()
{
	ReadActionParameters();
	CCircle* C = new CCircle(p1, p2,radius, CircleGfxInfo);
	pManager->AddFigure(C);
}
