#include "CCircle.h"
CCircle::CCircle(Point Point1,Point Point2, int r, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = Point1;
	P2 = Point2;
	Center = Point1;
	Radius = r;
}
void CCircle::Draw(Output* pOut) const
{	
	pOut->DrawCircle(P1, P2, FigGfxInfo, Selected);
}


bool CCircle::IsPointInside(int x, int y) const
{
	// Check if the point (x, y) is inside the circle
	int dx = x - Center.x;
	int dy = y - Center.y;
	return (dx * dx + dy * dy <= Radius * Radius);
}

