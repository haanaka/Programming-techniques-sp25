#pragma once
#include "CFigure.h"
class CSquare : public CFigure
{
private:
	Point Center; // Top left corner of the square
public:
	CSquare(Point P1, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool IsPointInside(int x, int y) const;
	void MoveTo(Point destination);
	void shiftTo(int x, int y);
	int getType();
	Point getCenter(Point& center) const;
	void Save(ofstream& out);
	void Load(ifstream& Infile);
	bool Rotation(); //Function belonging to the rotate class
	CFigure* Clone() const override;
	//color& getdrawcolor() const;
	//color& getfillcolor() const;
};


