#include "SAVE.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <iostream>



SAVEAction::SAVEAction(ApplicationManager* pApp) : Action(pApp)
{
}
void SAVEAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Enter filename to save: ");
	n = pIn->GetString(pOut);
	if (n == "")
	{
		n = "default";
		pOut->PrintMessage("Default filename");
		return;
	}
}
string SAVEAction::getcolorname(color c)
{
	if (c == BLACK)
		return "BLACK";
	else if (c == WHITE)
		return "WHITE";
	else if (c == BLUE)
		return "BLUE";
	else if (c == RED)
		return "RED";
	else if (c == YELLOW)
		return "YELLOW";
	else if (c == GREEN)
		return "GREEN";
	else if (c == LIGHTGOLDENRODYELLOW)
		return "LIGHTGOLDENRODYELLOW";
	else if (c == MAGENTA)
		return "MAGENTA";
	else if (c == TURQUOISE)
		return "TURQUOISE";
	return "COLOR";
}
void SAVEAction::Execute()
{
	ReadActionParameters();	
	ofstream file;
	file.open(n + ".txt");
	Output* pOut = pManager->GetOutput();
	file << pManager->GetFigCount() << endl;
	pManager->Saveall(file);
	pOut->PrintMessage("File saved");
	file.close();
}


