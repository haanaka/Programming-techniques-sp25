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
	 void Save(ofstream& OutFile); //Saves the triangle info to a file
	 void Load(ifstream& Infile); //Loads the triangle info from a file

};


