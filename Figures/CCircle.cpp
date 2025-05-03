#include "CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
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
bool CCircle::Rotation()
{
	return false;
}
Point CCircle::getCenter(Point& center) const
{
	center.x = Center.x;
	center.y = Center.y;
	return center;
}
void CCircle::MoveTo(Point destination)
{
	Point Center;
	Center.x = this->Center.x;
	Center.y = this->Center.y;
	int dx = destination.x - Center.x;
	int dy = destination.y - Center.y;
	this->Center.x += dx;
	this->Center.y += dy;
}
void CCircle::shiftTo(int x, int y)
{
	// Shift the circle to a new position
	int dx = x - Center.x;
	int dy = y - Center.y;
	P1.x += dx;
	P1.y += dy;
	P2.x += dx;
	P2.y += dy;
	Center.x += dx;
	Center.y += dy;
}
int CCircle::getType() {
	return 1; // 1 for circle
}