#ifndef INPUT_H
#define INPUT_H

#include "..\DEFS.h"
#include "UI_Info.h" 
#include "..\CMUgraphicsLib\CMUgraphics.h"

class Output;   // forward declaration

class Input		//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Input(window* pW);		//Consturctor
	void GetPointClicked(int& x, int& y) const;

	void CheckFilled(Output* P, GfxInfo& GfxInfo) const;

	void CheckColor(Output* P, GfxInfo& GfxInfo) const;

	//Get coordinate where user clicks
	string GetString(Output* pO) const;	 //Returns a string entered by the user

	ActionType GetUserAction() const; //Read the user click and map to an action

	ActionType SwitchToPlayMode();

	~Input();
};

#endif