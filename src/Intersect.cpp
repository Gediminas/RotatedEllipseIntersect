#include "StdAfx.h"
#include "Intersect.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

const double sqeps = 0.00000001;

inline bool eqx(double x, double y) 
{
	return (x < y) ? (y - x < sqeps) : (x - y < sqeps);
}

inline bool eq0(double x) 
{
	return (x < sqeps) && (x > -sqeps);
}

inline bool less(double x, double y)
{
	return (x < y && !eqx(x, y));
}

inline bool CalcDiscriminant(double a, double b, double c, double &d)
{
    const double D = b*b - 4*a*c;

	if ( less(D, 0.0) ) // discriminant checking
	{
		return false;
	}

	d = eq0(D) ? 0.0 : sqrt(D);

    return true;
}

bool IntersectEllipseWithLine(const SEllipse2D &ellipse, const SLine2D &line, SPoint2D &pt1, SPoint2D &pt2, bool &bTouches)
{
	const double h = ellipse.dRadiusX;
	const double v = ellipse.dRadiusY;

	if ( !::less(0.0, h) || !::less(0.0, v))
	{
		return false; // incorrect ellipse formula
	}

	const double A = -(line.pt2.y - line.pt1.y);
	const double B = line.pt2.x - line.pt1.x;
	const double H = - (A * line.pt1.x + B * line.pt1.y);

	if (eq0(A) && eq0(B))
	{
		return false;
	}

	bTouches = false;

	const double dAngleRad = PI - ellipse.dAngle * PI / 180;

	const double E  = ellipse.ptCenter.x;
	const double F  = ellipse.ptCenter.y;
	const double C  = cos(dAngleRad);
	const double S  = sin(dAngleRad);

	const double CC = C*C;
	const double SS = S*S;
	const double CS = C*S;
	const double hh = h*h;
	const double vv = v*v;

	//const bool bLineVert = fabs(A) > fabs(B);
	const bool bLineVert = !eq0(A);

	double d = 0.0;

	if (bLineVert)
	{
		const double m  = -B/A;
		const double b1 = -H/A;
		const double b2 = b1 + (m*F - E);

		const double mm = m*m;

		const double a = vv * (mm*CC + 2*m*CS + SS) + hh * (CC - 2*m*CS + mm*SS);
		const double b = 2*vv*b2 * (CS + m*CC) + 2*hh*b2 * (m*SS - CS);
		const double c = b2*b2 * (vv*CC + hh*SS) - hh*vv;

        if ( !::CalcDiscriminant(a, b, c, d) )
        {
            return false;
        }

		pt1.y = ((-b - d) / (2*a)) + F;
		pt2.y = ((-b + d) / (2*a)) + F;

		pt1.x = m * pt1.y + b1;
		pt2.x = m * pt2.y + b1;
	}
	else
	{
		const double m  = -A/B;
		const double b1 = -H/B;
		const double b2 = b1 + (m*E - F);

		const double mm = m*m;

		const double a = vv * (CC + 2*m*CS + mm*SS) + hh * (mm*CC - 2*m*CS + SS);
		const double b = 2*vv*b2 * (CS + m*SS) + 2*hh*b2 * (m*CC - CS);
		const double c = b2*b2 * (vv*SS + hh*CC) - hh*vv;

		double d = 0.;
        if ( !::CalcDiscriminant(a, b, c, d) )
        {
            return false;
        }

		pt1.x = ((-b - d) / 2*a) + E;
		pt2.x = ((-b + d) / 2*a) + E;

		pt1.y = m * pt1.x + b1;
		pt2.y = m * pt2.x + b1;
	}

	bTouches = eq0(d);
	return true;
}


inline void CalcRotatedEllipsePoint(double x0, double y0, 
								    double dRadiusX, double dRadiusY, 
							        double dEllipseAngleRad, double dSweepAngleRad, 
								    double &x, double &y)
{
	const double x1 = dRadiusX*cos(dSweepAngleRad)+x0;
	const double y1 = dRadiusY*sin(dSweepAngleRad)+y0;

	x  = (x1-x0)*cos(dEllipseAngleRad) - (y1-y0)*sin(dEllipseAngleRad) + x0;
	y  = (y1-y0)*cos(dEllipseAngleRad) + (x1-x0)*sin(dEllipseAngleRad) + y0;
}

void DrawRotatedEllipse(CDC *pDC, const SEllipse2D &ellipse, const int offset_x, const int offset_y)
{
	const double dAngleRad = PI - ellipse.dAngle * PI / 180;

	double x, y;
	CalcRotatedEllipsePoint(ellipse.ptCenter.x, ellipse.ptCenter.y, ellipse.dRadiusX, ellipse.dRadiusY, dAngleRad, 0, x, y);
	pDC->MoveTo(offset_x+(int)x, offset_y+(int)y);

	for (double dRad = 0; dRad < 2*PI; dRad += 0.005)
	{
		CalcRotatedEllipsePoint(ellipse.ptCenter.x, ellipse.ptCenter.y, ellipse.dRadiusX, ellipse.dRadiusY, dAngleRad, dRad, x, y);
		pDC->LineTo(offset_x+(int)x, offset_y+(int)y);
	}

	CalcRotatedEllipsePoint(ellipse.ptCenter.x, ellipse.ptCenter.y, ellipse.dRadiusX, ellipse.dRadiusY, dAngleRad, 0, x, y);
	pDC->LineTo(offset_x+(int)x, offset_y+(int)y);
}