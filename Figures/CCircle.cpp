#include "CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include <iostream>

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

float DIFF(Point p1, Point p2);

bool CCircle::IsPointInside(int x, int y) const
{
	// Check if the point (x, y) is inside the circle
	int dx = x - Center.x;
	int dy = y - Center.y;
	float R = DIFF(P1, P2);
	return (dx * dx + dy * dy <= R * R);
}
void CCircle::Save(ofstream& out)
{
	string fillcolor;
	if (FigGfxInfo.isFilled)
		fillcolor = getcolorname(FigGfxInfo.FillClr);
	else
		fillcolor = "no fill";
	out << "CIRC\t" << getID() << "\t" << Center.x << "\t" << Center.y << "\t" 
		<< Radius << "\t" << getcolor() << "\t" << fillcolor<< endl;
}
bool CCircle::Rotation()
{
	return false;
}
color CCircle::getcolor() const
{
	if (FigGfxInfo.isFilled)
	return FigGfxInfo.FillClr;
	return FigGfxInfo.DrawClr;
}
bool CCircle::isfilled() const
{
	return FigGfxInfo.isFilled;
}
string CCircle::getcolorname(color c) const
{
	return CFigure::getcolor(c);;
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

	// Shift the circle's center to the new coordinates
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
CFigure* CCircle::Clone() const
{
	return new CCircle(*this); // Create a new circle with the same properties
}
