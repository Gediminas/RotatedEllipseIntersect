#pragma once

const double PI = 3.1415926535897932384626433832795;

struct SPoint2D
{
	double x;
	double y;
};

struct SLine2D
{
	SPoint2D pt1;
	SPoint2D pt2;
};

struct SEllipse2D
{
	double   dRadiusX;
	double   dRadiusY;
	double   dAngle;
	SPoint2D ptCenter;
};

bool IntersectEllipseWithLine(const SEllipse2D &ellipse, const SLine2D &line, SPoint2D &pt1, SPoint2D &pt2, bool &bTouches);

void DrawRotatedEllipse(CDC *pDC, const SEllipse2D &ellipse, const int offset_x, const int offset_y);

