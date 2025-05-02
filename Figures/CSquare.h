#pragma once
#include "CFigure.h"
class CSquare :
    public CFigure
{
private:
	Point Center; // Top left corner of the square
public:
	CSquare(Point P1, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsPointInside(int x, int y) const;
	void MoveTo(Point destination);
	Point getCenter(Point& center) const;
};


