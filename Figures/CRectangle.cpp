#include "CRectangle.h"

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