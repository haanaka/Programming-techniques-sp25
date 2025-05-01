#include "CTriangle.h"
		
CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = P1;
	Vertex2 = P2;
	Vertex3 = P3;
}
void CTriangle::Draw(Output* pOut) const
{
	
	pOut->DrawTriangle(Vertex1, Vertex2, Vertex3, FigGfxInfo, Selected);
}
bool CTriangle::IsPointInside(int x, int y) const
{	float d1 = ((P2.y - P3.y) * (x - P3.x) + (P3.x - P2.x) * (y - P3.y)) /
     ((P2.y - P3.y) * (P1.x - P3.x) + (P3.x - P2.x) * (P1.y - P3.y));
	float d2 = ((P3.y - P1.y) * (x - P3.x) + (P1.x - P3.x) * (y - P3.y)) /
      ((P2.y - P3.y) * (P1.x - P3.x) + (P3.x - P2.x) * (P1.y - P3.y));
	float d3 = 1.0f - d1 - d2;
	return (d1 > 0 && d2 > 0 && d3 > 0);
}