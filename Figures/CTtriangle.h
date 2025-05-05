#pragma once
#include "CFigure.h"
class CTriangle :public CFigure
{
private:
	Point P1, P2, P3; //Three points of the triangle
public:
	CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const; //Draws the triangle
	 bool IsPointInside(int x, int y) const; //Checks if a point is inside the triangle
	 void Save(ofstream& out); //Saves the triangle info to a file
	 void Load(ifstream& Infile); //Loads the triangle info from a file
	 Point getCenter(Point& center) const; 
	 void MoveTo(Point destination);
	 void shiftTo(int x, int y);
	 int getType();
	 bool Rotation(); //Function belonging to the rotate class
	 //color& getdrawcolor() const;
	 //color& getfillcolor() const;
	 CFigure* Clone() const override;
	 GfxInfo getgfxinfo();
	 bool isSelected() const;
};


