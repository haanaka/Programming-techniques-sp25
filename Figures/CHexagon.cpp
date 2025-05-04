
#include "CHexagon.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#define r3 1.7320508075689
#include<iostream>

CHexagon::CHexagon(Point  P, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P;
}
void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexagon(Center, FigGfxInfo, Selected);
}
double Abs(double x)
{
	return (x < 0) ? -x : x;
}
bool isinsiderect(Point p1, Point p2, int x, int y) {
	int left = min(p1.x, p2.x);
	int right = max(p1.x, p2.x);
	int top = min(p1.y, p2.y);
	int bottom = max(p1.y, p2.y);

	return (x >= left && x <= right && y >= top && y <= bottom);

}
bool CHexagon::IsPointInside(int x, int y) const
{
	Point hex[6];
	hex[0].x = Center.x + 100;    hex[0].y = Center.y;

	hex[1].x = Center.x + 50;	  hex[1].y = Center.y + 50 * r3;

	hex[2].x = Center.x - 50;     hex[2].y = Center.y + 50 * r3;

	hex[3].x = Center.x - 100;    hex[3].y = Center.y;

	hex[4].x = Center.x - 50;     hex[4].y = Center.y - 50 * r3;

	hex[5].x = Center.x + 50;     hex[5].y = Center.y - 50 * r3;



	int crossings = 0;
	for (int i = 0; i < 6; i++) {
		Point p1 = hex[i];
		Point p2 = hex[(i + 1) % 6];
		if ((y <= p1.y) != (y <= p2.y)) {
			float intersect = p1.x + (y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y);
			if (x <= intersect) crossings++;
		}
	}
	return (crossings % 2 == 1);

}
void CHexagon::Save(ofstream& OutFile)
{
	cout << "HEX" << "  " << "  " << Center.x << "  " << Center.y << "  " << endl;
}
Point CHexagon::getCenter(Point& center) const
{
	center.x = Center.x;
	center.y = Center.y;
    return center;
}
void CHexagon::MoveTo(Point destination)
{
	Point Center;
	Center.x = this->Center.x;
	Center.y = this->Center.y;
	int dx = destination.x - Center.x;
	int dy = destination.y - Center.y;
	this->Center.x += dx;
	this->Center.y += dy;

}
void CHexagon::shiftTo(int x, int y)
{
	Point Center;
	Center.x = this->Center.x;
	Center.y = this->Center.y;
	int dx = x - Center.x;
	int dy = y - Center.y;
	this->Center.x += dx;
	this->Center.y += dy;
}
int CHexagon::getType() 
{
	return 3; // 3 for hexagon
}
bool CHexagon::Rotation()
{
    return false;
}
CFigure* CHexagon::Clone() const
{
	return new CHexagon(*this);
}