#include "CFigure.h"
#include "CTriangle.h"
#include "GUI/Output.h"
#include "GUI/Input.h"
CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Vertex1 = p1;
	Vertex2 = p2;
	Vertex3 = p3;
}
void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTriangle(Vertex1, Vertex2, Vertex3, FigGfxInfo, Selected);
}