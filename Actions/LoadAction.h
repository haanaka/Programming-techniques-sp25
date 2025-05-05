#ifndef LOADACTION_H
#define LOADACTION_H
#include "Action.h"


class LoadAction : public Action
{
	string n;
public:
	LoadAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();
};
#endif // !LOADACTION_H

