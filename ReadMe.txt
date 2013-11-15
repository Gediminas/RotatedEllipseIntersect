RotatedEllipseIntersect - 2D rotated ellipse intersection with line

NOTES:
  * implemented using mathematical equations
  * see screenshot1.jpg
  * returns intersection points pt1 & pt2
  * Windows MFC application


src\Intersect.h:

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

  bool IntersectEllipseWithLine(const SEllipse2D &ellipse, const SLine2D &line,
                                SPoint2D &pt1, SPoint2D &pt2,
                                bool &bTouches);


(C) Gediminas Lūžys, 2013
