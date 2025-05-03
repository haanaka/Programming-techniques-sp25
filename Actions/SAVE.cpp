#include "SAVE.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <fstream>

SAVEAction::SAVEAction(ApplicationManager* pApp) : Action(pApp)
{
}

string getcolorname(color c) {
	switch (c) {
	case RED:
		return "RED";
	case GREEN:
		return "GREEN";
	case BLUE:
		return "BLUE";
	case YELLOW:
		return "YELLOW";
	case BLACK:
		return "BLACK";
	case WHITE:
		return "WHITE";
	default:
		return "UNKNOWN";
	}
}`