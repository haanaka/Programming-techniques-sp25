#include "ApplicationManager.h"
#include "GUI/Output.h"
#include "Figures/CTtriangle.h"
CTriangle::CTriangle(Point Point1, Point Point2, Point Point3, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	P1 = Point1;
	P2 = Point2;
	P3 = Point3;
}
void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTriangle(P1, P2, P3, FigGfxInfo, Selected);
}
float DIFF(Point p1, Point p2) {
	float dx = p1.x - p2.x;
	float dy = p1.y - p2.y;
	return (sqrt(dx*dx+dy*dy));
}
bool CTriangle::IsPointInside(int x, int y) const
{
	Point P;
	P.x = x;
	P.y = y;
	float rc1, rc2, rc3,r12,r23,r31,A,A1,A2,A3;
	rc1 = DIFF(P, P1);
	rc2 = DIFF(P, P2);
	rc3 = DIFF(P, P3);
	r12 = DIFF(P1, P2);
	r23 = DIFF(P2, P3);
	r31 = DIFF(P3, P1);
	A = (r12 + r23 + r31) / 2;
	A1 = (rc1 + rc2 + r12) / 2;
	A2 = (rc2 + rc3 + r23) / 2;
	A3 = (rc3 + rc1 + r31) / 2;
	return(A - (A1 + A2 + A3) < 0.01);
}
Point CTriangle::getCenter(Point& center) const {
	center.x = (P1.x + P2.x + P3.x) / 3;
	center.y = (P1.y + P2.y + P3.y) / 3;
	return center;
}
void CTriangle::MoveTo(Point destination) {
	Point Center;
	Center.x = (P1.x + P2.x + P3.x) / 3;
	Center.y = (P1.y + P2.y + P3.y) / 3;
	int dx = destination.x - Center.x;
	int dy = destination.y - Center.y;
	P1.x += dx;
	P1.y += dy;
	P2.x += dx;
	P2.y += dy;
	P3.x += dx;
	P3.y += dy;
}
void CTriangle::shiftTo(int x, int y) {
	Point Center;
	Center.x = (P1.x + P2.x + P3.x) / 3;
	Center.y = (P1.y + P2.y + P3.y) / 3;
	int dx = x - Center.x;
	int dy = y - Center.y;
	P1.x += dx;
	P1.y += dy;
	P2.x += dx;
	P2.y += dy;
	P3.x += dx;
	P3.y += dy;
}
int CTriangle::getType() {
	return 2;
}
static Point RotatePoint90(const Point& P, const Point& C)
{
	Point R;
	R.x = C.x + (P.y - C.y);
	R.y = C.y - (P.x - C.x);
	return R;
}

bool CTriangle::Rotation()
{
	//  Compute the triangle’s center
	Point center;
	center.x = (P1.x + P2.x + P3.x) / 3;
	center.y = (P1.y + P2.y + P3.y) / 3;

	//  Put the three corners in an array so we can loop
	Point pts[3];
	pts[0] = P1;
	pts[1] = P2;
	pts[2] = P3;

	//For each point: translate to center, rotate 90° CW, translate back
	for (int i = 0; i < 3; i++)
	{
		int dx = pts[i].x - center.x;  // relative x
		int dy = pts[i].y - center.y;  // relative y

		// 90° CW rotation: new dx =  dy, new dy = –dx
		int newDx = dy;
		int newDy = -dx;

		// write back rotated position
		pts[i].x = center.x + newDx;
		pts[i].y = center.y + newDy;
	}

	// Update the triangle’s corners
	P1 = pts[0];
	P2 = pts[1];
	P3 = pts[2];

	return true;  // indicates the shape actually changed
}
CFigure* CTriangle::Clone()
{
	return new CTriangle(*this);
}
