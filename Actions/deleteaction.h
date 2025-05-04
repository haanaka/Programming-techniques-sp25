#pragma once
#ifndef dELETEAction_h
#define dELETEAction_h
#include "Action.h"

class dELETEAction : public Action
{
public:
	dELETEAction(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();


};

#endif 
