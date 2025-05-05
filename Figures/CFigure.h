#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"



//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	bool isrotated = false; //true if the figure is rotated
	GfxInfo FigGfxInfo;	//Figure graphics info
	
	/// Add more parameters if needed.

public:

	CFigure(GfxInfo FigureGfxInfo);

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual CFigure* Clone() const=0; // Clone the figure
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	virtual int getType();	//get the type of the figure
	virtual void shiftTo(int x, int y) = 0; //shift the figure to a new position
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	int getID() const;
	void setID(int id);
	void setisrotated(bool r); //set the figure to be rotated
	virtual GfxInfo getgfxinfo() = 0; //get the figure's graphics info
	virtual bool isSelected() const = 0; //check if the figure is filled
	virtual bool IsPointInside(int x, int y) const=0;
	virtual void MoveTo(Point destination)=0;
	virtual Point getCenter(Point& center) const = 0; 
	virtual bool Rotation() = 0;//Function belonging to the rotate class
	virtual string getcolor(color c)const;
	virtual color getstringcolor(string c)const;
	//check if a point is inside the figure
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

#endif