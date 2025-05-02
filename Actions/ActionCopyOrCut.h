#pragma once
#include "Action.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"
#include "..\GUI\Input.h"

	
class ActionCopyOrCut :public Action
{
private:
	CFigure* Clipboard;  //Pointer to copied figure
	GfxInfo FigGfxInfo; //Figure graphics info
	bool copyorcut; //true for copy, false for cut
public:
	ActionCopyOrCut(ApplicationManager* pApp,bool CopyOrCut);

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
	void setcopyorcut(bool copyorcut) {
		this->copyorcut = copyorcut;
	}
};

