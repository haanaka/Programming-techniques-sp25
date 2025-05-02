#include "AddHexaAction.h"
#include "..\Figures\CHexagon.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddHexaAction::AddHexaAction(ApplicationManager* pApp) :Action(pApp), center()
{
}
void AddHexaAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Hexagon: click to add center");
	pIn->GetPointClicked(center.x, center.y);
	HexaGfxInfo.isFilled = false;
	HexaGfxInfo.DrawClr = pOut->getCrntDrawColor();
	pIn->CheckColor(pOut, HexaGfxInfo);
	HexaGfxInfo.FillClr = pOut->getCrntFillColor();
	pIn->CheckFilled(pOut, HexaGfxInfo);
	pOut->ClearStatusBar();
}
void AddHexaAction::Execute()
{
	ReadActionParameters();
	CHexagon* H = new CHexagon(center, HexaGfxInfo);
	pManager->AddFigure(H);
}