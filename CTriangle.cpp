
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
Point CTriangle::getCenter(Point& center) const {
	center.x = (P1.x + P2.x + P3.x) / 3;
	center.y = (P1.y + P2.y + P3.y) / 3;
	return center;
}
void CTriangle::MoveTo(Point destination) {
	Point Center;
	Center.x = (P1.x + P2.x + P3.x) / 3;
	Center.y = (P1.y + P2.y + P3.y) / 3;
	int dx = destination.x - Center.x;
	int dy = destination.y - Center.y;
	P1.x += dx;
	P1.y += dy;
	P2.x += dx;
	P2.y += dy;
	P3.x += dx;
	P3.y += dy;
}
void CTriangle::shiftTo(int x, int y) {
	Point Center;
	Center.x = (P1.x + P2.x + P3.x) / 3;
	Center.y = (P1.y + P2.y + P3.y) / 3;
	int dx = x - Center.x;
	int dy = y - Center.y;
	P1.x += dx;
	P1.y += dy;
	P2.x += dx;
	P2.y += dy;
	P3.x += dx;
	P3.y += dy;
}
int CTriangle::getType() {
	return 2;
}