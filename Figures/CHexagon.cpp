
#include "CHexagon.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#define r3 1.7320508075689

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

bool CHexagon::IsPointInside(int x, int y) const
{
    float dx = Abs(x - Center.x);
    float dy = Abs(y - Center.y);

    if (dx > 100 || dy > 100 * r3 / 2)
        return false;

    if (dx > 50 && dy > (r3 / 2) * (100 - dx))
        return false;

    return true;
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