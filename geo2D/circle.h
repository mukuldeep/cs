#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"
#include "line.h"
#include <vector>

class Circle {
public:
    Point center;
    double r;

    Circle(const Point& c, double radius) : center(c), r(radius) {}

    // Line–Circle intersection
    std::vector<Point> intersect(const Line& l) const {
        std::vector<Point> pts;

        double a = l.a, b = l.b, c = l.c;
        double x0 = center.x, y0 = center.y;

        double d = std::fabs(a*x0 + b*y0 + c) / std::sqrt(a*a + b*b);
        if (d > r + EPS) return pts;

        double t = -(a*x0 + b*y0 + c) / (a*a + b*b);
        double x = x0 + a * t;
        double y = y0 + b * t;

        if (nearlyEqual(d, r)) {
            pts.push_back(Point(x, y));
        } else {
            double h = std::sqrt(r*r - d*d);
            double dx = -b / std::sqrt(a*a + b*b);
            double dy =  a / std::sqrt(a*a + b*b);

            pts.push_back(Point(x + dx*h, y + dy*h));
            pts.push_back(Point(x - dx*h, y - dy*h));
        }
        return pts;
    }
};

#endif
