#pragma once
#include "CFigure.h"
class CHexagon : public CFigure
{
private:
	Point Center; // Six points of the hexagon
	bool isrotated;
public:
	CHexagon(Point center, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const override; // Draws the hexagon
	bool IsPointInside(int x, int y) const; // Checks if a point is inside the hexagon
	void Save(ofstream& OutFile); // Saves the hexagon info to a file
	void Load(ifstream& Infile); // Loads the hexagon info from a file
	Point getCenter(Point& center) const; 
	void MoveTo(Point destination);
	void shiftTo(int x, int y);
	int getType();
	CFigure* Clone() const override;
	void Rotation(); //Function belonging to the rotate class
	void setisrotated(bool r);


	color getdrawcolor() const;
	color getfillcolor() const;

};

