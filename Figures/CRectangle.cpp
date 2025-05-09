#include "CRectangle.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include <iostream>
#include <fstream>


CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsPointInside(int x, int y) const
{

        int left = min(Corner1.x, Corner2.x);
        int right = max(Corner1.x, Corner2.x);
        int top = min(Corner1.y, Corner2.y);
        int bottom = max(Corner1.y, Corner2.y);

        return (x >= left && x <= right && y >= top && y <= bottom);
   
}
Point CRectangle::getCenter(Point& center) const {
	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;
	return center;
}
void CRectangle::MoveTo(Point destination) {
	Point Center;
	Center.x = (Corner1.x + Corner2.x) / 2;
	Center.y = (Corner1.y + Corner2.y) / 2;
	int dx = destination.x - Center.x;
	int dy = destination.y - Center.y;
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
}
void CRectangle::shiftTo(int x, int y)
{
	// Shift the rectangle to a new position
	int dx = x - Corner1.x;
	int dy = y - Corner1.y;
	Corner1.x += dx;
	Corner1.y += dy;
	Corner2.x += dx;
	Corner2.y += dy;
}
int CRectangle::getType() {
	return 5; // 5 for rectangle
}
void CRectangle::Save(ofstream& out)
{
	out << "RECT\t" << getID() << "\t" << Corner1.x << "\t" << Corner1.y << "\t" << Corner2.x<<"\t" << Corner2.y << "\t"
		<< "\t" << endl;

}
void CRectangle::Load(ifstream& Infile)
{
	string Drawcolor, Fillcolor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Drawcolor >> Fillcolor;
	//FigGfxInfo.DrawClr = getdrawcolor();
	if (Fillcolor == "No fill")
		FigGfxInfo.isFilled = false;
	else
	{
		//FigGfxInfo.FillClr = getdrawcolor();
		FigGfxInfo.isFilled = true;
	}
}
bool CRectangle::Rotation()
{
	Point M; //point M will be the middle of the selected figure
	M.y = (Corner1.y + Corner2.y) / 2; //since rectangle is symetrical you get the y coordinate of the middle point by dividing the sum of 2 CORNERS that are on the same VERTICAL LINE by 2
	M.x = (Corner1.x + Corner2.x) / 2; //same is done with the x coordinate
	//an easier way to get the coordinates of the middle point was to sum all the coordinates and divided them by them by 4 but i am using the data members corners that my friend already declared in rectangel.h
	int sidelx = Corner2.x - Corner1.x;
	int sidely = Corner2.y - Corner1.y;
	//simple function to get new coordinates for rotated figure
	Corner1.x = (M.x - sidely / 2);
	Corner1.y = (M.y + sidelx / 2);
	Corner2.x = (M.x + sidely / 2);
	Corner2.y = (M.y - sidelx / 2);
	return true;
}
CFigure* CRectangle::Clone() const
{
	return new CRectangle(*this);
}
/*color& CRectangle::getdrawcolor()const {
	return FigGfxInfo.DrawClr;
}
color& CRectangle::getfillcolor()const {
	return  FigGfxInfo.FillClr;
}*/
GfxInfo CRectangle::getgfxinfo() {
	return FigGfxInfo;
}
bool CRectangle::isSelected() const
{
	return Selected;
}