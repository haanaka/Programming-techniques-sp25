#ifndef deleteaction_h
#define deleteaction_h
#include "Action.h"

class deleteaction : public Action
{
public:
	deleteaction(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();


};

#endif // !delete_h
