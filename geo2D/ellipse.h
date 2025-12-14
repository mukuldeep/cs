#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "point.h"
#include "line.h"
#include <vector>

class Ellipse {
public:
    Point center;
    double a, b; // semi-major, semi-minor

    Ellipse(const Point& c, double _a, double _b)
            : center(c), a(_a), b(_b) {}

    // Line–Ellipse intersection (analytic)
    std::vector<Point> intersect(const Line& l) const {
        std::vector<Point> pts;

        // Substitute line into ellipse equation
        // ax + by + c = 0 → y = (-ax - c)/b

        if (nearlyEqual(l.b, 0)) {
            // vertical line x = const
            double x = -l.c / l.a;
            double t = 1 - ((x-center.x)*(x-center.x))/(a*a);
            if (t < -EPS) return pts;

            double dy = std::sqrt(std::max(0.0, t)) * b;
            pts.push_back(Point(x, center.y + dy));
            if (!nearlyEqual(dy, 0))
                pts.push_back(Point(x, center.y - dy));
            return pts;
        }

        double m = -l.a / l.b;
        double k = -l.c / l.b;

        double A = (1/(a*a)) + (m*m)/(b*b);
        double B = 2*(m*(k-center.y)/(b*b) - center.x/(a*a));
        double C = (center.x*center.x)/(a*a)
                   + ((k-center.y)*(k-center.y))/(b*b) - 1;

        double D = B*B - 4*A*C;
        if (D < -EPS) return pts;

        double sqrtD = std::sqrt(std::max(0.0, D));
        double x1 = (-B + sqrtD) / (2*A);
        double y1 = m*x1 + k;
        pts.push_back(Point(x1, y1));

        if (!nearlyEqual(D, 0)) {
            double x2 = (-B - sqrtD) / (2*A);
            double y2 = m*x2 + k;
            pts.push_back(Point(x2, y2));
        }
        return pts;
    }
};

#endif
