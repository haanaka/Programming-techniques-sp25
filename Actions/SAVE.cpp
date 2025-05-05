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
	//No parameters to read from the user
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


