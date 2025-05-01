
#include "Figures/CTtriangle.h"
CTriangle::CTriangle(Point Point1, Point Point2, Point Point3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = Point1;
	P2 = Point2;
	P3 = Point3;
}
void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);
}

bool CTriangle::IsPointInside(int x, int y) const
{
	float d1 = ((P2.y - P3.y) * (x - P3.x) + (P3.x - P2.x) * (y - P3.y)) /
		((P2.y - P3.y) * (P1.x - P3.x) + (P3.x - P2.x) * (P1.y - P3.y));
	float d2 = ((P3.y - P1.y) * (x - P3.x) + (P1.x - P3.x) * (y - P3.y)) /
		((P2.y - P3.y) * (P1.x - P3.x) + (P3.x - P2.x) * (P1.y - P3.y));
	float d3 = 1.0f - d1 - d2;
	return (d1 > 0 && d2 > 0 && d3 > 0);
}