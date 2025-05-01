#include "CHexagon.h"
#define r3 1.7320508075689
double abs(double x)
{
	return (x < 0) ? -x : x;
}


bool CHexagon::IsPointInside(int x, int y) const
{
    float dx = abs(x - center.x);
    float dy = abs(y - center.y);

    if (dx > 100 || dy > 100 * r3 / 2)
        return false;

    if (dx > 50 && dy > (r3 / 2) * (100 - dx))
        return false;

    return true;
}