
#include "CHexagon.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#define r3 1.7320508075689

CHexagon::CHexagon(Point  P, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	center = P;
}
void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHexagon(center, FigGfxInfo, Selected);
}
double Abs(double x)
{
	return (x < 0) ? -x : x;
}

bool CHexagon::IsPointInside(int x, int y) const
{
    float dx = Abs(x - center.x);
    float dy = Abs(y - center.y);

    if (dx > 100 || dy > 100 * r3 / 2)
        return false;

    if (dx > 50 && dy > (r3 / 2) * (100 - dx))
        return false;

    return true;
}
bool CHexagon::Rotation()
{
    return false;
}