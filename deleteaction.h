#ifndef deleteaction_h
#define deleteaction_h
#include "Action.h"

class deleteaction : public Action
{
public:
	deleteaction(ApplicationManager *pApp);

	virtual void ReadActionParameters();

	virtual void Execute();


}

#endif // !delete_h
