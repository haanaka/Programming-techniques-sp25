#include "AddSquAction.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
AddSquAction::AddSquAction(ApplicationManager* pApp) :Action(pApp), P1()
{
}
void AddSquAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Square: click a Point");
	pIn->GetPointClicked(P1.x, P1.y);
	SquGfxinfo.isFilled = false;
	SquGfxinfo.DrawClr = pOut->getCrntDrawColor();
	pIn->CheckColor(pOut, SquGfxinfo);
	SquGfxinfo.FillClr = pOut->getCrntFillColor();
	pIn->CheckFilled(pOut, SquGfxinfo);
	pOut->ClearStatusBar();
}
void AddSquAction::Execute()
{
	ReadActionParameters();
	CSquare* S = new CSquare(P1, SquGfxinfo);
	pManager->AddFigure(S);
}
