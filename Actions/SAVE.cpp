#include "SAVE.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

SAVEAction::SAVEAction(ApplicationManager* pApp) : Action(pApp)
{
}
void SAVEAction::ReadActionParameters()
{
	//No parameters to read from the user
}
void SAVEAction::Execute()
{
	//Get a Pointer to the Output Interfaces
}
string SAVEAction:: getcolorname(color c) {
		if (c == RED) return "red";
		if (c == GREEN) return "green";
		if (c == BLUE) return "blue";
		if (c == YELLOW) return "yellow";
		if (c == ORANGE) return "orange";
		if (c == PINK) return "pink";
		if(c == BROWN) return "brown";
		if (c == CYAN) return "cyan";
		if (c == MAGENTA) return "magenta";
		if (c == BLACK) return "black";
		if (c == WHITE) return "white";
		return "unknown";
}