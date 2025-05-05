#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "CSquare.h"
#define r2  1.4142135623731
#include <iostream>
#include <fstream>

CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CSquare::Draw(Output* pOut) const
{
	pOut->Drawsquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsPointInside(int x, int y) const
{
	return(x >= Center.x - 37.5 &&x <= Center.x + 37.5 &&y >= Center.y - 37.5 &&y <= Center.y + 37.5) ;

}
bool CSquare::Rotation()
{
	return false;
}
Point CSquare::getCenter(Point& center) const {
	center.x = Center.x;
	center.y = Center.y;
	return center;
}
void CSquare::Save(ofstream& out)
{
	out << "SQUARE\t" << getID() << "\t" << Center.x << "\t" << Center.y << "\t"
		<< "\t" << endl;

}
void CSquare::Load(ifstream& Infile)
{
	string Drawcolor, Fillcolor;
	Infile >> ID >> Center.x >> Center.y >> Drawcolor >> Fillcolor;
	//FigGfxInfo.DrawClr = getdrawcolor();
	if (Fillcolor == "No fill")
		FigGfxInfo.isFilled = false;
	else
	{
		//FigGfxInfo.FillClr = getdrawcolor();
		FigGfxInfo.isFilled = true;
	}
	Center.x = Center.x;
	Center.y = Center.y;
}
void CSquare::MoveTo(Point destination) {
	Point Center;
	Center.x = this->Center.x;
	Center.y = this->Center.y;
	int dx = destination.x - Center.x;
	int dy = destination.y - Center.y;
	this->Center.x += dx;
	this->Center.y += dy;
}
void CSquare::shiftTo(int x, int y)
{
	Point Center;
	Center.x = this->Center.x;
	Center.y = this->Center.y;
	int dx = x - Center.x;
	int dy = y - Center.y;
	this->Center.x += dx;
	this->Center.y += dy;
}
int CSquare::getType() 
{
	return 4; // 4 for square
}

CFigure* CSquare::Clone() const
{
	return new CSquare(*this);
}
/*color& CSquare::getdrawcolor() const
{
	return FigGfxInfo.DrawClr;
}
color& CSquare::getfillcolor() const
{
	return FigGfxInfo.FillClr;
}*/
GfxInfo CSquare::getgfxinfo()
{
	return FigGfxInfo;
}
bool CSquare::isSelected() const
{
	return Selected;
}