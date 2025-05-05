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

	bool Rotation();
	
	void Save(ofstream& out);
	void Load(ifstream& Infile);

	CFigure* Clone() const override;
	GfxInfo getgfxinfo();
	bool isSelected() const;
	//virtual color& getdrawcolor() const;
	//virtual color& getfillcolor()const ;
};
#endif