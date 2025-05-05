#include "Input.h"
#include "Output.h"

using namespace std;
void toLowerCase(string& s) {

	// Manual converting each character to lowercase
	// using ASCII values
	for (char& c : s) {
		if (c >= 'A' && c <= 'Z') {

			// Convert uppercase to lowercase
			// by adding 32
			c += 32;
		}
	}
}

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}
void Input::CheckFilled(Output* P, GfxInfo& GfxInfo) const
{
	P->PrintMessage("Please enter if you want to fill the shape with color (true/false): ");
	string filled = GetString(P);
	toLowerCase(filled);
	if ((filled == "true")||( filled=="ture")||(filled =="teru")||(filled=="teur")||(filled =="tture"))
	{
		 GfxInfo.isFilled = true;
		 P->PrintMessage("Please enter the color you want to fill with: ");
		 string color = GetString(P);
		 toLowerCase(color);
		 if (color == "red")
		 {
			 GfxInfo.FillClr = RED;
		 }
		 else if (color == "green")
		 {
			 GfxInfo.FillClr = GREEN;
		 }
		 else if (color == "blue")
		 {
			 GfxInfo.FillClr = BLUE;
		 }
		 else if (color == "yellow")
		 {
			 GfxInfo.FillClr = YELLOW;
		 }
		 else if (color == "orange")
		 {
			 GfxInfo.FillClr = ORANGE;
		 }
		 else if (color == "pink")
		 {
			 GfxInfo.FillClr = PINK;
		 }
		 else if (color == "brown")
		 {
			 GfxInfo.FillClr = BROWN;
		 }
		 else if (color == "cyan")
		 {
			 GfxInfo.FillClr = CYAN;
		 }
		 else if (color == "magenta")
		 {
			 GfxInfo.FillClr = MAGENTA;
		 }
		 else if (color == "purple")
		 {
			 GfxInfo.FillClr = PURPLE;
		 }
		 else if (color == "black")
		 {
			 GfxInfo.FillClr = BLACK;
		 }
		 else if (color == "white")
		 {
			 GfxInfo.FillClr = WHITE;
		 }
		 else
		 {
			 P->PrintMessage("Invalid color, using default color");
			 GfxInfo.FillClr = BLACK;
		 }
	}
	else
	{
		GfxInfo.isFilled = false;
	}
}
void Input::CheckColor(Output* P, GfxInfo& GfxInfo) const
{
	P->PrintMessage("Please enter the color you want to use for sides: ");
	string color = GetString(P);
	toLowerCase(color);
	if (color == "red")
	{
		GfxInfo.DrawClr = RED;
	}
	else if (color == "orange")
	{
		GfxInfo.DrawClr = ORANGE;
	}
	else if (color == "pink")
	{
		GfxInfo.DrawClr = PINK;
	}
	else if (color == "brown")
	{
		GfxInfo.DrawClr = BROWN;
	}
	else if (color == "cyan")
	{
		GfxInfo.DrawClr = CYAN;
	}
	else if (color == "magenta")
	{
		GfxInfo.DrawClr = MAGENTA;
	}
	else if (color == "green")
	{
		GfxInfo.DrawClr = GREEN;
	}
	else if (color == "blue")
	{
		GfxInfo.DrawClr = BLUE;
	}
	else if (color == "yellow")
	{
		GfxInfo.DrawClr = YELLOW;
	}
	else if (color == "purple")
	{
		GfxInfo.DrawClr = PURPLE;
	}
	else if (color == "black")
	{
		GfxInfo.DrawClr = BLACK;
	}
	else if (color == "white")
	{
		GfxInfo.DrawClr = WHITE;
	}
	else
	{
		P->PrintMessage("Invalid color, using default color");
		GfxInfo.DrawClr = BLACK;
	}
}
string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_EXIT: return EXIT;
			case ITM_CIRC: return DRAW_CIRCLE;
			case ITM_SQR: return DRAW_SQR;
			case ITM_TRI: return DRAW_TRI;
			case ITM_HEXA: return DRAW_HEXA;
			case ITM_SELECT: return SELECT;
			case ITM_SWAP: return SWAP;
			case ITM_ROTATE:return ROTATE;
			case ITM_DELETE: return dELETE;
			case ITM_CLEARALL: return CLEAR_ALL;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_REDO:return REDO;
			case ITM_UNDO: return UNDO;
			case ITM_PASTE: return PASTE;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_SWITCH_TO_PLAY:return SWITCH_TO_PLAY;
			default: return EMPTY;  //A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;

		
	}
else if (UI.InterfaceMode == MODE_PLAY)
		//GUI is in PLAY mode
	{
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding action
		if (y >= 0 && y < UI.ToolBarHeight) {
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			switch (ClickedItemOrder) {
			case PLAY_ITM_SAVE: return SAVE;
			case PLAY_ITM_LOAD: return LOAD;
			case PLAY_ITM_SWITCH_TO_DRAW: return SWITCH_TO_DRAW;
			case PLAY_ITM_SWITCH_GAME_MODE: return SWITCH_GAMEMODE;
			case PLAY_ITM_EXIT:return EXIT;
			default: return EMPTY;
			}

		}
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return PLAYING_AREA;
		}
		return SWITCH_TO_PLAY;	//just for now. This should be updated
	}

}
ActionType Input::SwitchToPlayMode() {
	return SWITCH_TO_PLAY
		;
}
/////////////////////////////////

Input::~Input()
{
}