#include"AddTriAction.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{
}
void AddTriAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Triangle: Click at first vertex");

	pIn->GetPointClicked(Vertex1.x, Vertex1.y);
	pOut->PrintMessage("New Triangle: Click at second vertex");

	pIn->GetPointClicked(Vertex2.x, Vertex2.y);
	pOut->PrintMessage("New Triangle: Click at third vertex");
	
	pIn->GetPointClicked(Vertex3.x, Vertex3.y);
	TriGfxInfo.isFilled = false;

	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();

}