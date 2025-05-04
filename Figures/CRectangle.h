#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(int x, int y) const;
	Point getCenter(Point& center) const;
	void MoveTo(Point destination);

	void shiftTo(int x, int y);

	int getType();
	
	void Save(ofstream& OutFile);

	bool Rotation(); //Function belonging to the rotate class
	CFigure* Clone() const;
};
#endif