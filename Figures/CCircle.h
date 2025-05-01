#pragma once
#pragma once
#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	int Radius;
public:
	CCircle(Point P1, int r, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsPointInside(int x, int y) const;
};

