#pragma once
#ifndef dELETEAction_h
#define dELETEAction_h
#include "Action.h"

class dELETEAction : public Action
{
public:
	dELETEAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


};

#endif 
