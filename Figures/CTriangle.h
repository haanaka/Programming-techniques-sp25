#include pragma once
#include "CFigure.h"
#include "defs.h"
#include "GUI/UI_Info.h"
#include"GUI/Output.h
#include "GUI/Input.h"
class CTriangle : public CFigure
{
private:
	Point Vertex1;
	Point Vertex2;	
	Point Vertex3;
public:
	CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;	
	
};