#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	
	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* BackupList[MaxFigCount]; //Backup list of figures
	int BackupCount; //Count of backup figures	
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	bool isExit;
	CFigure* Clipboard;  //Pointer to copied/cut figure
	bool copyorCut;  //true if the action is copy and false if it is cut

public:
	ApplicationManager();
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	void deleteselectedfigure(); //Deletes the selected figure
	void deleteClipboard();
	void Saveall(ofstream& out ); //Saves all figures to a file

	void clearallfigure(); //Clears all figures
	void Exit();
	bool shouldExit()const;
	/// Deselects any currently selected figure
	void ClearSelectedFigure();

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	CFigure* getSelectedFigure();
	bool getCopyOrCut();
	CFigure* GetClipboard();

	void SwitchToPlayMode();

	void SwitchToDrawMode();

	void SaveCurrentGraph();

	void RestoreSavedGraph();

	void ClearGraph();

	void SetSelectedFigure(CFigure* c);
	CFigure* selectFigure(int x, int y); //Selects a figure given a point inside the figure
	CFigure* getFigureI(int index) const;
	void SetClipboard(CFigure* C);
	CFigure* SelectClipboardFigure(int x, int y);
	int getSelectedFigureIndex() const; //Returns the index of the selected figure in the FigList
	int GetClipboardIndex() const;

	// -- Interface Management Functions



	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	int GetFigCount() const; //Returns the number of figures in the list
};

#endif