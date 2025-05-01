#include "CCircle.h"



bool CCircle::IsPointInside(int x, int y) const
{
	// Check if the point (x, y) is inside the circle
	int dx = x - Center.x;
	int dy = y - Center.y;
	return (dx * dx + dy * dy <= Radius * Radius);
}