
#pragma once
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point P1;
	Point P2;
	Point Center;
	int Radius;
public:
	CCircle(Point ,Point, int r, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsPointInside(int x, int y) const;
	void Save(ofstream& OutFile);
	void MoveTo(Point destination);
	Point getCenter(Point& center) const;
void Load(ifstream& Infile);
};

