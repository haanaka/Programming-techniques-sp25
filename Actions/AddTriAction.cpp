#include"AddTriAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "../Figures/CTtriangle.h"
AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddTriAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Triangle: Click at first vertex");

	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Triangle: Click at second vertex");

	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third vertex");
	
	pIn->GetPointClicked(P3.x, P3.y);
	TriGfxInfo.isFilled = false;
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();

}
void AddTriAction::Execute()
{
	ReadActionParameters();
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);
	pManager->AddFigure(T);
}
